// author Peter Lowe

#include "Game.h"
#include <iostream>



#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 480 }, "SMFL Game" },
	m_triangle{ sf::Triangles },
	m_vertexs{
		{ { 100,150 },CORNFLOWER_BLUE },
		{ { 100,350 },CORNFLOWER_BLUE },
		{ { 200,350 },CORNFLOWER_BLUE }
}

{
	for (size_t i = 0; i < 3; i++)
	{
		m_triangle.append(m_vertexs[i]);
	}
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time)
{
	// wrong way to do transformations just here to show you
	// how the vertexes could be updated you need to maintain
	// a set of MyVector3Ds and then update the vertex array
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_triangle[0].position = m_triangle[0].position + sf::Vector2f(0.0f, 0.7f);

		m_vertexs[1].position = m_vertexs[1].position + sf::Vector2f(1.0f, 1.0f); // this has no effect 
																				  // because the vertex array made a copy of the vertex when we appended it
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	{
		m_triangle[0].position = m_triangle[0].position - sf::Vector2f(0.0f, 0.7f);

		m_vertexs[1].position = m_vertexs[1].position - sf::Vector2f(1.0f, 1.0f);// this has no effect 
																				 // because the vertex array made a copy of the vertex when we appended it
	}
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_triangle);
	m_window.display();
}