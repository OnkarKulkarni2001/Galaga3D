#include "cPlayerShipB.h"
#include "cPlayerProjectile.h"

cLoadModels* cPlayerShipB::GetModel()
{
    return &playerModel;
}

void cPlayerShipB::SetModel(cLoadModels& playerModel)
{
    this->playerModel = playerModel;
}

void cPlayerShipB::MoveLeft(float deltaTime)
{
    playerPosition.x -= deltaTime * speed;
    playerModel.pMeshTransform.x = playerPosition.x;
    playerModel.pMeshTransform.y = playerPosition.y;
    playerModel.pMeshTransform.z = playerPosition.z;
}

void cPlayerShipB::MoveRight(float deltaTime)
{
    playerPosition.x += deltaTime * speed;
    playerModel.pMeshTransform.x = playerPosition.x;
    playerModel.pMeshTransform.y = playerPosition.y;
    playerModel.pMeshTransform.z = playerPosition.z;
}

void cPlayerShipB::Shoot(float deltaTime, IProjectile* projectile)
{
    /*cPlayerProjectile projectile;
    projectile.SetModel(model);
    int i = playerPosition.y + 170.0f;
    projectile.SetPosition(glm::vec3(0.0, i * projectile.GetSpeed() * deltaTime, 0.0));
    i++;*/
    projectile->Fire(deltaTime);
}

void cPlayerShipB::TakeHit(float deltaTime)
{
}

glm::vec3 cPlayerShipB::GetPosition()
{
    return playerPosition;
}

void cPlayerShipB::SetPosition(glm::vec3 position)
{
    this->playerPosition = position;
    playerModel.position = this->playerPosition;
}

float cPlayerShipB::GetSpeed()
{
    return speed;
}

void cPlayerShipB::SetSpeed(float speed)
{
    this->speed = speed;
}
