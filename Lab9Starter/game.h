#ifndef GAME
#define GAME
// must write comments for Pete's sake


#include <SFML/Graphics.hpp>


const sf::Color CORNFLOWER_BLUE{ 154, 206, 235, 255 };

class Game
{
public:
	Game();
	void run();
private:
	void             processEvents();
	void             update(sf::Time);
	void             render();

private:
	sf::RenderWindow m_window;
	sf::VertexArray m_triangle;
	sf::Vertex m_vertexs[3]; // only used to initialise the array 

};

#endif // !GAME
