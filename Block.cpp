#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	方块单元的边长

//	构造函数
Block::Block(int x1, int y1, int x2, int y2) {
	map_x = x1;
	map_y = y1;
	view_x = x2;
	view_y = y2;
}

//	初始化地图
void Block::InitMap() {
	memset(map, 0, sizeof(map));
	Refresh();
	SetViewBlock();
	NewBlock();
}

//	设置预览方块
void Block::SetViewBlock() {

	//	随机类型
	view_type = rand() % 7;

	//	清空形状
	memset(view_shape, 0, sizeof(view_shape));

	switch (view_type) {
	case 0://	O型
		view_shape[1][1] = view_shape[1][2] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = BLUE;
		break;
	case 1://	I型
		view_shape[0][1] = view_shape[1][1] = view_shape[2][1] = view_shape[3][1] = 1;
		view_color = RED;
		break;
	case 2://	S型
		view_shape[1][1] = view_shape[1][2] = view_shape[2][0] = view_shape[2][1] = 1;
		view_color = GREEN;
		break;
	case 3://	Z型
		view_shape[1][0] = view_shape[1][1] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = CYAN;
		break;
	case 4://	L型
		view_shape[0][1] = view_shape[1][1] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = MAGENTA;
		break;
	case 5://	J型
		view_shape[0][2] = view_shape[1][2] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = YELLOW;
		break;
	case 6://	T型
		view_shape[1][0] = view_shape[1][1] = view_shape[1][2] = view_shape[2][1] = 1;
		view_color = BROWN;
		break;
	}
}

//	生成
void Block::NewBlock() {

	//	初始化基础点坐标
	row = 0;
	column = 3;

	//	赋值为预览方块
	dynamic_type = view_type;
	memcpy(dynamic_shape, view_shape, sizeof(view_shape));
	dynamic_color = view_color;

	SetViewBlock();

	//	清空预览框
	clearrectangle(view_x + 1, view_y + 1,
		view_x + UNIT * 4 - 1, view_y + UNIT * 4 - 1);

	//	绘制预览方块
	setfillcolor(view_color);
	setlinecolor(WHITE);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (view_shape[i][j] == 1) {
				fillrectangle(view_x + UNIT * j + 1, view_y + UNIT * i + 1,
					view_x + UNIT * (j + 1) - 1, view_y + UNIT * (i + 1) - 1);
			}
		}
	}
}

//	绘制
void Block::DrawBlock() {
	setfillcolor(dynamic_color);
	setlinecolor(WHITE);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1 && row + i >= 4) {
				fillrectangle(map_x + UNIT * (column + j) + 1, map_y + UNIT * (row + i) + 1,
					map_x + UNIT * (column + j + 1) - 1, map_y + UNIT * (row + i + 1) - 1);
			}
		}
	}
}

//	擦除
void Block::ClearBlock() {
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1 && row + i >= 4) {
				fillrectangle(map_x + UNIT * (column + j) + 1, map_y + UNIT * (row + i) + 1,
					map_x + UNIT * (column + j + 1) - 1, map_y + UNIT * (row + i + 1) - 1);
			}
		}
	}
}

//	固定
int Block::FixBlock() {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				map[row + i][column + j].state = 1;	//	动态方块落定，标记地图
				map[row + i][column + j].color = dynamic_color;
			}
		}
	}
	for (int i = row; i < row + 4; i++) {	//	检测四行
		if (IsFullLine(i)) {	//	层满
			DeleteLine(i);
			count++;
		}
	}
	return count;
}

//	刷新
void Block::Refresh() {

	//	清空游戏池
	clearrectangle(map_x + 1, map_y + UNIT * 4 + 1,
		map_x + UNIT * 10 - 1, map_y + UNIT * 26 - 1);

	//	重绘方块
	setlinecolor(WHITE);
	for (int i = 4; i < 26; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j].state == 1) {
				setfillcolor(map[i][j].color);
				fillrectangle(map_x + UNIT * j + 1, map_y + UNIT * i + 1,
					map_x + UNIT * (j + 1) - 1, map_y + UNIT * (i + 1) - 1);
			}
		}
	}
}

//	下落
void Block::MoveDown() {
	ClearBlock();
	Sleep(250);			//	延时 250 毫秒
	row++;
	DrawBlock();
	FlushBatchDraw();	//	绘制
}

//	左移 
void Block::MoveLeft() {
	ClearBlock();
	column--;
	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	绘制
	}
	else {
		MoveRight();
	}
}

//	右移 
void Block::MoveRight() {
	ClearBlock();
	column++;
	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	绘制
	}
	else {
		MoveLeft();
	}
}

//	旋转
void Block::Rotate() {
	ClearBlock();

	//	4*4 矩阵顺时针旋转 90°
	int temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = dynamic_shape[3 - j][i];
		}
	}
	memcpy(dynamic_shape, temp, sizeof(temp));

	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	绘制
	}
	else {
		//	4*4 矩阵逆时针旋转 90°
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = dynamic_shape[j][3 - i];
			}
		}
		memcpy(dynamic_shape, temp, sizeof(temp));
	}
}

//	沉底
void Block::Sink() {
	while (!IsBottom()) {	//	不触底
		ClearBlock();
		row++;
		DrawBlock();
		FlushBatchDraw();	//	绘制
	}
}

//	消行
void Block::DeleteLine(int r) {
	for (int i = r; i > 3; i--) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
	Refresh();
}

//	增行 
void Block::AddLine() {
	for (int i = 3; i < 25; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = map[i + 1][j];
		}
	}

	//	绘制增行方块
	setfillcolor(DARKGRAY);
	setlinecolor(WHITE);
	for (int j = 0; j < 10; j++) {
		map[25][j].state = rand() % 2;
		if (map[25][j].state == 1) {
			map[25][j].color = DARKGRAY;
			fillrectangle(map_x + UNIT * j + 1, map_y + UNIT * 25 + 1,
				map_x + UNIT * (j + 1) - 1, map_y + UNIT * 26 - 1);
		}
	}

	Refresh();
}

//	触底检测
bool Block::IsBottom() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				if (map[row + i + 1][column + j].state == 1) {	//	与落定方块重叠
					return true;
				}
				if (row + i + 1 == 26) {	//	底部出界
					return true;
				}
			}
		}
	}
	return false;
}

//	碰撞检测
bool Block::IsAgain() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				if (map[row + i][column + j].state == 1) {	//	与落定方块重叠
					return true;
				}
				if (column + j == 10 || column + j == -1) {	//	左右出界
					return true;
				}
			}
		}
	}
	return false;
}

//	层满检测
bool Block::IsFullLine(int r) {
	for (int j = 0; j < 10; j++) {
		if (map[r][j].state != 1) {	//	有非落定方块
			return false;
		}
	}
	return true;
}

//	结束判定
bool Block::IsGameOver() {
	for (int j = 0; j < 10; j++) {
		if (map[3][j].state == 1) {	//	第四行有落定方块
			return true;
		}
	}
	return false;
}