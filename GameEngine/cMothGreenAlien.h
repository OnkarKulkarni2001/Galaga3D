#pragma once
#include "IGalaga.h"
#include "cLoadModels.h"

class cMothGreenAlien : public IAlienAi {
public:
    cLoadModels GetModel() override;
    void SetModel(cLoadModels& playerModel) override;
    void MoveAlongCurve(float deltaTime) override;
    void Shoot(float deltaTime, IProjectile* projectile) override;
    void TakeHit(float deltaTime) override;
    bool IsDestroyed(float deltaTime) override ;
    glm::vec3 GetPosition() override;
    void SetPosition(glm::vec3 position) override;    
    float GetSpeed() override;
    void SetSpeed(float speed) override;
private:
    float speed = 1.0f;

    cLoadModels mothGreenAlienModel;
    glm::vec3 mothGreenAlienPosition;
};