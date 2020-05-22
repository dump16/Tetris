#include"Block.h"
#include"Game.h"
#include"Render.h"
#include"Player.h"
#include<graphics.h>
#include<conio.h>
#include<ctime>

//	开始新游戏
void Game::NewGame() {
	Block block;
	block.NewBlock();
}

//	结束游戏
void Game::GameOver() {

}

//	退出游戏
void Game::Quit() {

}

//	暂停游戏
void Game::Pause() {

}

//	继续游戏 
void Game::Continue() {

}