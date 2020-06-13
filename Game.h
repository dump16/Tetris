/*	游戏类主要负责	控制游戏的开始、暂停、继续、结束、退出	*/

#pragma once

class Game {
private:
	Block block_a, block_b;

public:
	Game();
	void HandleInput();		//	处理键盘输入
	void NewGame();			//	开始新游戏
	int GameOver();			//	结束游戏
	void Quit();			//	退出游戏
};