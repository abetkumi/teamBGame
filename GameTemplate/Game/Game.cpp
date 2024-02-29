#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"

Game::Game()
{
	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
}

Game::~Game()
{
	DeleteGO(player);
	DeleteGO(gameCamera);

}

void Game::Update()
{

}