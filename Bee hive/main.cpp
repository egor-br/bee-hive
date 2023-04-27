#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "Menu.h"
#include "Bee.h"
#include <ctime>
#include <string> 
#include "Game.h"
#include <SFML/Audio.hpp>


using namespace sf;
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SoundBuffer buffer;
	buffer.loadFromFile("1.ogg");
	Sound sound;
	sound.setBuffer(buffer);
	//sound.play();
	sound.setLoop(true);



	Font font;
	font.loadFromFile("times.ttf");
	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	Text text_1;
	text_1.setFont(font);
	text_1.setCharacterSize(36);
	text_1.setFillColor(sf::Color::White);
	int n = 2, backg = 0, k, set_poz_bum[6][2] = { {50,50},{0,0},{100,50},{50,100},{0,0},{50,50} }, posit_game = 0;
	bee** Bee ;
	Bee = new bee * [2];
	Bee[0] = new bee_qwin[1];
	Bee[1] = new bee_trut[1];
	Bee[0]->col_qwin = 1;
	n = 2;
	Bee[0]->col = 4;
	for (int i = 0; i < n; i++)
		Bee[i]->set_init_pos();
	srand(time(0));
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	sf::RenderWindow window(desktop, "Bee hive", sf::Style::None);
	Image image;
	image.loadFromFile("back.png");

	Texture texture;
	texture.loadFromImage(image);
	Texture* bee_qw_pn;
	Sprite* bee_qw;
	Texture* valut;
	Texture buum;
	Sprite* valuta;
	Sprite* bee_tr;
	Sprite* info = new Sprite[3];
	Sprite Buum;
	Texture* button;
	Texture* inf = new Texture[3];
	Texture* zad = new Texture[2];
	Sprite* butn;
	Sprite sprite;
	Sprite* zadaniu = new Sprite[2];
	Texture* game_button;
	Sprite* game_butn;
	game_butn = new Sprite[3];
	game_button = new Texture[3];
	inf[0].loadFromFile("inf.png");
	inf[1].loadFromFile("lose_col.png");
	inf[2].loadFromFile("lose_qwin.png");
	buum.loadFromFile("bum.png");
	zad[0].loadFromFile("zad.png");
	zad[1].loadFromFile("zad_1.png");
	game_button[0].loadFromFile("street.png");
	game_button[1].loadFromFile("home.png");
	game_button[2].loadFromFile("menu.png");
	sf::Vector2f m_info(desktop.width - 100, desktop.height - 100);
	sf::Vector2f m_butn(desktop.width / 30, desktop.width / 30);
	sf::Vector2f m_zad(desktop.width / 3, desktop.height / 8);
	sf::Vector2f m_lose_butn(desktop.width / 8, desktop.width / 8);

	game_butn[0].setPosition(0, desktop.height - desktop.width / 30);
	game_butn[2].setPosition(0, 0);
	game_butn[1].setPosition(desktop.width - desktop.width / 30, desktop.height - desktop.width / 30);
	for (int i = 0; i < 3; i++) {
		game_butn[i].setTexture(game_button[i]);
		game_butn[i].setScale(
			m_butn.x / game_butn[i].getLocalBounds().width,
			m_butn.y / game_butn[i].getLocalBounds().height);
	}
	for (int i = 0; i < 3; i++) {
		info[i].setTexture(inf[i]);
		info[i].setPosition(50, 50);
		info[i].setScale(
			m_info.x / info[i].getLocalBounds().width,
			m_info.y / info[i].getLocalBounds().height);
	}
	
	for (int i = 0; i < 2; i++) {
		zadaniu[i].setTexture(zad[i]);
		zadaniu[i].setPosition(desktop.width / 3, 150);
		zadaniu[i].setScale(
			m_zad.x / zadaniu[i].getLocalBounds().width,
			m_zad.y / zadaniu[i].getLocalBounds().height);
	}
	
	Buum.setTexture(buum);
	Buum.setPosition(50, 50);
	Buum.setScale(
		m_info.x / Buum.getLocalBounds().width,
		m_info.y / Buum.getLocalBounds().height);
	Texture back;
	Sprite Back;
	back.loadFromFile("back 2.png");
	Back.setTexture(back);
	sf::Vector2f targetSize(desktop.width, desktop.height); //целевой размер
	sf::Vector2f Size_valut(desktop.width/50, desktop.width / 50);
	Back.setScale(
		targetSize.x / Back.getLocalBounds().width,
		targetSize.y / Back.getLocalBounds().height);
	button = new Texture[6];
	butn = new Sprite[6];
	bee_qw = new Sprite[6];
	bee_tr = new Sprite[6];
	bee_qw_pn = new Texture[12];
	valut = new Texture[3];
	valuta = new Sprite[3];
	int col = 0, x = 50, y = 50, a, xx[2], yy[2], flag = 0, bum, zvuk = 1;
	init(xx, yy, desktop, bee_qw_pn, bee_qw, butn, button, bee_tr);
	valut[0].loadFromFile("med.png");
	valut[1].loadFromFile("sote.png");
	valut[2].loadFromFile("sote.png");
	for (int i = 0; i < 3; i++) {
		valuta[i].setTexture(valut[i]);
		valuta[i].setPosition(0, 0);
		valuta[i].setScale(
			Size_valut.x / valuta[i].getLocalBounds().width,
			Size_valut.y / valuta[i].getLocalBounds().height);
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	clock_t t0 = clock();
	clock_t t_1 = clock();
	clock_t t_2 = clock();
	int* arr, n_time = n;
	arr = new int[n_time];
	
	auto s = to_string(n);
	while (window.isOpen())
	{
		t0 = clock();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				if (flag < 0)
					flag += 2;
				if (flag == 2 || flag == 3) {
					flag = 0;
				}
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					if (flag == 6) {
						Vector2i position = Mouse::getPosition(window);
						if (position.x >= desktop.width / 2 - desktop.width / 16 && position.x < desktop.width / 2 - desktop.width / 16 + desktop.width / 8) {
							if (position.y > desktop.height / 1.5 && position.y < desktop.height / 1.5 + desktop.width / 8) {
								flag = 1;
								for (int i = 0; i < n; i++)
									delete[] Bee[i];
								free(Bee);
								delete[] arr;
								Bee = new bee * [2];
								Bee[0] = new bee_qwin[1];

								Bee[1] = new bee_trut[1];
								n = 2;
								for (int i = 0; i < n; i++) {
									Bee[i]->set_init_pos();
									k = Bee[i]->get();
									if (k == 2)
										Bee[0]->col_trut += 1;
								}
								Bee[0]->col = n;
								Bee[0]->col_med = 100;

								Bee[0]->col_qwin = 1;
							}
						}
					}
					if (flag == 0 || flag == 1) {
						Vector2i position = Mouse::getPosition(window);
						flag = result_button(position, desktop, flag);
						if (flag == 1 && zvuk == 0) {
							zvuk = 1;
							sound.pause();
						}
						if (flag == 0 && zvuk == 1) {
							sound.play();
							zvuk = 0;

						}
						if (flag == 5)
							break;
						
						if (flag == 2) {
							t0 = clock();
							for (int i = 0; i < n; i++)
								delete[] Bee[i];
							free(Bee);
							delete[] arr;
							
							Bee = new bee * [2];
							Bee[0] = new bee_qwin[1];
							Bee[1] = new bee_trut[1];
							Bee[0]->col_qwin = 1;
							n = 2;
							Bee[0]->col = 4;
							Bee[0]->col_bee = 2;
							arr = new int[n];
							n_time = n;
							for (int i = 0; i < n; i++)
								Bee[i]->set_init_pos();
							s = to_string(Bee[0]->col_vosk);
							posit_game = 1;
						}
						if (flag == 3) {
							if (posit_game == 0) {
								for (int i = 0; i < n; i++)
									delete[] Bee[i];
								free(Bee);
								delete[] arr;
								Bee =Input(Bee, n);
								posit_game = 1;
								arr = new int[n];
								n_time = n;
								t0 = clock();
								if (n < 4)
									Bee[0]->col = 4;
								
							}
						}
					}
					else {
						if (flag == 2 || flag == 3) {
							Vector2i position = Mouse::getPosition(window);
							for (int i = 0; i < n; i++) {
								if (Bee[i]->posit == 4) {
									int FLAG = 0;
									for (int j = 0; j < Bee[i]->n; j++) {
										if (position.x >= desktop.width / 3 && position.x < desktop.width / 3 * 2 ) {
											if (position.y > desktop.height / 8 * j + j * 50 + 150 && position.y < desktop.height / 8 * j + j * 50 + 150 + desktop.height / 8) {
												FLAG = 1;
												if (Bee[i]->prov_zad(j, n, Bee) == 0) {
													Bee[i]->zadanie(j, Bee);
													t_1 = clock();
													arr[i] = t_1;
													if (Bee[i]->get() == 1 || j == 3) {
														for (int l = 0; l < n; l++) {
															int a = Bee[l]->get();
															if (a == 2) {
																Bee[l]->zadanie(1, Bee);
																break;
															}
														}
													}
												}
												break;
											}
										}
									}
									if (FLAG == 0)
										Bee[i]->posit = 0;
									break;
								}
								if (Bee[i]->posit == 0 ) {
									auto m = Bee[i]->bee_sprite[0].getPosition();
									if (position.x > m.x + 50 && position.x < m.x + desktop.width/6 - 50) {
										if (position.y > m.y + 50 && position.y < m.y + desktop.height / 5 - 50) {
											Bee[i]->zadanie(-1, Bee);
											
											break;
										}
									}
								}
							}
							if (position.x < desktop.width / 30 && position.y > desktop.height - desktop.width / 30 && backg == 0)
								backg = 1;
							if (position.x > desktop.width - desktop.width / 30 && position.y > desktop.height - desktop.width / 30 && backg == 1)
								backg = 0;
							if (position.x < desktop.width / 30 && position.y < desktop.width / 30 )
								flag = 1;
						}
					}
				}
			}

		}
		

		window.clear();
		if (Bee[0]->col_med < 0 || Bee[0]->col_qwin>1) {
			flag = 6;
		}
		if (flag == 6) {
			window.draw(Back);

			if (Bee[0]->col_med < 0) {
				window.draw(info[1]);
			}
			if (Bee[0]->col_qwin > 1) {
				window.draw(info[2]);
			}
			game_butn[2].setPosition(desktop.width / 2 - desktop.width / 16, desktop.height / 1.5);
			game_butn[2].setScale(
				m_lose_butn.x / game_butn[2].getLocalBounds().width,
				m_lose_butn.x / game_butn[2].getLocalBounds().height);
			window.draw(game_butn[2]);
		
			game_butn[2].setPosition(0,0);
			game_butn[2].setScale(
				m_butn.x / game_butn[2].getLocalBounds().width,
				m_butn.x / game_butn[2].getLocalBounds().height);
		}
		if (flag == 0 || flag == 1) {
			window.draw(sprite);
			if (xx[0] > 0)
				window.draw(bee_qw[col % 3 + 3]);
			else
				window.draw(bee_qw[col % 3]);
			if (xx[1] > 0)
				window.draw(bee_tr[col % 3 + 3]);
			else
				window.draw(bee_tr[col % 3]);
			for (int i = 0; i < 5; i++) {
				if(flag == 1 && i == 4)
					window.draw(butn[i+1]);
				else
					window.draw(butn[i]);
			}
			
			auto m = bee_qw[0].getPosition();
			bee_be(m.x, xx, yy, m.y, desktop, bee_qw, 0);
			auto mm = bee_tr[0].getPosition();
			bee_be(mm.x, xx, yy, mm.y, desktop, bee_tr, 1);
			col++;
		}
		if (flag < 0) {
			window.draw(sprite);
			window.draw(info[0]);
		}
		if (flag == 5)
			break;

		if (flag == 2 || flag == 3) {
			
			if (backg == 0) {
				window.draw(Back);
				bum = 0;
				for (int i = 1; i < n; i++) {
					if (Bee[i]->posit == 5)
						bum = 1;
				}
				if (bum == 0) {
					for (int i = 0; i < n; i++) {
						if (Bee[i]->posit == 0 || Bee[i]->posit == 4) {
							if (Bee[i]->xx > 0)
								window.draw(Bee[i]->bee_sprite[col % 3 + 3]);
							else
								window.draw(Bee[i]->bee_sprite[col % 3]);

						}

						auto m = Bee[i]->bee_sprite[0].getPosition();
						Bee[i]->fly(m.x, m.y, desktop, Bee[i]->bee_sprite);
					}
					for (int i = 0; i < n; i++) {
						if (Bee[i]->posit == 4) {
							for (int j = 0; j < Bee[i]->n; j++) {
								if (Bee[i]->prov_zad(j, n, Bee) == 0) {
									zadaniu[1].setPosition(desktop.width / 3, desktop.height / 8 * j + j * 50 + 150);
									window.draw(zadaniu[1]);
								}
								else {
									zadaniu[0].setPosition(desktop.width / 3, desktop.height / 8 * j + j * 50 + 150);
									window.draw(zadaniu[0]);
								}
								text.setPosition(75 + desktop.width / 3, 50 + desktop.height / 8 * j + j * 50 + 150);
								text.setString(Bee[i]->str[j]);
								window.draw(text);
								valuta[1].setPosition(75 + desktop.width / 3 + desktop.width / 3 - desktop.width / 15, 50 + desktop.height / 8 * j + j * 50 + 175);
								window.draw(valuta[1]);
								valuta[0].setPosition(75 + desktop.width / 3 + desktop.width / 3 - desktop.width / 9, 50 + desktop.height / 8 * j + j * 50 + 175);
								window.draw(valuta[0]);
							}
							break;
						}
						else {
							if (Bee[i]->posit != 0 && Bee[i]->get() != 2) {
								Bee = prov_zad(Bee, n, t0, arr[i], arr,i);
								if (n_time < n) {
									int* ar = new int[n];
									for (int l = 0; l < n_time; l++) {
										ar[l] = arr[l];
									}

									n_time = n;
									delete[] arr;
									arr = ar;
								}
							}


						}

					}
				}
				else {
					Buum.setPosition(set_poz_bum[rand() % 6][rand() % 2], set_poz_bum[rand() % 6][rand() % 2]);
					window.draw(Buum);
					for (int i = 0; i < n; i++) {
						if (Bee[i]->posit != 0 && Bee[i]->get() != 2) {
							Bee = prov_zad(Bee, n, t0, arr[i], arr, i);
							if (n_time < n) {
								int* ar = new int[n];
								for (int l = 0; l < n_time; l++) {
									ar[l] = arr[l];
								}

								n_time = n;
								delete[] arr;
								arr = ar;
							}
						}
					}
				}
			}
			else {
				window.draw(sprite);

				for (int i = 0; i < n; i++) {
					if (Bee[i]->posit == 1) {
						if (Bee[i]->xx > 0)
							window.draw(Bee[i]->bee_sprite[col % 3 + 3]);
						else
							window.draw(Bee[i]->bee_sprite[col % 3]);
						auto m = Bee[i]->bee_sprite[0].getPosition();
						Bee[i]->fly(m.x, m.y, desktop, Bee[i]->bee_sprite);
					}
					if (Bee[i]->posit != 0) {
						Bee = prov_zad(Bee, n, t0, arr[i],arr,i);
					}
				}
			}
			if (t0 - t_2 >= 30000) {
				for (int i = 0; i < n; i++) {
					if (Bee[i]->get() == 1) {
						Bee[0]->col_med -= 7;
					}
					else {
						if (Bee[i]->get() == 2)
							Bee[0]->col_med -= 12;
						else
							Bee[0]->col_med -= 3;
					}
				}
				t_2 = t0;
			}
			col++;
			valuta[1].setPosition(desktop.width - 30 - desktop.width/50, 15);
			window.draw(valuta[1]);
			valuta[0].setPosition(desktop.width - 180 - desktop.width / 50, 15);
			window.draw(valuta[0]);
			text_1.setPosition(desktop.width - 150, 10);
			s = std::to_string(Bee[0]->col_vosk);
			text_1.setString(s);
			window.draw(text_1);
			text_1.setPosition(desktop.width - 300, 10);
			s = std::to_string(Bee[0]->col_med);
			text_1.setString(s);
			window.draw(text_1);
			window.draw(game_butn[backg]);
			window.draw(game_butn[2]);
		}
		
		window.display();
		sleep(sf::milliseconds(80));
	}
	Ounput(Bee, Bee[0]->col_bee );
	delete[] Bee;
	
	return 0;
}