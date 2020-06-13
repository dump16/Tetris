#include"Block.h"
#include"Game.h"
#include"Render.h"

#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cstring>

#define	UNIT 20		//	���鵥Ԫ�ı߳�

//	��������
void Render::Welcome() {

	//	������Ϸ���ڣ���СΪ 50*30 ��Ԫ
	initgraph(UNIT * 50, UNIT * 30, EW_NOMINIMIZE);

	//	���ô��ڱ���
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("����˹����"));

	//	���������������
	setbkmode(TRANSPARENT);

	//	��ʼ�����������
	srand((unsigned)time(NULL));

	//	���ƻ�ӭ����
	settextstyle(240, 0, _T("Courier"));
	outtextxy(UNIT * 13, UNIT * 7, _T("Tetris"));

	settextstyle(28, 0, _T("΢���ź�"));
	outtextxy(UNIT * 20, 410, _T("���������ʼ��Ϸ"));
	outtextxy(UNIT * 20, 450, _T("��ʾ���л����뷨"));

	//	���������ʼ��Ϸ
	_getch();
	Run();
}

//	���н���
void Render::Run() {

	//	����
	cleardevice();

	//	������Ϸ�أ���СΪ 10*22 ��Ԫ
	fillrectangle(UNIT * 10, UNIT * 5, UNIT * 20, UNIT * 27);
	fillrectangle(UNIT * 30, UNIT * 5, UNIT * 40, UNIT * 27);

	//	����Ԥ���򣬴�СΪ 4*4 ��Ԫ
	fillrectangle(UNIT * 4, UNIT * 5, UNIT * 8, UNIT * 9);
	fillrectangle(UNIT * 42, UNIT * 5, UNIT * 46, UNIT * 9);

	//	��ʾ����˵��
	settextstyle(14, 0, _T("������"));

	outtextxy(UNIT * 4, 410, _T("W����ת"));
	outtextxy(UNIT * 4, 430, _T("A������"));
	outtextxy(UNIT * 4, 450, _T("D������"));
	outtextxy(UNIT * 4, 470, _T("S������"));

	outtextxy(UNIT * 42, 410, _T("������ת"));
	outtextxy(UNIT * 42, 430, _T("��������"));
	outtextxy(UNIT * 42, 450, _T("��������"));
	outtextxy(UNIT * 42, 470, _T("��������"));

	outtextxy(UNIT * 23, 410, _T("Esc���˳�"));
	outtextxy(UNIT * 23, 430, _T("�ո���ͣ"));
	outtextxy(UNIT * 23, 450, _T("�س�������Ϸ"));

	//	��ʾ�����Ϣ
	settextstyle(14, 0, _T("������"));
	outtextxy(UNIT * 14, UNIT * 4, _T("Player A"));
	outtextxy(UNIT * 34, UNIT * 4, _T("Player B"));

	//	����Ϸ
	game.NewGame();

	Over();
}

//	��������
void Render::Over() {

	Sleep(80);

	//	��ʾʤ����Ϣ
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
	if (MessageBox(wnd, _T("�Ƿ������Ϸ��"), _T("����"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK) {
		//	����
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