#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	���鵥Ԫ�ı߳�

Game::Game() {
	block_a = Block(UNIT * 10, UNIT * 1, UNIT * 4, UNIT * 5);
	block_b = Block(UNIT * 30, UNIT * 1, UNIT * 42, UNIT * 5);
}

//	�����������
void Game::HandleInput() {

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
		break;

		//	������Ϸ
	case 27:	Quit();					break;	//	Esc �� �˳�
	case 32:	system("pause");		break;	//	�ո�� ��ͣ
	case 13:	NewGame();				break;	//	�س��� ����Ϸ
	}
}

//	��ʼ����Ϸ
void Game::NewGame() {

	block_a.InitMap();
	block_b.InitMap();

	BeginBatchDraw();	//	��ʼ������ͼ
	while (GameOver() == 0) {	//��Ϸδ����
		while (1) {//	������
			if (_kbhit()) {	//	�а���
				HandleInput();
			}
			else if (block_a.IsBottom()) {
				for (int i = 0; i < block_a.FixBlock(); i++) {
					block_b.AddLine();
				}
				block_a.NewBlock();
				break;
			}
			else if (block_b.IsBottom()) {
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

//	������Ϸ
int Game::GameOver() {
	if (block_a.IsGameOver()) {
		return 1;
	}
	else if (block_b.IsGameOver()) {
		return 2;
	}
	else {
		return 0;
	}
}

//	�˳���Ϸ
void Game::Quit() {
	closegraph();
	exit(0);
}