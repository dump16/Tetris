/*	方块类主要负责	设置、操作、判定、绘制方块	*/

#pragma once

class Unit {
public:
	int state;		//	状态
					/*	空格	0
						落定	1
						预览	2	*/
	int color;		//	颜色
};

class Block {
private:
	int view_type;				//	预览方块类型
	int view_shape[4][4];		//	形状
	int view_color;				//	颜色
	int view_x;					//	横坐标
	int view_y;					//	纵坐标

	int dynamic_type;			//	动态方块类型
	int dynamic_shape[4][4];	//	形状
	int dynamic_color;			//	颜色
	int row;					//	基础点行坐标
	int column;					//	列坐标

	Unit map[26][10];			//	游戏池地图
	int map_x;					//	横坐标
	int map_y;					//	纵坐标

public:
	Block() {}
	Block(int x1, int y1, int x2, int y2);
	void InitMap();				//	初始化地图
	void SetViewBlock();		//	设置预览方块
	void NewBlock();			//	生成
	void DrawBlock();			//	绘制
	void ClearBlock();			//	擦除
	int	FixBlock();				//	固定
	void Refresh();				//	更新

	void MoveDown();			//	下落
	void MoveLeft();			//	左移
	void MoveRight();			//	右移
	void Rotate();				//	旋转
	void Sink();				//	沉底
	void DeleteLine(int r);		//	消行
	void AddLine();				//	增行 

	bool IsBottom();			//	触底检测
	bool IsAgain();				//	碰撞检测
	bool IsFullLine(int r);		//	层满检测
	bool IsGameOver();			//	结束检测 

};