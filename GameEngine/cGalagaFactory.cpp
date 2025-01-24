#include "cGalagaFactory.h"
#include "cPlayerShipA.h"
#include "cPlayerShipB.h"
#include "cButterflyAlien.h"
#include "cBeeAlien.h"
#include "cMothBlueAlien.h"
#include "cMothGreenAlien.h"
#include "cPlayerProjectile.h"
#include "cEnemyProjectile.h"
#include "cEnemyExplosion.h"
#include "cPlayerExplosion.h"

IPlayerShip* cGalagaFactory::CreatePlayerShip(ePlayerType playerType)
{
    switch (playerType) {
    case ePlayerType::PLAYER_SHIP_A:
        return new cPlayerShipA();

    case ePlayerType::PLAYER_SHIP_B:
        return new cPlayerShipB();
        
    default:
        return nullptr;
    }
}

IAlienAi* cGalagaFactory::CreateAlien(eAlienType alienType)
{
    switch (alienType) {
    case eAlienType::MOTH_BLUE:
        return new cMothBlueAlien();

    case eAlienType::BEE:
        return new cBeeAlien();

    case eAlienType::MOTH_GREEN:
        return new cMothGreenAlien();

    case eAlienType::BUTTERFLY:
        return new cButterflyAlien();

    default:
        return nullptr;
    }
}

IProjectile* cGalagaFactory::CreateProjectile(eProjectileType projectileType)
{
    switch (projectileType) {
    case eProjectileType::ENEMY_PROJECTILE:
        return new cEnemyProjectile();

    case eProjectileType::PLAYER_PROJECTILE:
        return new cPlayerProjectile();

    default:
        return nullptr;
    }
}

IAnimation* cGalagaFactory::CreateExplosion(eExplosionType explosionType)
{
    switch (explosionType) {
    case eExplosionType::PLAYER_EXPLOSION:
        return new cPlayerExplosion();

    case eExplosionType::ENEMY_EXPLOSION:
        return new cEnemyExplosion();
    default:
        return nullptr;
    }
}
