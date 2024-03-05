#pragma once
class Amo : public IGameObject
{
public:
	Amo();
	~Amo();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();

	ModelRender modelRender;
	Vector3 position;
	Vector3 firstPosition;
	Quaternion rotation;

};

