/*
 * Particle.cpp
 *
 *  Created on: May 18, 2018
 *      Author: createlex
 */

#include "Particle.h"

namespace cop {

Particle::Particle() :m_x(0.0), m_y(0.0){
	// TODO Auto-generated constructor stub

	init();

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::init(){
	m_x = 0.0;
	m_y = 0.0;

	m_direction = ( 2.0 * M_PI * rand())/RAND_MAX;
	m_speed =  (0.0001  *  rand())/RAND_MAX;

	m_speed = m_speed * 2;

}

void Particle:: update(int interval){


	m_direction += interval * 0.0002;
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x +=  xspeed * interval;
	m_y += yspeed * interval;

	if(m_x < -1 || m_x > 1 || m_y < -1 || m_y >1) {
		init();
	}

//	m_x += m_xspeed;
//	m_y += m_yspeed;

//
//	if(m_x <= -1.0 || m_x >= 1.0) {
//		m_xspeed = -m_xspeed;
//	}
//
//	if(m_y <= -1.0 || m_y >= 1.0) {
//			m_yspeed = -m_yspeed;
//		}

}

} /* namespace cop */
