/*	玩家类主要负责	与玩家的交互、处理键盘输入	*/

#pragma once
#include"Block.h"
class Player {
private:
	Block block_a, block_b,block;

public:
	Player();
	void HandleInput();		//	处理键盘输入
	void player_a();
	void player_b();
};