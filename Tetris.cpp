#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

int main()
{
	Render x;
	x.Welcome();


	_getch();		// 运行完等待，不闪退
	closegraph();	//关闭绘图窗口
	return 0;
}