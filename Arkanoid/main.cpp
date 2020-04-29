#include<SFML/Graphics.hpp>
#include<time.h>

using namespace sf;

Sprite blocks[100], ball, paddle;
float dx = 6, dy = 5;
int N = 100;

void draw(RenderWindow& app);
void CreateBlocks();
void Move();
bool isCollide(Sprite s1, Sprite s2);
void Control();

int main()
{
	RenderWindow app(VideoMode(520, 450), "Arknoid Game!");
	app.setFramerateLimit(60);
	ball.setPosition(300, 300);
	paddle.setPosition(300, 440);
	CreateBlocks();
	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		Control();
		Move();
		draw(app);
	}

	return 0;
}

//»æÍ¼
void draw(RenderWindow& app)
{
	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");
	Sprite bk(t2);

	ball.setTexture(t3);
	paddle.setTexture(t4);

	app.clear();
	app.draw(bk);
	app.draw(paddle);
	app.draw(ball);
	for (int i = 0; i < 100; i++)
	{
		blocks[i].setTexture(t1);
		app.draw(blocks[i]);
	}
	app.display();
}

//Éú³É×©¿é
void CreateBlocks()
{
	int n = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			blocks[n].setPosition(i * 43, j * 20);
			n++;
		}
	}
}

//ÇòµÄÒÆ¶¯
void Move()
{
	srand(time(0));
	ball.move(dx, 0);
	for (int i = 0; i < N; i++)
	{
		if (isCollide(ball, blocks[i]))
		{
			blocks[i].setPosition(-100, 0);
			dx = -dx;
		}
	}
	ball.move(0, dy);
	for (int i = 0; i < N; i++)
	{
		if (isCollide(ball, blocks[i]))
		{
			blocks[i].setPosition(-100, 0);
			dy = -dy;
		}
	}
	Vector2f ballPos = ball.getPosition();
	if (ballPos.x < 0 || ballPos.x>520)
		dx = -dx;
	if (ballPos.y < 0 || ballPos.y>450)
		dy = -dy;
	if (isCollide(ball, paddle))
		dy = -(rand() % 5 + 2);
}

//¼ì²âÅö×²
bool isCollide(Sprite s1, Sprite s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

void Control()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
		paddle.move(6, 0);
	else if (Keyboard::isKeyPressed(Keyboard::Left))
		paddle.move(-6, 0);
}