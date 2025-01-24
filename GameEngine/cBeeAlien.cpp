#include "cBeeAlien.h"

cLoadModels cBeeAlien::GetModel()
{
    return beeEnemyModel;
}

void cBeeAlien::SetModel(cLoadModels& playerModel)
{
    this->beeEnemyModel = playerModel;
}

void cBeeAlien::MoveAlongCurve(float deltaTime)
{
    beePosition -= deltaTime * speed * glm::vec3(0.0, 1.0, 0.0);
    beeEnemyModel.pMeshTransform.x = beePosition.x;
    beeEnemyModel.pMeshTransform.y = beePosition.y;
    beeEnemyModel.pMeshTransform.z = beePosition.z;
}

void cBeeAlien::Shoot(float deltaTime, IProjectile* projectile)
{
    //projectile->SetPosition(glm::vec3(beePosition.x, beePosition.y + 170.0f, beePosition.z));
    projectile->Fire(deltaTime);
}

void cBeeAlien::TakeHit(float deltaTime)
{
}

bool cBeeAlien::IsDestroyed(float deltaTime)
{
    return false;
}

glm::vec3 cBeeAlien::GetPosition()
{
    return beePosition;
}

void cBeeAlien::SetPosition(glm::vec3 position)
{
    this->beePosition = position;
    beeEnemyModel.position = beePosition;
}

float cBeeAlien::GetSpeed()
{
    return speed;
}

void cBeeAlien::SetSpeed(float speed)
{
    this->speed = speed;
}
