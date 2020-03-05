#include "Ball.h"

Ball::Ball(){
}

Ball::~Ball()
{
}

void Ball::Update(float dt) {
	move(velocity * dt);
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 750)
	{
		setPosition(750, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}
	if (getPosition().y > 500)
	{
		setPosition(getPosition().x, 500);
		velocity.y = -velocity.y;
	}
}
void Ball::collisionResponse(GameObject* collider) {
	
		velocity.x = -velocity.x;
		velocity.y = -velocity.y;
}