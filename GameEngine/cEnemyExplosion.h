#pragma once
#include "IGalaga.h"
#include "cLoadModels.h"
#include <vector>

class cEnemyExplosion : public IAnimation {
public:
	std::vector<cLoadModels*> GetExplosionAnimations() override;
	void Animate(float deltaTime) override;
	glm::vec3 GetPosition() override;
	void SetPosition(glm::vec3 position) override;
private:
	std::vector<cLoadModels*> vecEnemyExplosionAnimation;
	glm::vec3 enemyExplosionPosition;
};