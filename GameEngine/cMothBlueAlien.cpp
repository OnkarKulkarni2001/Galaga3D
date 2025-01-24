#include "cMothBlueAlien.h"

cLoadModels cMothBlueAlien::GetModel()
{
    return mothBlueAlienModel;
}

void cMothBlueAlien::SetModel(cLoadModels& playerModel)
{
    this->mothBlueAlienModel = playerModel;
}

void cMothBlueAlien::MoveAlongCurve(float deltaTime)
{
    mothBlueAlienPosition -= deltaTime * speed * glm::vec3(0.0, 1.0, 0.0);
    mothBlueAlienModel.pMeshTransform.x = mothBlueAlienPosition.x;
    mothBlueAlienModel.pMeshTransform.y = mothBlueAlienPosition.y;
    mothBlueAlienModel.pMeshTransform.z = mothBlueAlienPosition.z;
}

void cMothBlueAlien::Shoot(float deltaTime, IProjectile* projectile)
{
    //projectile->SetPosition(glm::vec3(mothBlueAlienPosition.x, mothBlueAlienPosition.y + 170.0f, mothBlueAlienPosition.z));
    projectile->Fire(deltaTime);
}

void cMothBlueAlien::TakeHit(float deltaTime)
{
}

bool cMothBlueAlien::IsDestroyed(float deltaTime)
{
    return false;
}

glm::vec3 cMothBlueAlien::GetPosition()
{
    return mothBlueAlienPosition;
}

void cMothBlueAlien::SetPosition(glm::vec3 position)
{
    this->mothBlueAlienPosition = position;
    mothBlueAlienModel.position = mothBlueAlienPosition;
}

float cMothBlueAlien::GetSpeed()
{
    return speed;
}

void cMothBlueAlien::SetSpeed(float speed)
{
    this->speed = speed;
}
