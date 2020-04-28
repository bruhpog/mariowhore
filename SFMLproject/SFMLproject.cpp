#include <SFML/Graphics.hpp>
class Mario
{
public:
    Mario()
    {
        groundLevel = 300;
        if (image.loadFromFile("mariowhore.png"));
        mariowhore = sf::Sprite(image, sf::IntRect(0, 0, 55, 115));
    }
    void draw(sf::RenderWindow& window)
    {
        if (clock.getElapsedTime() > sf::seconds(0.1f))
        {
            clock.restart();
            mariowhore.move(speed);
            auto pos = mariowhore.getPosition().y;
        }
            window.draw(mariowhore);
    }

    void move(sf::Event event)
    {
        if (event.key.code == sf::Keyboard::Left)
            speed -= { 1, 0};
        else if (event.key.code == sf::Keyboard::Right)
            speed += { 1, 0};
        else if (event.key.code == sf::Keyboard::Up)
            speed += { 0, -10};
        else if (event.key.code == sf::Keyboard::Down)
            mariowhore.move(0, 5);
    }


private:
    sf::Texture image;
    sf::Sprite mariowhore;
    sf::Vector2f speed;
    sf::Clock clock;
    int groundLevel;

};

class Virus
{






};
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Whorio");
    sf::CircleShape virus(40.f);
    virus.setPosition(200, 200);
    Mario mario;
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                mario.move(event);


        }

        if (clock.getElapsedTime() > sf::seconds(0.1f))
        {
            clock.restart();
            if (virus.getPosition().x < 0)
                virus.setPosition(580, 200);
            virus.move(-1, 0);
            window.clear();

            mario.draw(window);
            window.draw(virus);
            window.display();
        }
    }
    return 0;
}




