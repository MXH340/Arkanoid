#include<SFML/Graphics.hpp>
#include<time.h>

using namespace sf;

Vector2f blocks[100];
Vector2f ballPos = { 300,300 };
float dx = 6, dy = 5;

void draw(RenderWindow& app);
void CreateBlocks();
void Move();

int main()
{
	RenderWindow app(VideoMode(520, 450), "Arknoid Game!");
	app.setFramerateLimit(60);

	while (app.isOpen())
	{
		CreateBlocks();
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		Move();
		draw(app);
	}

	return 0;
}

//绘图
void draw(RenderWindow& app)
{
	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");
	Sprite block(t1), bk(t2), ball(t3), paddle(t4);

	paddle.setPosition(300, 440);
	ball.setPosition(ballPos.x, ballPos.y);
	app.clear();
	app.draw(bk);
	app.draw(paddle);
	app.draw(ball);
	for (int i = 0; i < 100; i++)
	{
		block.setPosition(blocks[i].x * 43, blocks[i].y * 20);
		app.draw(block);
	}
	app.display();
}

//生成砖块
void CreateBlocks()
{
	int n = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			blocks[n].x = i;
			blocks[n].y = j;
			n++;
		}
	}
}

//球的移动
void Move()
{
	ballPos.x += dx;
	ballPos.y += dy;
	if (ballPos.x < 0 || ballPos.x>520)
		dx = -dx;
	if (ballPos.y < 0 || ballPos.y>450)
		dy = -dy;
}