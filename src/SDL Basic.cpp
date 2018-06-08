//============================================================================
// Name        : SDL.cpp
// Author      : Alexander Kissi Jr
// Version     :
// Copyright   : Createlex
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "SDL.h"
#include "Screen.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"
#include "Particle.h"
#include "Swarm.h"


using namespace std;
using namespace cop;




int main() {


	srand(time(NULL));

	Swarm swarm;



Screen screen;
if (screen.init() == false) {

	cout << "problem loading DSL " << endl;

}


bool quit = false;

const Particle  * const pParticle = swarm.getParticle();
int screenW =Screen::SCREEN_W / 2;
while(!quit) {



	//screen.clear();
	int elasped = SDL_GetTicks();

	//screen.boxBlur();
	swarm.update(elasped);

	unsigned  char red = (1 + sin(elasped * 0.0001))  * 128;
	unsigned  char green = (1 + sin(elasped * 0.0002))  * 128;
	unsigned  char blue = (1 + sin(elasped * 0.0003))  * 128;




	for(int i = 0; i < swarm.NPARTICLES; i++) {

		Particle particles = pParticle[i];
		int x = (particles.m_x + 1) * screenW;
		int y = (particles.m_y ) * screenW + screenW;




		screen.setPixel(x, y, red,green, blue);

	}


//	for(int x = 0; x < Screen::SCREEN_W; x++) {
//		for (int y = 0; y < Screen::SCREEN_H; y++) {
//			screen.setPixel(x,y,red,green,blue);
//
//		}
//	}



	screen.setPixel(300,300, 255,255,255);






	screen.boxBlur();

	//Draws screen
	screen.update();




	if(screen.processEvents() == false) {
		break;

	}



}

screen.close();





	return 0;
}
