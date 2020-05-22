#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

//	键盘响应
void Player::Kbhit() {
	Block block;

	if (_kbhit()) {	//	有按键
		switch (_getch()){	//	获取键码
		
		//	Player A 操作响应
		case 'W':
		case 'w':	block.Rotate();		break;
		case 'A':
		case 'a':	block.Move();		break;
		case 'S':
		case 'd':	block.Sink();		break;
		case 'D':
		case 's':	block.Move();		break;
		
		//	Player B 操作响应
		case 72:	block.Rotate();		break;	//	↑
		case 75:	block.Move();		break;	//	←
		case 80:	block.Sink();		break;	//	↓
		case 77:	block.Move();		break;	//	→
		
		}
	}
}
