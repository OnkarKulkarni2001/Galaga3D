#pragma once
#include "IGalaga.h"
#include "cLoadModels.h"

class cEnemyProjectile : public IProjectile {
public:
	cLoadModels GetModel() override;
	void SetModel(cLoadModels& playerModel) override;
	void Fire(float deltaTime) override;
	glm::vec3 GetPosition() override;
	void SetPosition(glm::vec3 position) override;
	float GetSpeed() override;
	void SetSpeed(float speed) override;
private:
	float speed = 1.0f;

	cLoadModels enemyProjectileModel;
	glm::vec3 projectilePosition;
};