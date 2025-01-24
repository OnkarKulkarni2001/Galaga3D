#include "cEnemyProjectile.h"

cLoadModels cEnemyProjectile::GetModel()
{
	return enemyProjectileModel;
}

void cEnemyProjectile::SetModel(cLoadModels& playerModel)
{
	this->enemyProjectileModel = playerModel;
}

void cEnemyProjectile::Fire(float deltaTime)
{
	projectilePosition.y -= deltaTime * speed;
}

glm::vec3 cEnemyProjectile::GetPosition()
{
	return projectilePosition;
}

void cEnemyProjectile::SetPosition(glm::vec3 position)
{
	this->projectilePosition = position;
	enemyProjectileModel.position = projectilePosition;
}

float cEnemyProjectile::GetSpeed()
{
	return speed;
}

void cEnemyProjectile::SetSpeed(float speed)
{
	this->speed = speed;
}
