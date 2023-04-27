#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


void init(int* xx, int* yy, VideoMode desktop, Texture* bee_qw_pn, Sprite* bee_qw, Sprite* butn, Texture *button,Sprite* bee_tr);

void bee_be(float& x, int* xx, int* yy, float& y, VideoMode desktop, Sprite* bee_qw,int number);

int result_button(Vector2i position, VideoMode desktop, int flag);