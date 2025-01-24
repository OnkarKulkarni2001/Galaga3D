#pragma once
#include "IGalaga.h"
#include "cLoadModels.h"

class cPlayerShipB : public IPlayerShip {
public:
    cLoadModels* GetModel() override;
    void SetModel(cLoadModels& playerModel) override;
    void MoveLeft(float deltaTime) override;
    void MoveRight(float deltaTime) override;
    void Shoot(float deltaTime, IProjectile* projectile) override;
    void TakeHit(float deltaTime) override;
    glm::vec3 GetPosition() override;
    void SetPosition(glm::vec3 position) override;
    float GetSpeed() override;
    void SetSpeed(float speed) override;
private:
    float speed = 1.0f;

    cLoadModels playerModel;
    glm::vec3 playerPosition;
};