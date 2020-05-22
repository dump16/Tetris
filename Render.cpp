#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

#define	UNIT 20	//	ÿ�����鵥Ԫ�ı߳�

//	��������
void Render::Welcome() {

	//	������Ϸ����
	initgraph(UNIT * 50, UNIT * 30);

	//	�޸Ĵ�������
	HWND hWnd = GetHWnd();
	SetWindowText(hWnd, _T("����˹����"));

	// ����ͼ�����ı���ɫΪ͸��
	setbkmode(TRANSPARENT);

	//	��ʼ�����������
	srand((unsigned)time(NULL));

	//	�������н���
	if (1) {	//	��Ӧ���� ��ʼ��Ϸ
		Run();
	}

}

//	���н���
void Render::Run() {

	//	����
	cleardevice();

	//	������Ϸ�ر߽磬��СΪ 10*22 ��Ԫ
	rectangle(UNIT * 10, UNIT * 5, UNIT * 20, UNIT * 27);
	rectangle(UNIT * 30, UNIT * 5, UNIT * 40, UNIT * 27);

	//	����Ԥ���򣬴�СΪ 4*4 ��Ԫ
	rectangle(UNIT * 4, UNIT * 5, UNIT * 8, UNIT * 9);
	rectangle(UNIT * 42, UNIT * 5, UNIT * 46, UNIT * 9);

	//	��ʾ����˵��
	settextstyle(14, 0, _T("������"));

	outtextxy(UNIT * 4, 410, _T("W����ת"));
	outtextxy(UNIT * 4, 430, _T("A������"));
	outtextxy(UNIT * 4, 450, _T("D������"));
	outtextxy(UNIT * 4, 470, _T("S����������"));

	outtextxy(UNIT * 42, 410, _T("������ת"));
	outtextxy(UNIT * 42, 430, _T("��������"));
	outtextxy(UNIT * 42, 450, _T("��������"));
	outtextxy(UNIT * 42, 470, _T("������������"));
	
	//	��ʾ�����Ϣ
	outtextxy(UNIT * 13.5, UNIT * 4, _T("Player A"));
	outtextxy(UNIT * 33.5, UNIT * 4, _T("Player B"));

	//	��ʼ����Ϸ
	Game game;
	game.NewGame();
}

//	��������
void Render::Over() {

	//	����
	cleardevice();

}