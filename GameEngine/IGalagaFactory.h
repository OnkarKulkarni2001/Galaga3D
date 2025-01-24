#pragma once
#include "IGalaga.h"
#include "IGalagaEnums.h"

class IGalagaFactory {
public:	
	virtual IPlayerShip* CreatePlayerShip(ePlayerType playerType) = 0;
	virtual IAlienAi* CreateAlien(eAlienType alienType) = 0;
	virtual IProjectile* CreateProjectile(eProjectileType projectileType) = 0;
	virtual IAnimation* CreateExplosion(eExplosionType explosionType) = 0;
	//virtual IAnimation* CreateTractorBeam() = 0;
};