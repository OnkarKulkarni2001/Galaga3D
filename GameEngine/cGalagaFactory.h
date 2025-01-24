#include "IGalagaFactory.h"

class cGalagaFactory : public IGalagaFactory {
public:

	IPlayerShip* CreatePlayerShip(ePlayerType playerType) override;

	IAlienAi* CreateAlien(eAlienType alienType) override;

	IProjectile* CreateProjectile(eProjectileType projectileType) override;

	IAnimation* CreateExplosion(eExplosionType explosionType) override;

	//IAnimation* CreateTractorBeam() override;
};