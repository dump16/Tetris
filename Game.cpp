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

#define	UNIT 20		//	���鵥Ԫ�ı߳�

//	����Ϸ
void Game::NewGame() {
	player.player_a();
	/*player.player_b();*/
	GameOver();
}

//	����
void Game::GameOver() {
	
}

//	�˳�
void Game::Exit() {

}

//	��ͣ
void Game::Pause() {

}

//	����
void Game::Continue() {

}