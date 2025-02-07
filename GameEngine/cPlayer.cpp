#include "cPlayer.h"

cPlayer::cPlayer()
{
    playerHealth = 150.0f;
    playerSpeed = 0.01f;
    playerForwardVector = glm::vec3(0.0f, 0.0f, 1.0f);		// will be looking in z direction
    playerRightVector = glm::vec3(1.0f, 0.0f, 0.0f);		// will be in x direction
    playerUpVector = glm::vec3(0.0f, 1.0f, 0.0f);			// will be in y direction
}

cPlayer::cPlayer(cLoadModels& playerModel)
{
    playerHealth = 150.0f;
    playerSpeed = 0.01f;
    this->playerModel = &playerModel;
    playerLocation = glm::vec3(playerModel.pMeshTransform.x, playerModel.pMeshTransform.y, playerModel.pMeshTransform.z);
    playerForwardVector = glm::vec3 (0.0f, 0.0f, 1.0f);		// will be looking in z direction
    playerRightVector = glm::vec3 (1.0f, 0.0f, 0.0f);		// will be in x direction
    playerUpVector = glm::vec3 (0.0f, 1.0f, 0.0f);			// will be in y direction
}

cPlayer::~cPlayer()
{

}

void cPlayer::MoveForward(float deltaTime)
{
    playerLocation += deltaTime * playerSpeed * playerForwardVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::MoveBackward(float deltaTime)
{
    playerLocation -= deltaTime * playerSpeed * playerForwardVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::MoveLeft(float deltaTime)
{
    playerLocation -= deltaTime * playerSpeed * playerRightVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::MoveRight(float deltaTime)
{
    playerLocation += deltaTime * playerSpeed * playerRightVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::MoveUp(float deltaTime)
{
    playerLocation += deltaTime * playerSpeed * playerUpVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::MoveDown(float deltaTime)
{
    playerLocation -= deltaTime * playerSpeed * playerUpVector;
    playerModel->pMeshTransform.x = playerLocation.x;
    playerModel->pMeshTransform.y = playerLocation.y;
    playerModel->pMeshTransform.z = playerLocation.z;
}

void cPlayer::Jump()
{
    // TODO
}

void cPlayer::Fire(cLoadModels bulletModel)
{
    // TODO: Implement fire logic
    bulletModel.position = playerLocation;
    bulletModel.position.y = playerLocation.y + 170.0f;
    std::cout << "BulletPos: " << bulletModel.position.x << " " << bulletModel.position.y << " " << bulletModel.position.z << std::endl;
}

void cPlayer::DecreaseHealth(float value)
{
    playerHealth -= value;
}

void cPlayer::IncreaseHealth(float value)
{
    playerHealth += value;
}


// Getters
double cPlayer::GetHealth()
{
    return playerHealth;
}

glm::vec3 cPlayer::GetLocation()
{
    return playerLocation;
}

void cPlayer::GetWeapon()
{
    // TODO: Implement struct
}

float cPlayer::GetSpeed()
{
    return playerSpeed;
}

glm::vec3 cPlayer::GetForwardVector()
{
    return playerForwardVector;
}

glm::vec3 cPlayer::GetRightVector()
{
    return playerRightVector;
}

glm::vec3 cPlayer::GetUpVector()
{
    return playerUpVector;
}


// Setters
void cPlayer::SetHealth(float value)
{
    playerHealth = value;
}

void cPlayer::SetLocation(float x, float y, float z)
{
    playerLocation = glm::vec3(x, y, z);
}

void cPlayer::SetWeapon()
{
    // TODO: Implement struct for this
}

void cPlayer::SetSpeed(float value)
{
    playerSpeed = value;
}

void cPlayer::SetForwardVector(float x, float y, float z)
{
    playerForwardVector = glm::vec3(x, y, z);
}

void cPlayer::SetRightVector(float x, float y, float z)
{
    playerRightVector = glm::vec3(x, y, z);
}

void cPlayer::SetUpVector(float x, float y, float z)
{
    playerUpVector = glm::vec3(x, y, z);
}

bool cPlayer::IsDead()
{
    if (playerHealth <= 0)
        return true;
    return false;
}