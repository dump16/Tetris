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

//	启动界面
void Render::Welcome() {

	//	绘制游戏界面，大小为 50*30 单元
	initgraph(UNIT * 50, UNIT * 30);

	//	设置窗口标题
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("我罗斯方块"));

	//	设置文字背景颜色
	setbkmode(TRANSPARENT);

	//	初始化随机数种子
	srand((unsigned)time(NULL));

	//	绘制运行界面
	if (1) {	//	响应键盘 开始游戏
		Run();
	}

}

//	运行界面
void Render::Run() {

	//	清屏
	cleardevice();

	//	绘制游戏池，大小为 10*22 单元
	rectangle(UNIT * 10, UNIT * 5, UNIT * 20, UNIT * 27);
	rectangle(UNIT * 30, UNIT * 5, UNIT * 40, UNIT * 27);

	//	绘制预览框，大小为 4*4 单元
	rectangle(UNIT * 4, UNIT * 5, UNIT * 8, UNIT * 9);
	rectangle(UNIT * 42, UNIT * 5, UNIT * 46, UNIT * 9);

	//	显示操作说明
	settextstyle(14, 0, _T("新宋体"));

	outtextxy(UNIT * 4, 410, _T("W：旋转"));
	outtextxy(UNIT * 4, 430, _T("A：左移"));
	outtextxy(UNIT * 4, 450, _T("D：右移"));
	outtextxy(UNIT * 4, 470, _T("S：快速下落"));

	outtextxy(UNIT * 42, 410, _T("↑：旋转"));
	outtextxy(UNIT * 42, 430, _T("←：左移"));
	outtextxy(UNIT * 42, 450, _T("→：右移"));
	outtextxy(UNIT * 42, 470, _T("↓：快速下落"));
	
	//	显示玩家信息
	outtextxy(UNIT * 14, UNIT * 4, _T("Player A"));
	outtextxy(UNIT * 34, UNIT * 4, _T("Player B"));
	
	//	开始新游戏
	game.NewGame();

}

//	结束界面
void Render::Over() {

	//	清屏
	cleardevice();

	settextcolor(WHITE);
	settextstyle(250, 0, _T("Courier"));
	outtextxy(UNIT * 12, 100, _T("Game"));
	outtextxy(UNIT * 22, 230, _T("OVER"));

}