#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	ball.loadFromFile("gfx/Beach_Ball.png");
	ball1.setSize(sf::Vector2f(100, 100));
	ball2.setSize(sf::Vector2f(100, 100));
	ball1.setTexture(&ball);
	ball2.setTexture(&ball);
	ball2.setPosition(400, 50);
	ball1.setVelocity(100, 50);
	ball2.setVelocity(-100, -50);
	ball1.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	ball2.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{	ball1.Update(dt);
	ball2.Update(dt);
	if (Collision::checkBoundingBox(&ball1, &ball2)) {
		ball1.collisionResponse(NULL);
		ball2.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}