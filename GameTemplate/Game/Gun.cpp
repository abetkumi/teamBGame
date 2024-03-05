#include "stdafx.h"
#include "Gun.h"
#include "Player.h"

Gun::Gun()
{

	
	player = FindGO<Player>("player");
}

Gun::~Gun()
{

}

void Gun::Update()
{
	m_position = player->m_position;

}

void Gun::Render(RenderContext& rc)
{

}

void Gun::Move()
{

}

void Gun::Rotation()
{

}
