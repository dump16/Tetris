/*	游戏类主要负责	控制游戏的开始、暂停、继续、结束、退出	*/

#pragma once
#include"Player.h"
class Game {
private:
	Player player;

public:
	void NewGame();			//	新游戏
	void GameOver();		//	结束
	void Pause();			//	暂停
	void Continue();		//	继续 
	void Exit();			//	退出
};