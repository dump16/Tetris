#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	方块单元的边长

//	启动界面
void Render::Welcome() {

	//	绘制游戏窗口，大小为 50*30 单元
	initgraph(UNIT * 50, UNIT * 30, EW_NOMINIMIZE);

	//	设置窗口标题
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("我罗斯方块"));

	//	设置文字输出背景
	setbkmode(TRANSPARENT);

	//	初始化随机数种子
	srand((unsigned)time(NULL));

	//	绘制欢迎界面
	settextstyle(240, 0, _T("Courier"));
	outtextxy(UNIT * 13, UNIT * 7, _T("Tetris"));

	settextstyle(28, 0, _T("微软雅黑"));
	outtextxy(UNIT * 20, 410, _T("按任意键开始游戏"));
	outtextxy(UNIT * 20, 450, _T("提示：切换输入法"));

	//	按任意键开始游戏
	_getch();
	Run();
}

//	运行界面
void Render::Run() {

	//	清屏
	cleardevice();

	//	绘制游戏池，大小为 10*22 单元
	fillrectangle(UNIT * 10, UNIT * 5, UNIT * 20, UNIT * 27);
	fillrectangle(UNIT * 30, UNIT * 5, UNIT * 40, UNIT * 27);

	//	绘制预览框，大小为 4*4 单元
	fillrectangle(UNIT * 4, UNIT * 5, UNIT * 8, UNIT * 9);
	fillrectangle(UNIT * 42, UNIT * 5, UNIT * 46, UNIT * 9);

	//	显示操作说明
	settextstyle(14, 0, _T("新宋体"));

	outtextxy(UNIT * 4, 410, _T("W：旋转"));
	outtextxy(UNIT * 4, 430, _T("A：左移"));
	outtextxy(UNIT * 4, 450, _T("D：右移"));
	outtextxy(UNIT * 4, 470, _T("S：沉底"));

	outtextxy(UNIT * 42, 410, _T("↑：旋转"));
	outtextxy(UNIT * 42, 430, _T("←：左移"));
	outtextxy(UNIT * 42, 450, _T("→：右移"));
	outtextxy(UNIT * 42, 470, _T("↓：沉底"));

	outtextxy(UNIT * 23, 410, _T("Esc：退出"));
	outtextxy(UNIT * 23, 430, _T("空格：暂停"));
	outtextxy(UNIT * 23, 450, _T("回车：新游戏"));

	//	显示玩家信息
	settextstyle(14, 0, _T("新宋体"));
	outtextxy(UNIT * 14, UNIT * 4, _T("Player A"));
	outtextxy(UNIT * 34, UNIT * 4, _T("Player B"));

	//	新游戏
	game.NewGame();

	Over();
}

//	结束界面
void Render::Over() {

	Sleep(80);

	//	显示胜负信息
	setfillcolor(BLACK);
	setlinestyle(PS_DASHDOT, 5);
	settextstyle(100, 0, _T("Courier"));

	fillroundrect(UNIT * 28, UNIT * 8, UNIT * 42, UNIT * 13, 10, 10);
	fillroundrect(UNIT * 8, UNIT * 8, UNIT * 22, UNIT * 13, 10, 10);

	if (game.GameOver() == 1) {
		outtextxy(UNIT * 31, UNIT * 8, _T("Win"));
		outtextxy(UNIT * 9, UNIT * 8, _T("Fail"));
	}
	else if (game.GameOver() == 2) {
		outtextxy(UNIT * 11, UNIT * 8, _T("Win"));
		outtextxy(UNIT * 29, UNIT * 8, _T("Fail"));
	}

	HWND wnd = GetHWnd();
	if (MessageBox(wnd, _T("是否结束游戏？"), _T("提醒"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK) {
		//	清屏
		cleardevice();
		for (int i = 0; i < 5; i++)
		{
			settextstyle(110, 0, _T("Arial Black"));
			if (i == 0)settextcolor(RED);
			else if (i == 1)settextcolor(BLUE);
			else if (i == 2)settextcolor(GREEN);
			else if (i == 3)settextcolor(YELLOW);
			else settextcolor(WHITE);
			outtextxy(UNIT * 12, UNIT * 8, _T("GAME OVER"));
			Sleep(900);
		}
		game.Quit();
	}
	else {
		setlinestyle(PS_SOLID, 1);
		Run();
		game.NewGame();
	}
}