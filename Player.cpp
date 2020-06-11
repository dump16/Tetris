#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>
#include<thread>
using namespace std;

#define	UNIT 20		//	���鵥Ԫ�ı߳�

Player::Player(){
	block_a = Block(UNIT * 10, UNIT * 1, UNIT * 4, UNIT * 5);
	block_b = Block(UNIT * 30, UNIT * 1, UNIT * 42, UNIT * 5);
}

//	�����������
void Player::HandleInput() {

	//while (_kbhit()) {	//	�а���
		switch (_getch()) {	//	��ȡ����

		//	Player A ������Ӧ
		case 'W':
		case 'w':	block_a.Rotate();		break;
		case 'A':
		case 'a':	block_a.MoveLeft();		break;
		case 'S':
		case 's':	block_a.Sink();			break;
		case 'D':
		case 'd':	block_a.MoveRight();	break;

			//	Player B ������Ӧ
		case 0:
		case 0xE0:
			switch (_getch()) {
			case 72:	block_b.Rotate();		break;	//	��
			case 75:	block_b.MoveLeft();		break;	//	��
			case 80:	block_b.Sink();			break;	//	��
			case 77:	block_b.MoveRight();	break;	//	��
			}

		}
	//}

}

//	��� A
void Player::player_a() {
	block_a.NewBlock();
	block_b.NewBlock();
	BeginBatchDraw();	//	��ʼ������ͼ
	while ((!block_a.IsGameOver())&&( !block_b.IsGameOver())) {	//��Ϸδ����
		while (1) {//	������
			if (_kbhit()) {	//	�а���
				HandleInput();
			}
			else if (block_a.IsBottom()) {
				block_a.FixBlock();
				for (int i = 0; i < block_a.FixBlock(); i++) {
					block_b.AddLine();
				}
				block_a.NewBlock();
				break;
			}
			else if (block_b.IsBottom()) {
				block_b.FixBlock();
				for (int i = 0; i < block_b.FixBlock(); i++) {
					block_a.AddLine();
				}
				block_b.NewBlock();
				break;
			}
			else {
				block_a.MoveDown();	//	����
				block_b.MoveDown();
			}
		}
	}
	EndBatchDraw();	//	����������ͼ

}

//	��� B
void Player::player_b() {

	//	��������ԭ��
	setorigin(UNIT * 30, UNIT * 1);

	while (!block.IsGameOver()) {	//��Ϸδ����
		block.NewBlock();
		BeginBatchDraw();		//	��ʼ������ͼ
		while (!block.IsBottom()) {	//	������
			if (_kbhit()) {	//	�а���
				HandleInput();
			}
			else {
				block.MoveDown();	//	����
			}
		}
		block.FixBlock();
	}

	EndBatchDraw();	//	����������ͼ
}