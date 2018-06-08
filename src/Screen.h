/*
 * Screen.h
 *
 *  Created on: May 14, 2018
 *      Author: createlex
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include "SDL.h"
using namespace std;


namespace cop {



class Screen {
public:
	int static const SCREEN_W = 600;
	int static const SCREEN_H = 700;


private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;




public:


	Screen();
	bool init();
	bool processEvents();
	void close();
	void update();
	void setPixel(int x, int y , Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();


};


} /* namespace cop */

#endif /* SCREEN_H_ */
