#pragma once
class Scene
{
public:
	virtual ~Scene() {}
	virtual Scene* GetInstance() {}

private:

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
};

