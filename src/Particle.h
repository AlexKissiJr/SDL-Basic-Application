/*
 * Particle.h
 *
 *  Created on: May 18, 2018
 *      Author: createlex
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <iostream>
#include "stdlib.h"
#include "math.h"


using namespace std;
namespace cop {

struct Particle {

	double m_x;
	double m_y;
//	double m_xspeed;
//	double m_yspeed;
	double m_speed;
	double m_direction;

	Particle();
	void init();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace cop */

#endif /* PARTICLE_H_ */
