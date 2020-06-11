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

#define	UNIT 20		//	方块单元的边长

Player::Player(){
	block_a = Block(UNIT * 10, UNIT * 1, UNIT * 4, UNIT * 5);
	block_b = Block(UNIT * 30, UNIT * 1, UNIT * 42, UNIT * 5);
}

//	处理键盘输入
void Player::HandleInput() {

	//while (_kbhit()) {	//	有按键
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

		}
	//}

}

//	玩家 A
void Player::player_a() {
	block_a.NewBlock();
	block_b.NewBlock();
	BeginBatchDraw();	//	开始批量绘图
	while ((!block_a.IsGameOver())&&( !block_b.IsGameOver())) {	//游戏未结束
		while (1) {//	不触底
			if (_kbhit()) {	//	有按键
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
				block_a.MoveDown();	//	下落
				block_b.MoveDown();
			}
		}
	}
	EndBatchDraw();	//	结束批量绘图

}

//	玩家 B
void Player::player_b() {

	//	设置坐标原点
	setorigin(UNIT * 30, UNIT * 1);

	while (!block.IsGameOver()) {	//游戏未结束
		block.NewBlock();
		BeginBatchDraw();		//	开始批量绘图
		while (!block.IsBottom()) {	//	不触底
			if (_kbhit()) {	//	有按键
				HandleInput();
			}
			else {
				block.MoveDown();	//	下落
			}
		}
		block.FixBlock();
	}

	EndBatchDraw();	//	结束批量绘图
}