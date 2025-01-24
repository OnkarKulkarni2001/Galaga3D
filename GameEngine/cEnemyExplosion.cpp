#include "cEnemyExplosion.h"

std::vector<cLoadModels*> cEnemyExplosion::GetExplosionAnimations()
{
	return vecEnemyExplosionAnimation;
}

void cEnemyExplosion::Animate(float deltaTime)
{
}

glm::vec3 cEnemyExplosion::GetPosition()
{
	return enemyExplosionPosition;
}

void cEnemyExplosion::SetPosition(glm::vec3 position)
{
	this->enemyExplosionPosition = position;
}
