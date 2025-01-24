#include "cAiEnemy.h"

cAiEnemy::cAiEnemy()
{
    enemyHealth = 150.0f;
    enemySpeed = 0.02f;
    enemyForwardVector = glm::vec3(0.0f, 0.0f, 1.0f);		// will be looking in z direction
    enemyRightVector = glm::vec3(1.0f, 0.0f, 0.0f);		// will be in x direction
    enemyUpVector = glm::vec3(0.0f, 1.0f, 0.0f);			// will be in y direction
}

cAiEnemy::cAiEnemy(cLoadModels& enemyModel)
{
    enemyHealth = 150.0f;
    enemySpeed = 0.02f;
    this->enemyModel = &enemyModel;
    enemyLocation = glm::vec3(enemyModel.pMeshTransform.x, enemyModel.pMeshTransform.y, enemyModel.pMeshTransform.z);
    enemyForwardVector = glm::vec3(0.0f, 0.0f, 1.0f);		// will be looking in z direction
    enemyRightVector = glm::vec3(1.0f, 0.0f, 0.0f);		// will be in x direction
    enemyUpVector = glm::vec3(0.0f, 1.0f, 0.0f);			// will be in y direction
}

cAiEnemy::~cAiEnemy()
{
}

void cAiEnemy::MoveForward(float deltaTime)
{
    enemyLocation += deltaTime * enemySpeed * enemyForwardVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::MoveBackward(float deltaTime)
{
    enemyLocation -= deltaTime * enemySpeed * enemyForwardVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::MoveLeft(float deltaTime)
{
    enemyLocation -= deltaTime * enemySpeed * enemyRightVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::MoveRight(float deltaTime)
{
    enemyLocation += deltaTime * enemySpeed * enemyRightVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::MoveUp(float deltaTime)
{
    enemyLocation += deltaTime * enemySpeed * enemyUpVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::MoveDown(float deltaTime)
{
    enemyLocation -= deltaTime * enemySpeed * enemyUpVector;
    enemyModel->pMeshTransform.x = enemyLocation.x;
    enemyModel->pMeshTransform.y = enemyLocation.y;
    enemyModel->pMeshTransform.z = enemyLocation.z;
}

void cAiEnemy::Jump()
{
    // TODO
}

void cAiEnemy::Fire(cLoadModels bulletModel)
{
    // TODO: Implement fire logic
    bulletModel.position = enemyLocation;
    bulletModel.position.y = enemyLocation.y + 170.0f;
    std::cout << "BulletPos: " << bulletModel.position.x << " " << bulletModel.position.y << " " << bulletModel.position.z << std::endl;
}

void cAiEnemy::DecreaseHealth(float value)
{
    enemyHealth -= value;
}

void cAiEnemy::IncreaseHealth(float value)
{
    enemyHealth += value;
}


// Getters
double cAiEnemy::GetHealth()
{
    return enemyHealth;
}

glm::vec3 cAiEnemy::GetLocation()
{
    return enemyLocation;
}

void cAiEnemy::GetWeapon()
{
    // TODO: Implement struct
}

float cAiEnemy::GetSpeed()
{
    return enemySpeed;
}

glm::vec3 cAiEnemy::GetForwardVector()
{
    return enemyForwardVector;
}

glm::vec3 cAiEnemy::GetRightVector()
{
    return enemyRightVector;
}

glm::vec3 cAiEnemy::GetUpVector()
{
    return enemyUpVector;
}


// Setters
void cAiEnemy::SetHealth(float value)
{
    enemyHealth = value;
}

void cAiEnemy::SetLocation(float x, float y, float z)
{
    enemyLocation = glm::vec3(x, y, z);
}

void cAiEnemy::SetWeapon()
{
    // TODO: Implement struct for this
}

void cAiEnemy::SetSpeed(float value)
{
    enemySpeed = value;
}

void cAiEnemy::SetForwardVector(float x, float y, float z)
{
    enemyForwardVector = glm::vec3(x, y, z);
}

void cAiEnemy::SetRightVector(float x, float y, float z)
{
    enemyRightVector = glm::vec3(x, y, z);
}

void cAiEnemy::SetUpVector(float x, float y, float z)
{
    enemyUpVector = glm::vec3(x, y, z);
}

bool cAiEnemy::IsDead()
{
    if (enemyHealth <= 0)
        return true;
    return false;
}