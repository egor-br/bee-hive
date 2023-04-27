#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <string>

class  bee
{
public:
	
	int  xx, posit = 0, col = 4, n = 4, col_trut = 0, col_qwin = 0, hp, col_med = 100, col_vosk = 100, col_max = 12, Time[4] = { 5,5,5,5 }, col_bee = 0;//позиции три улица, улей(занят), пропали на задание
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	String* str;
	Texture* bee_texture;
	Sprite* bee_sprite;


	bee() {
		str = new String[4];
		bee_texture = new Texture[6];
		bee_sprite = new Sprite[6];
	}
	~bee() {
		delete[] bee_texture;
		delete[] bee_sprite;
	}
	void set_init_pos() {

		int a = rand()%2;
		if (a % 2 == 0)
			xx = 1;
		else
			xx = -1;
		a = rand() % 2;
		if (a % 2 == 0)
			yy = 1;
		else
			yy = -1;
	}
	void fly(float& x, float& y, VideoMode desktop, Sprite* bee_qw) {
		if (x <= 0 || x >= desktop.width - desktop.width / 6) {
			xx = xx * (-1);
		}
		if (y <= 50 || y >= desktop.height - desktop.height / 5 - 50) {
			yy = yy * (-1);
		}
		x = x + xx * 4; y = y + yy * 4;
		for (int i = 0; i < 6; i++) {
			if (i == 3 && xx > 0)
				x += 10;
			bee_qw[i].setPosition(x, y);
			if (i == 3 && xx > 0)
				x -= 10;
		}
	}
	virtual void zadanie(int j,bee** Bee) = 0;
	virtual int get() = 0;
	virtual int prov_zad(int i, int n, bee** Bee) = 0;

private:
	int  yy;
};


class bee_qwin : public bee
{
public:

	void zadanie(int j, bee** Bee) {
		switch (j)
		{
			case -1:
				posit = 4; break;
			case 0:
				Bee[0]->col_med -= 50;
				Bee[0]->col_vosk -= 30;
				posit = 5;
				break;
			case 1:
				Bee[0]->col_med -= 80;
				Bee[0]->col_vosk -= 45;
				posit = 6;
				break;
			case 2:
				Bee[0]->col_med -= 110;
				Bee[0]->col_vosk -= 50;
				posit = 7;
				break;
			case 3:
				Bee[0]->col_med -= 110;
				Bee[0]->col_vosk -= 50;
				posit = 8;
				break;
		default:
			break;
		}
	}
	int prov_zad(int i, int n, bee** Bee) {
		if(Bee[0]->col_med >= 50 && Bee[0]->col_vosk >= 30 && i == 0 && n < Bee[0]->col && n < Bee[0]->col_max)
			return 0;
		if (Bee[0]->col_med >= 80 && Bee[0]->col_vosk >= 45 && i == 1 && n < Bee[0]->col && n < Bee[0]->col_max)
			return 0;
		if (Bee[0]->col_med >= 110 && Bee[0]->col_vosk >= 50 && i == 2 && n < Bee[0]->col && n < Bee[0]->col_max)
			return 0;
		if (Bee[0]->col_med >= 110 && Bee[0]->col_vosk >= 50 && i == 3 && n < Bee[0]->col && n < Bee[0]->col_max)
			return 0;
		return 1;
	};
	int get() {
		return 1;
	}
	bee_qwin() {
		str[0] = L"Создать обычную пчелу\n                                                                  50          30";
		str[1] = L"Создать рабочую пчелу\n                                                                  80          45";
		str[2] = L"Создать пчелу оруженика\n                                                                 110         50";
		str[3] = L"Создать пчелу медоносца\n                                                                 110         50";
		bee_texture[0].loadFromFile("qwin 1.png");
		bee_texture[1].loadFromFile("qwin 2.png");
		bee_texture[2].loadFromFile("qwin 3.png");
		bee_texture[3].loadFromFile("qwin 4.png");
		bee_texture[4].loadFromFile("qwin 5.png");
		bee_texture[5].loadFromFile("qwin 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand()%1000,60+ rand()%600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};

class bee_trut : public bee
{
public:
	int zad;

	void zadanie(int j,bee** Bee) {
		if (j == -1)
			posit = 0;
		else
			posit = 3;
	}
	int get() {
		return 2;
	}
	int prov_zad(int i, int n,bee** Bee) {
		return 0;
	};

	bee_trut() {
		col_trut++;
		bee_texture[0].loadFromFile("tr 1.png");
		bee_texture[1].loadFromFile("tr 2.png");
		bee_texture[2].loadFromFile("tr 3.png");
		bee_texture[3].loadFromFile("tr 4.png");
		bee_texture[4].loadFromFile("tr 5.png");
		bee_texture[5].loadFromFile("tr 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand() % 1000, 60 + rand() % 600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};


class bee_ob : public bee
{
public:
	int zad;

	int get() {
		return 3;
	}
//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
	void zadanie(int j, bee** Bee) {
		switch (j)
		{
		case -1:
			posit = 4; break;
		case 0:
			posit = 1;
			break;
		case 1:
			Bee[0]->col_med -= 30;
			posit = 2;
			break;
		case 2:
			Bee[0]->col_med -= 150;
			Bee[0]->col_vosk -= 150;
			posit = 3;
			break;
		case 3:
			Bee[0]->col_med -= 400;
			Bee[0]->col_vosk -= 400;
			posit = 5;
			break;
		default:
			break;
		}
	}
	int prov_zad(int i, int n, bee** Bee) {
		if (i == 0)
			return 0;
		if (Bee[0]->col_med >= 30 && i == 1)
			return 0;
		if (Bee[0]->col_med >= 150 && Bee[0]->col_vosk >= 150 && i == 2)
			return 0;
		if (Bee[0]->col_med >= 400 && Bee[0]->col_vosk >= 400 && i == 3 && Bee[0]->col_trut > 1)
			return 0;
		return 1;
	};
	bee_ob() {

		str[0] = L"Собрать мёд\n                                                                    0            0";
		str[1] = L"Сделать воск\n                                                                   30           0";
		str[2] = L"Увеличить мест в улье\n                                                                 150        150";
		str[3] = L"Убить трутня\n                                                                 400        400";
		bee_texture[0].loadFromFile("ob 1.png");
		bee_texture[1].loadFromFile("ob 2.png");
		bee_texture[2].loadFromFile("ob 3.png");
		bee_texture[3].loadFromFile("ob 4.png");
		bee_texture[4].loadFromFile("ob 5.png");
		bee_texture[5].loadFromFile("ob 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand() % 1000, 60 + rand() % 600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};

class bee_work : public bee
{
public:

	int get() {
		return 4;
	}
	//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
	void zadanie(int j, bee** Bee) {
		switch (j)
		{
		case -1:
			posit = 4; break;
		case 0:
			posit = 1;
			break;
		case 1:
			Bee[0]->col_med -= 50;
			posit = 2;
			break;
		case 2:
			Bee[0]->col_med -= 100;
			Bee[0]->col_vosk -= 100;
			posit = 3;
			break;
		case 3:
			Bee[0]->col_med -= 400;
			Bee[0]->col_vosk -= 400;
			posit = 5;
			break;
		default:
			break;
		}
	}
	int prov_zad(int i, int n,bee** Bee) {
		if (i == 0)
			return 0;
		if (Bee[0]->col_med >= 50 && i == 1)
			return 0;
		if (Bee[0]->col_med >= 100 && Bee[0]->col_vosk >= 100 && i == 2)
			return 0;
		if (Bee[0]->col_med >= 400 && Bee[0]->col_vosk >= 400 && i == 3 && Bee[0]->col_trut > 1)
			return 0;
		return 1;
	};

	bee_work() {

		str[0] = L"Собрать мёд\n                                                                    0            0";
		str[1] = L"Сделать воск\n                                                                   50           0";
		str[2] = L"Увеличить мест в улье\n                                                                 100        100";
		str[3] = L"Убить трутня\n                                                                 400        400";
		bee_texture[0].loadFromFile("wr 1.png");
		bee_texture[1].loadFromFile("wr 2.png");
		bee_texture[2].loadFromFile("wr 3.png");
		bee_texture[3].loadFromFile("wr 4.png");
		bee_texture[4].loadFromFile("wr 5.png");
		bee_texture[5].loadFromFile("wr 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand() % 1000, 60 + rand() % 600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};

class bee_or : public bee
{
public:
	int get() {
		return 5;
	}

	//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
	void zadanie(int j,bee** Bee) {
		switch (j)
		{
		case -1:
			posit = 4; break;
		case 0:
			posit = 1;
			break;
		case 1:
			Bee[0]->col_med -= 50;
			posit = 2;
			break;
		case 2:
			Bee[0]->col_med -= 200;
			Bee[0]->col_vosk -= 200;
			posit = 3;
			break;
		case 3:
			Bee[0]->col_med -= 80;
			Bee[0]->col_vosk -= 80;
			posit = 5;
			break;
		default:
			break;
		}
	}
	int prov_zad(int i, int n,bee **Bee) {
		if (i == 0)
			return 0;
		if (Bee[0]->col_med >= 50 && i == 1)
			return 0;
		if (Bee[0]->col_med >= 200 && Bee[0]->col_vosk >= 200 && i == 2 )
			return 0;
		if (Bee[0]->col_med >= 80 && Bee[0]->col_vosk >= 80 && i == 3 && Bee[0]->col_trut > 1)
			return 0;
		return 1;
	};

	bee_or() {

		str[0] = L"Собрать мёд\n                                                                    0            0";
		str[1] = L"Сделать воск\n                                                                   50           0";
		str[2] = L"Увеличить мест в улье\n                                                                 200        200";
		str[3] = L"Убить трутня\n                                                                   80          80";

		bee_texture[0].loadFromFile("or 1.png");
		bee_texture[1].loadFromFile("or 2.png");
		bee_texture[2].loadFromFile("or 3.png");
		bee_texture[3].loadFromFile("or 4.png");
		bee_texture[4].loadFromFile("or 5.png");
		bee_texture[5].loadFromFile("or 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand() % 1000, 60 + rand() % 600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};

class bee_med : public bee
{
public:
	//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
	void zadanie(int j, bee** Bee) {
		switch (j)
		{
		case -1:
			posit = 4; break;
		case 0:
			posit = 1;
			break;
		case 1:
			Bee[0]->col_med -= 50;
			posit = 2;
			break;
		case 2:
			Bee[0]->col_med -= 200;
			Bee[0]->col_vosk -= 200;
			posit = 3;
			break;
		case 3:
			Bee[0]->col_med -= 350;
			Bee[0]->col_vosk -= 350;
			posit = 5;
			break;
		default:
			break;
		}
	}
	int get() {
		return 6;
	}
	int prov_zad(int i, int n,bee** Bee) {
		if (i == 0)
			return 0;
		if (Bee[0]->col_med >= 50 && i == 1)
			return 0;
		if (Bee[0]->col_med >= 200 && Bee[0]->col_vosk >= 200 && i == 2)
			return 0;
		if (Bee[0]->col_med >= 350 && Bee[0]->col_vosk >= 350 && i == 3 && Bee[0]->col_trut > 1)
			return 0;
		return 1;
	};
	bee_med() {

		str[0] = L"Собрать мёд\n                                                                    0            0";
		str[1] = L"Сделать воск\n                                                                   50           0";
		str[2] = L"Увеличить мест в улье\n                                                                 200        200";
		str[3] = L"Убить трутня\n                                                                 350        350";

		bee_texture[0].loadFromFile("med 1.png");
		bee_texture[1].loadFromFile("med 2.png");
		bee_texture[2].loadFromFile("med 3.png");
		bee_texture[3].loadFromFile("med 4.png");
		bee_texture[4].loadFromFile("med 5.png");
		bee_texture[5].loadFromFile("med 6.png");
		sf::Vector2f beeSize(desktop.width / 6, desktop.height / 5); //целевой размер

		for (int i = 0; i < 6; i++) {
			bee_sprite[i].setTexture(bee_texture[i]);
			bee_sprite[i].setPosition(rand() % 1000, 60 + rand() % 600);
			bee_sprite[i].setScale(
				beeSize.x / bee_sprite[i].getLocalBounds().width,
				beeSize.y / bee_sprite[i].getLocalBounds().height);
		}
	}

};