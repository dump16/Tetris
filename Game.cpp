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

//	新游戏
void Game::NewGame() {
	player.player_a();
	/*player.player_b();*/
	GameOver();
}

//	结束
void Game::GameOver() {
	
}

//	退出
void Game::Exit() {

}

//	暂停
void Game::Pause() {

}

//	继续
void Game::Continue() {

}