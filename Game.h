/*	��Ϸ����Ҫ����	������Ϸ�Ŀ�ʼ����ͣ���������������˳�	*/

#pragma once
#include"Player.h"
class Game {
private:
	Player player;

public:
	void NewGame();			//	����Ϸ
	void GameOver();		//	����
	void Pause();			//	��ͣ
	void Continue();		//	���� 
	void Exit();			//	�˳�
};