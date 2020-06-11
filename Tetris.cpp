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

int main()
{
	Render render;
	render.Welcome();


	_getch();		//	按任意键退出
	closegraph();	//	关闭绘图窗口
	return 0;
}