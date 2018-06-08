/*
 * Swarm.cpp
 *
 *  Created on: May 18, 2018
 *      Author: createlex
 */

#include "Swarm.h"

namespace cop {

Swarm::Swarm() {
	// TODO Auto-generated constructor stub

	m_pParticle = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	// TODO Auto-generated destructor stub
	delete [] m_pParticle;
}

void Swarm::update (int elasped) {

	int interval = elasped - lastTime;

	for ( int x = 0 ; x < NPARTICLES; x++) {
		m_pParticle[x].update(interval);
	}

	lastTime = elasped;

}

} /* namespace cop */
