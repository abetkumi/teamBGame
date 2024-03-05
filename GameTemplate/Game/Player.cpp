#include "stdafx.h"
#include "Player.h"

Player::Player()
{

	m_charaCon.Init(25.0f, 75.0f, m_position);
}

Player::~Player()
{

}

void Player::Update()
{
	Move();
	Rotation();

	m_modelRender.Update();
}

void Player::Move()
{
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	right *= stickL.x * 120.0f;
	forward *= stickL.y * 120.0f;

	m_moveSpeed += right + forward;

	if (m_charaCon.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;
	}
	else
	{
		m_moveSpeed.y -= 10.0f;
	}
	
	if (g_pad[0]->IsPress(enButtonA))
	{
		m_moveSpeed.y = 300.0f;
	}
	

	if (g_pad[0]->IsPress(enButtonX))
	{
		m_moveSpeed = (right + forward) * 3.5;
	}

	m_position = m_charaCon.Execute(m_moveSpeed, 1.0f / 20.0f);//��܂��Ȉړ����x

	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);
		m_modelRender.SetRotation(m_rotation);
	}
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}