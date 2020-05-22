#pragma once

class Block {
private:
	int type;			//	当前方块类型
	int shape[4][4];		//	形状
	int color;			//	颜色
	int column;
	int row;
	
public:
	void SetShape();				//	设置形状
	void NewBlock();				//	生成新方块
	void DrawBlock();				//	绘制方块
	void FixBlock();				//	擦除方块
	void Drop();					//	自动下落 
	void Move();					//	移动 
	void Rotate();					//	旋转
	void Sink();					//	直接下沉
	bool IsAgain();					//	碰撞检测
	bool Judge();					//	层满判定 
	void Eliminate();				//	消行
	void Add();						//	增行 
	bool IsGameOver();				//	胜负判定 

};