#pragma once
#include "IGalaga.h"
#include "cLoadModels.h"
#include <vector>

class cPlayerExplosion : public IAnimation {
public:
	std::vector<cLoadModels*> GetExplosionAnimations() override;
	void Animate(float deltaTime) override;
	glm::vec3 GetPosition() override;
	void SetPosition(glm::vec3 position) override;
private:
	std::vector<cLoadModels*> vecPlayerExplosionAnimation;
	glm::vec3 playerExplosionPosition;
};