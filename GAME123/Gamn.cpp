#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1080, 720), "What");
	window.setFramerateLimit(60);

	Texture t1, t2;
	t1.loadFromFile("BG01.png");
	t2.loadFromFile("12.png");

	Sprite sBackground(t1), sanimation(t2);
	sanimation.setPosition(300, 300);
	sanimation.setOrigin(22, 22);

	float x= 300, y= 300;
	float speed = 0, angle = 0;
	float maxSpeed = 12.0;
	float acc = 0.2, dec = 0.3;
	float turnSpeed = 0.08;


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if(e.type == Event::Closed)
				window.close();
		}
	
		bool Up = 0, Right = 0, Down = 0, Left = 0;
		if (Keyboard::isKeyPressed(Keyboard::Up)) Up = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) Right = 1;
		if (Keyboard::isKeyPressed(Keyboard::Down)) Down = 1;
		if (Keyboard::isKeyPressed(Keyboard::Left)) Left = 1;
		//animation movement
		if (Up && speed < maxSpeed)
			if (speed < 0) speed += dec;
			else speed += acc;
		if (Down && speed > -maxSpeed)
			if (speed >0)speed -= dec;
			else speed -=acc;
		if (!Up && !Down)
			if (speed - dec > 0) speed -= dec;
			else if (speed + dec < 0) speed += dec;
			else speed = 0;
		if (Right && speed != 0) angle += turnSpeed * speed / maxSpeed;
		if(Left&& speed!=0) angle -= turnSpeed * speed / maxSpeed;

		x += sin(angle) * speed;
		y -= cos(angle) * speed;




		window.clear(Color::Black);
		window.draw(sBackground);
		sanimation.setPosition(x, y);
		sanimation.setRotation(angle * 180 / 3.141592);

		window.draw(sanimation);
		window.display();
	}
	return 0;
}

