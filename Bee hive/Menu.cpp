#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace sf;

void init(int* xx, int* yy, VideoMode desktop, Texture* bee_qw_pn, Sprite* bee_qw, Sprite* butn, Texture* button, Sprite* bee_tr) {


	button[0].loadFromFile("play.png");
	button[1].loadFromFile("now_play.png");
	button[2].loadFromFile("info.png");
	button[3].loadFromFile("end.png");
	button[4].loadFromFile("zvuk 1.png");
	button[5].loadFromFile("zvuk 2.png");
	bee_qw_pn[0].loadFromFile("qwin 1.png");
	bee_qw_pn[1].loadFromFile("qwin 2.png");
	bee_qw_pn[2].loadFromFile("qwin 3.png");
	bee_qw_pn[3].loadFromFile("qwin 4.png");
	bee_qw_pn[4].loadFromFile("qwin 5.png");
	bee_qw_pn[5].loadFromFile("qwin 6.png");
	bee_qw_pn[6].loadFromFile("tr 1.png");
	bee_qw_pn[7].loadFromFile("tr 2.png");
	bee_qw_pn[8].loadFromFile("tr 3.png");
	bee_qw_pn[9].loadFromFile("tr 4.png");
	bee_qw_pn[10].loadFromFile("tr 5.png");
	bee_qw_pn[11].loadFromFile("tr 6.png");


	for (int i = 0; i < 6; i++) {
		butn[i].setTexture(button[i]);
		bee_qw[i].setTexture(bee_qw_pn[i]);
		bee_tr[i].setTexture(bee_qw_pn[i+6]);
	}

	sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер
	sf::Vector2f m_button(desktop.width / 3, desktop.height / 6);
	sf::Vector2f m_butn(desktop.width / 10, desktop.height / 9);
	butn[4].setPosition(0, desktop.height - desktop.height / 9);
	butn[4].setScale(
		m_butn.x / butn[4].getLocalBounds().width,
		m_butn.y / butn[4].getLocalBounds().height);
	butn[5].setPosition(0, desktop.height - desktop.height / 9);
	butn[5].setScale(
		m_butn.x / butn[5].getLocalBounds().width,
		m_butn.y / butn[5].getLocalBounds().height);
	for (int i = 0; i < 12; i++) {
		if (i < 4) {
			butn[i].setPosition(desktop.width  - desktop.width / 3 - 50, 100 + 50 * i + i * desktop.height / 6);
			butn[i].setScale(
				m_button.x / butn[i].getLocalBounds().width,
				m_button.y / butn[i].getLocalBounds().height);
		}
		if (i < 6) {
			bee_qw[i].setPosition(50, 50);
			bee_qw[i].setScale(
				beeSize.x / bee_qw[i].getLocalBounds().width,
				beeSize.y / bee_qw[i].getLocalBounds().height);
		}
		if (i >= 6) {
			bee_tr[i-6].setPosition(desktop.width - desktop.width / 5, desktop.height /2);
			bee_tr[i-6].setScale(
				beeSize.x / bee_tr[i-6].getLocalBounds().width,
				beeSize.y / bee_tr[i-6].getLocalBounds().height);
		}

	}
	int  a;
	a = rand() % 2;
	if (a % 2 == 0)
		xx[0] = 1;
	else
		xx[0] = -1;
	a = rand() % 2;
	if (a % 2 == 0)
		yy[0] = 1;
	else
		yy[0] = -1;
	a = rand() % 2;
	if (a % 2 == 0)
		xx[1] = 1;
	else
		xx[1] = -1;
	a = rand() % 2;
	if (a % 2 == 0)
		yy[1] = 1;
	else
		yy[1] = -1;
}

int result_button(Vector2i position, VideoMode desktop, int flag)
{

	if (position.x > desktop.width - desktop.width / 3 - 50 && position.x < desktop.width - 50) {
		if(position.y > 100 && position.y < 100 + 1 * desktop.height / 6)
			return 3;
		if (position.y > 100 + 50 * 1 + 1 * desktop.height / 6 && position.y < 100 + 50+2 * desktop.height / 6)
			return 2;
		if (position.y > 100 + 50 * 2 + 2 * desktop.height / 6 && position.y < 100 + 50*2 + 3 * desktop.height / 6)
			return flag - 2;
		if (position.y > 100 + 50 * 3 + 3 * desktop.height / 6 && position.y < 100 + 50 * 3 + 4 * desktop.height / 6)
			return 5;
	}
	else {
		if (position.x < desktop.width / 10 && position.y > desktop.height - desktop.height / 9)
			return (flag + 1) % 2;
		else
			return flag;
	}
}


void bee_be(float& x, int* xx, int* yy, float& y, VideoMode desktop, Sprite* bee_qw, int number) {
	if (x <= 0 || x >= desktop.width - desktop.width / 6) {
		xx[number] = xx[number] * (-1);
	}
	if (y <= 0 || y >= desktop.height - desktop.height / 5) {
		yy[number] = yy[number] * (-1);
	}
	x = x + xx[number] * 4; y = y + yy[number] * 4;
	for (int i = 0; i < 6; i++) {
		if (i == 3 && xx[number] > 0)
			x += 10;
		bee_qw[i].setPosition(x, y);
		if (i == 3 && xx[number] > 0)
			x -= 10;
	}
}

