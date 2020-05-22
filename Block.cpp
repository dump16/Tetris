#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

#define	UNIT 20	//	每个方块单元的边长

int MapA[26][10];
int MapB[26][10];	//	游戏池

//	设置形状
void Block::SetShape() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			shape[i][j] = 0;
		}
	}
	switch (type) {
	case 0://	O型
		shape[1][1] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
		color = BLUE;
		break;
	case 1://	I型
		shape[0][1] = shape[1][1] = shape[2][1] = shape[3][1] = 1;
		color = RED;
		break;
	case 2://	S型
		shape[1][1] = shape[1][2] = shape[2][0] = shape[2][1] = 1;
		color = GREEN;
		break;
	case 3://	Z型
		shape[1][0] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
		color = CYAN;
		break;
	case 4://	L型
		shape[0][1] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
		color = MAGENTA;
		break;
	case 5://	J型
		shape[0][2] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
		color = YELLOW;
		break;
	case 6://	T型
		shape[1][0] = shape[1][1] = shape[1][2] = shape[2][1] = 1;
		color = BROWN;
		break;
	}
}

//	生成新方块
void Block::NewBlock() {
	type = rand() % 7;
	SetShape();
	column = 0;
	row = 3;
	DrawBlock();
}

//	绘制方块
void Block::DrawBlock() {

	//	设置坐标原点 游戏区A
	setorigin(UNIT * 10, UNIT * 5);

	for (int i=0;i<4; i++) {
		for (int j = 0; j <4; j++) {
			if (shape[i][j] == 1) {
				setfillcolor(color);
				fillrectangle(UNIT * (row + j), UNIT * (column + i), UNIT * (row + j +1), UNIT * (column + i +1));
				MapA[column+i][row+j] == 0;
			}
		}
	}
	FixBlock();

	//	设置坐标原点 游戏区B
	setorigin(UNIT * 30, UNIT * 5);
}

//	擦除方块
void Block::FixBlock() {

	Sleep(100);
	//	设置坐标原点 游戏区A
	setorigin(UNIT * 10, UNIT * 5);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (shape[i][j] == 1) {
				setfillcolor(BLACK);
				fillrectangle(UNIT * (row + j), UNIT * (column + i), UNIT * (row + j + 1), UNIT * (column + i + 1));
				setlinecolor(BLACK);
				rectangle(UNIT * (row + j), UNIT * (column + i), UNIT * (row + j + 1), UNIT * (column + i + 1));
			}
		}
	}
	column++;
	DrawBlock();
}

//	自动下落 
void Block::Drop() {

}

//	碰撞检测
bool Block::IsAgain() {
	return 1;
}

//	移动 
void Block::Move() {

}

//	旋转
void Block::Rotate() {
	int temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = shape[3 - j][i];
		}
	}
	if (1) {//	不碰壁 可以旋转

	}
	else {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			shape[i][j] = temp[i][j];
		}
	}
}

//	直接下沉
void Block::Sink() {

}

//	层满判定 
bool Block::Judge() {
	return 1;
}

//	消行
void Block::Eliminate() {

}

//	增行 
void Block::Add() {

}

//	胜负判定
bool Block::IsGameOver() {
	return 1;
}