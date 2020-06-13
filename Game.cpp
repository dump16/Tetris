#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	方块单元的边长

Game::Game() {
	block_a = Block(UNIT * 10, UNIT * 1, UNIT * 4, UNIT * 5);
	block_b = Block(UNIT * 30, UNIT * 1, UNIT * 42, UNIT * 5);
}

//	处理键盘输入
void Game::HandleInput() {

	switch (_getch()) {	//	获取键码

	//	Player A 操作响应
	case 'W':
	case 'w':	block_a.Rotate();		break;
	case 'A':
	case 'a':	block_a.MoveLeft();		break;
	case 'S':
	case 's':	block_a.Sink();			break;
	case 'D':
	case 'd':	block_a.MoveRight();	break;

		//	Player B 操作响应
	case 0:
	case 0xE0:
		switch (_getch()) {
		case 72:	block_b.Rotate();		break;	//	↑
		case 75:	block_b.MoveLeft();		break;	//	←
		case 80:	block_b.Sink();			break;	//	↓
		case 77:	block_b.MoveRight();	break;	//	→
		}
		break;

		//	控制游戏
	case 27:	Quit();					break;	//	Esc 键 退出
	case 32:	system("pause");		break;	//	空格键 暂停
	case 13:	NewGame();				break;	//	回车键 新游戏
	}
}

//	开始新游戏
void Game::NewGame() {

	block_a.InitMap();
	block_b.InitMap();

	BeginBatchDraw();	//	开始批量绘图
	while (GameOver() == 0) {	//游戏未结束
		while (1) {//	不触底
			if (_kbhit()) {	//	有按键
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
				block_a.MoveDown();	//	下落
				block_b.MoveDown();
			}
		}
	}
	EndBatchDraw();	//	结束批量绘图

}

//	结束游戏
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

//	退出游戏
void Game::Quit() {
	closegraph();
	exit(0);
}