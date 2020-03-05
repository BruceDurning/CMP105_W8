#pragma once
#include "Framework/GameObject.h"

class Ball : public GameObject {
public:
	Ball();
	~Ball();
	void Update(float dt);
	void collisionResponse(GameObject* collider);
};