#include "cPlayerExplosion.h"

std::vector<cLoadModels*> cPlayerExplosion::GetExplosionAnimations()
{
	return vecPlayerExplosionAnimation;
}

void cPlayerExplosion::Animate(float deltaTime)
{
}

glm::vec3 cPlayerExplosion::GetPosition()
{
	return playerExplosionPosition;
}

void cPlayerExplosion::SetPosition(glm::vec3 position)
{
	this->playerExplosionPosition = position;
}
