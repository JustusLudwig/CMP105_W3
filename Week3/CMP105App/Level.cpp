#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	speedx = 300.f;
	speedy = 300.f;

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
{

	if (circle.getPosition().x + circle.getRadius() * 2 > window->getSize().x)
	{
		speedx = -speedx;
	}

	else if ((circle.getPosition().x < 0))
	{
		speedx = -speedx;
	}
	
	if (circle.getPosition().y + circle.getRadius() * 2 > window->getSize().y)
	{
		speedy = -speedy;
	}

	else if ((circle.getPosition().y < 0))
	{
		speedy = -speedy;
	}

	//Update/move circle
	circle.move(speedx * dt, speedy * dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}