#include "cButterflyAlien.h"

cLoadModels cButterflyAlien::GetModel()
{
    return butterflyEnemyModel;
}

void cButterflyAlien::SetModel(cLoadModels& playerModel)
{
    this->butterflyEnemyModel = playerModel;
}

void cButterflyAlien::MoveAlongCurve(float deltaTime)
{
    butterflyPosition -= deltaTime * speed * glm::vec3(0.0, 1.0, 0.0);
    butterflyEnemyModel.pMeshTransform.x = butterflyPosition.x;
    butterflyEnemyModel.pMeshTransform.y = butterflyPosition.y;
    butterflyEnemyModel.pMeshTransform.z = butterflyPosition.z;
}

void cButterflyAlien::Shoot(float deltaTime, IProjectile* projectile)
{
    //projectile->SetPosition(glm::vec3(butterflyPosition.x, butterflyPosition.y + 170.0f, butterflyPosition.z));
    projectile->Fire(deltaTime);
}

void cButterflyAlien::TakeHit(float deltaTime)
{
}

bool cButterflyAlien::IsDestroyed(float deltaTime)
{
    return false;
}

glm::vec3 cButterflyAlien::GetPosition()
{
    return butterflyPosition;
}

void cButterflyAlien::SetPosition(glm::vec3 position)
{
    this->butterflyPosition = position;
    butterflyEnemyModel.position = butterflyPosition;
}

float cButterflyAlien::GetSpeed()
{
    return speed;
}

void cButterflyAlien::SetSpeed(float speed)
{
    this->speed = speed;
}
