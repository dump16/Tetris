/*	��Ϸ����Ҫ����	������Ϸ�Ŀ�ʼ����ͣ���������������˳�	*/

#pragma once

class Game {
private:
	Block block_a, block_b;

public:
	Game();
	void HandleInput();		//	�����������
	void NewGame();			//	��ʼ����Ϸ
	int GameOver();			//	������Ϸ
	void Quit();			//	�˳���Ϸ
};