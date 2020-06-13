#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	���鵥Ԫ�ı߳�

//	���캯��
Block::Block(int x1, int y1, int x2, int y2) {
	map_x = x1;
	map_y = y1;
	view_x = x2;
	view_y = y2;
}

//	��ʼ����ͼ
void Block::InitMap() {
	memset(map, 0, sizeof(map));
	Refresh();
	SetViewBlock();
	NewBlock();
}

//	����Ԥ������
void Block::SetViewBlock() {

	//	�������
	view_type = rand() % 7;

	//	�����״
	memset(view_shape, 0, sizeof(view_shape));

	switch (view_type) {
	case 0://	O��
		view_shape[1][1] = view_shape[1][2] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = BLUE;
		break;
	case 1://	I��
		view_shape[0][1] = view_shape[1][1] = view_shape[2][1] = view_shape[3][1] = 1;
		view_color = RED;
		break;
	case 2://	S��
		view_shape[1][1] = view_shape[1][2] = view_shape[2][0] = view_shape[2][1] = 1;
		view_color = GREEN;
		break;
	case 3://	Z��
		view_shape[1][0] = view_shape[1][1] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = CYAN;
		break;
	case 4://	L��
		view_shape[0][1] = view_shape[1][1] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = MAGENTA;
		break;
	case 5://	J��
		view_shape[0][2] = view_shape[1][2] = view_shape[2][1] = view_shape[2][2] = 1;
		view_color = YELLOW;
		break;
	case 6://	T��
		view_shape[1][0] = view_shape[1][1] = view_shape[1][2] = view_shape[2][1] = 1;
		view_color = BROWN;
		break;
	}
}

//	����
void Block::NewBlock() {

	//	��ʼ������������
	row = 0;
	column = 3;

	//	��ֵΪԤ������
	dynamic_type = view_type;
	memcpy(dynamic_shape, view_shape, sizeof(view_shape));
	dynamic_color = view_color;

	SetViewBlock();

	//	���Ԥ����
	clearrectangle(view_x + 1, view_y + 1,
		view_x + UNIT * 4 - 1, view_y + UNIT * 4 - 1);

	//	����Ԥ������
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

//	����
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

//	����
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

//	�̶�
int Block::FixBlock() {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				map[row + i][column + j].state = 1;	//	��̬�����䶨����ǵ�ͼ
				map[row + i][column + j].color = dynamic_color;
			}
		}
	}
	for (int i = row; i < row + 4; i++) {	//	�������
		if (IsFullLine(i)) {	//	����
			DeleteLine(i);
			count++;
		}
	}
	return count;
}

//	ˢ��
void Block::Refresh() {

	//	�����Ϸ��
	clearrectangle(map_x + 1, map_y + UNIT * 4 + 1,
		map_x + UNIT * 10 - 1, map_y + UNIT * 26 - 1);

	//	�ػ淽��
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

//	����
void Block::MoveDown() {
	ClearBlock();
	Sleep(250);			//	��ʱ 250 ����
	row++;
	DrawBlock();
	FlushBatchDraw();	//	����
}

//	���� 
void Block::MoveLeft() {
	ClearBlock();
	column--;
	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	����
	}
	else {
		MoveRight();
	}
}

//	���� 
void Block::MoveRight() {
	ClearBlock();
	column++;
	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	����
	}
	else {
		MoveLeft();
	}
}

//	��ת
void Block::Rotate() {
	ClearBlock();

	//	4*4 ����˳ʱ����ת 90��
	int temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = dynamic_shape[3 - j][i];
		}
	}
	memcpy(dynamic_shape, temp, sizeof(temp));

	if (!IsAgain()) {
		DrawBlock();
		FlushBatchDraw();	//	����
	}
	else {
		//	4*4 ������ʱ����ת 90��
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = dynamic_shape[j][3 - i];
			}
		}
		memcpy(dynamic_shape, temp, sizeof(temp));
	}
}

//	����
void Block::Sink() {
	while (!IsBottom()) {	//	������
		ClearBlock();
		row++;
		DrawBlock();
		FlushBatchDraw();	//	����
	}
}

//	����
void Block::DeleteLine(int r) {
	for (int i = r; i > 3; i--) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
	Refresh();
}

//	���� 
void Block::AddLine() {
	for (int i = 3; i < 25; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = map[i + 1][j];
		}
	}

	//	�������з���
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

//	���׼��
bool Block::IsBottom() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				if (map[row + i + 1][column + j].state == 1) {	//	���䶨�����ص�
					return true;
				}
				if (row + i + 1 == 26) {	//	�ײ�����
					return true;
				}
			}
		}
	}
	return false;
}

//	��ײ���
bool Block::IsAgain() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dynamic_shape[i][j] == 1) {
				if (map[row + i][column + j].state == 1) {	//	���䶨�����ص�
					return true;
				}
				if (column + j == 10 || column + j == -1) {	//	���ҳ���
					return true;
				}
			}
		}
	}
	return false;
}

//	�������
bool Block::IsFullLine(int r) {
	for (int j = 0; j < 10; j++) {
		if (map[r][j].state != 1) {	//	�з��䶨����
			return false;
		}
	}
	return true;
}

//	�����ж�
bool Block::IsGameOver() {
	for (int j = 0; j < 10; j++) {
		if (map[3][j].state == 1) {	//	���������䶨����
			return true;
		}
	}
	return false;
}