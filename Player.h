/*	�������Ҫ����	����ҵĽ����������������	*/

#pragma once
#include"Block.h"
class Player {
private:
	Block block_a, block_b,block;

public:
	Player();
	void HandleInput();		//	�����������
	void player_a();
	void player_b();
};