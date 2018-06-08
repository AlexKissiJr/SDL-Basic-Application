/*
 * Swarm.h
 *
 *  Created on: May 18, 2018
 *      Author: createlex
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"


namespace cop {

class Swarm {
private:
	int lastTime;

public:

	const static int NPARTICLES = 1500;
	Particle *m_pParticle;
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticle(){return m_pParticle;}
	void update(int elapsed);
};

} /* namespace cop */

#endif /* SWARM_H_ */
