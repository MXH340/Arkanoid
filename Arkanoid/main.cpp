#include<SFML/Graphics.hpp>
#include<time.h>

using namespace sf;

void draw(RenderWindow& app);

int main()
{
	RenderWindow app(VideoMode(520, 450), "´ò×©¿é");
	app.setFramerateLimit(60);

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		draw(app);
	}

	return 0;
}

void draw(RenderWindow& app)
{
	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");
	Sprite bk(t2), ball(t3), paddle(t4);

	paddle.setPosition(300, 440);
	ball.setPosition(300, 400);

	app.clear();
	app.draw(bk);
	app.draw(ball);
	app.draw(paddle);
	app.display();
}