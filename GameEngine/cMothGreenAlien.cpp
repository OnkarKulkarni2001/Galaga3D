#include "cMothGreenAlien.h"
#include "cGalaga3D.h"

cLoadModels cMothGreenAlien::GetModel()
{
    return mothGreenAlienModel;
}

void cMothGreenAlien::SetModel(cLoadModels& playerModel)
{
    this->mothGreenAlienModel = playerModel;
}

void cMothGreenAlien::MoveAlongCurve(float deltaTime)
{
    mothGreenAlienPosition -= deltaTime * speed * glm::vec3(0.0, 1.0, 0.0);
    mothGreenAlienModel.pMeshTransform.x = mothGreenAlienPosition.x;
    mothGreenAlienModel.pMeshTransform.y = mothGreenAlienPosition.y;
    mothGreenAlienModel.pMeshTransform.z = mothGreenAlienPosition.z;
}

void cMothGreenAlien::Shoot(float deltaTime, IProjectile* projectile)
{
    //projectile->SetPosition(glm::vec3(mothGreenAlienPosition.x, mothGreenAlienPosition.y + 170.0f, mothGreenAlienPosition.z));
    projectile->Fire(deltaTime);
}

void cMothGreenAlien::TakeHit(float deltaTime)
{
}

bool cMothGreenAlien::IsDestroyed(float deltaTime)
{
    return false;
}

glm::vec3 cMothGreenAlien::GetPosition()
{
    return mothGreenAlienPosition;
}

void cMothGreenAlien::SetPosition(glm::vec3 position)
{
    this->mothGreenAlienPosition = position;
    mothGreenAlienModel.position = mothGreenAlienPosition;
}

float cMothGreenAlien::GetSpeed()
{
    return speed;
}

void cMothGreenAlien::SetSpeed(float speed)
{
    this->speed = speed;
}
