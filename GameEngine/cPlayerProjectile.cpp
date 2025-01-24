#include "cPlayerProjectile.h"

cLoadModels cPlayerProjectile::GetModel()
{
	return projectileModel;
}

void cPlayerProjectile::SetModel(cLoadModels& playerModel)
{
	this->projectileModel = playerModel;
}

void cPlayerProjectile::Fire(float deltaTime)
{
	projectilePosition.y += deltaTime * speed;
	//std::cout << "BulletPos: " << projectilePosition.x << " " << projectilePosition.y << " " << projectilePosition.z << std::endl;
}

glm::vec3 cPlayerProjectile::GetPosition()
{
	return projectilePosition;
}

void cPlayerProjectile::SetPosition(glm::vec3 position)
{
	this->projectilePosition = position;
	projectileModel.position = projectilePosition;
}

float cPlayerProjectile::GetSpeed()
{
	return speed;
}

void cPlayerProjectile::SetSpeed(float speed)
{
	this->speed = speed;
}
