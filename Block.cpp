#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

#define	UNIT 20	//	ÿ�����鵥Ԫ�ı߳�

int MapA[26][10];
int MapB[26][10];	//	��Ϸ��

//	������״
void Block::SetShape() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			shape[i][j] = 0;
		}
	}
	switch (type) {
	case 0://	O��
		shape[1][1] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
		color = BLUE;
		break;
	case 1://	I��
		shape[0][1] = shape[1][1] = shape[2][1] = shape[3][1] = 1;
		color = RED;
		break;
	case 2://	S��
		shape[1][1] = shape[1][2] = shape[2][0] = shape[2][1] = 1;
		color = GREEN;
		break;
	case 3://	Z��
		shape[1][0] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
		color = CYAN;
		break;
	case 4://	L��
		shape[0][1] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
		color = MAGENTA;
		break;
	case 5://	J��
		shape[0][2] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
		color = YELLOW;
		break;
	case 6://	T��
		shape[1][0] = shape[1][1] = shape[1][2] = shape[2][1] = 1;
		color = BROWN;
		break;
	}
}

//	�����·���
void Block::NewBlock() {
	type = rand() % 7;
	SetShape();
	column = 0;
	row = 3;
	DrawBlock();
}

//	���Ʒ���
void Block::DrawBlock() {

	//	��������ԭ�� ��Ϸ��A
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

	//	��������ԭ�� ��Ϸ��B
	setorigin(UNIT * 30, UNIT * 5);
}

//	��������
void Block::FixBlock() {

	Sleep(100);
	//	��������ԭ�� ��Ϸ��A
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

//	�Զ����� 
void Block::Drop() {

}

//	��ײ���
bool Block::IsAgain() {
	return 1;
}

//	�ƶ� 
void Block::Move() {

}

//	��ת
void Block::Rotate() {
	int temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = shape[3 - j][i];
		}
	}
	if (1) {//	������ ������ת

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

//	ֱ���³�
void Block::Sink() {

}

//	�����ж� 
bool Block::Judge() {
	return 1;
}

//	����
void Block::Eliminate() {

}

//	���� 
void Block::Add() {

}

//	ʤ���ж�
bool Block::IsGameOver() {
	return 1;
}