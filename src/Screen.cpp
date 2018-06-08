/*
 * Screen.cpp
 *
 *  Created on: May 14, 2018
 *      Author: createlex
 */

#include "Screen.h"
#include "SDL.h"




namespace cop {


Screen::Screen(){




	m_window = NULL;
	m_window = NULL;
    m_renderer =  NULL;
	m_texture = NULL;
	m_buffer1 = NULL;
	m_buffer2 = NULL;



}

bool Screen:: init() {


	if(SDL_Init(SDL_INIT_VIDEO) < 0) {

		cout <<"SDL Video init failed" << endl;
		return false;
	}

	cout << "SDL video init success" <<endl;

	m_window  = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,  SDL_WINDOWPOS_UNDEFINED,SCREEN_W,SCREEN_H, SDL_WINDOW_SHOWN);
	if (m_window == NULL) {

			cout << "Error " << SDL_GetError() << endl;
			SDL_Quit();
			return false;

		}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_W,SCREEN_H);

	m_buffer1 =  new Uint32[SCREEN_H * SCREEN_W];
	m_buffer2 =  new Uint32[SCREEN_H * SCREEN_W];

	memset(m_buffer1,0,SCREEN_H * SCREEN_W * sizeof(Uint32));
	memset(m_buffer2,0,SCREEN_H * SCREEN_W * sizeof(Uint32));


//	for (int i = 0; i < SCREEN_H * SCREEN_W; i++) {
//		m_buffer[i] = 0xFF0000FF;
//	}


		if(m_renderer == NULL) {
			cout << "Unable to create renderer" << endl;
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if(m_texture == NULL) {
			cout << "Unable to create texture" << endl;
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}






		return true;

}

bool Screen:: processEvents() {
		SDL_Event event;

			while(SDL_PollEvent(&event)) {


				if(event.type == SDL_QUIT){

					cout << "Closing App" <<endl;
					return false;

					break;
				}
			}


	return true;
}
void Screen:: close() {

		delete [] m_buffer1;
		delete [] m_buffer2;

		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();


}

void Screen:: update() {

	SDL_UpdateTexture(m_texture,NULL,m_buffer1,SCREEN_W* sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}


void Screen:: setPixel(int x, int y , Uint8 red, Uint8 green, Uint8 blue) {

	// checker
	if(x < 0 || x >= Screen::SCREEN_W || y < 0 || y >= Screen::SCREEN_H) {
		return;
	}

	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;


	m_buffer1[y * SCREEN_W + x ] = color;




}



void Screen:: boxBlur() {

	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < Screen::SCREEN_H; y++){

		for (int x = 0; x < Screen::SCREEN_W; x++ ){




			int redTotalColor = 0;
			int greenTotalColor = 0;
			int blueTotalColor = 0;


			for(int row = -1; row <=1; row++ ) {

				for(int col = -1; col <=1; col++){

					int currentX = x + col;
					int currentY = y + row;

					// check it doesnt get out of screen
					if(currentX >= 0 && currentX < Screen::SCREEN_W && currentY >= 0 && currentY < Screen::SCREEN_H) {

					Uint32 color = m_buffer2[currentY * Screen::SCREEN_W + currentX];

					Uint8 red = color >> 24;
					Uint8 green = color >> 16;
					Uint8 blue = color >> 8;

					redTotalColor += red;
					greenTotalColor  += green;
					blueTotalColor += blue;




					}
				}
			}

			Uint8 red = redTotalColor/9;
			Uint8 green = greenTotalColor/9;
			Uint8 blue = blueTotalColor/9;

			setPixel(x,y,red,green,blue);



		}
	}








}



} /* namespace cop */
