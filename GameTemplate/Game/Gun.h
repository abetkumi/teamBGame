#pragma once

class Player;
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();

	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 m_firstPosition;
	Quaternion m_rotation;
	Player* player;
};

