#pragma once
#include "cPlayerShipA.h"
#include "cPlayerProjectile.h"

cLoadModels* cPlayerShipA::GetModel()
{
	return &playerModel;
}

void cPlayerShipA::SetModel(cLoadModels& playerModel)
{
	this->playerModel = playerModel;
}

void cPlayerShipA::MoveLeft(float deltaTime) {
	playerPosition.x -= deltaTime * speed;
	playerModel.pMeshTransform.x = playerPosition.x;
	playerModel.pMeshTransform.y = playerPosition.y;
	playerModel.pMeshTransform.z = playerPosition.z;
}

void cPlayerShipA::MoveRight(float deltaTime) {
	playerPosition.x += deltaTime * speed;
	playerModel.pMeshTransform.x = playerPosition.x;
	playerModel.pMeshTransform.y = playerPosition.y;
	playerModel.pMeshTransform.z = playerPosition.z;
}

void cPlayerShipA::Shoot(float deltaTime, IProjectile* projectile) {
	//cPlayerProjectile projectile;
	//projectile.SetModel(model);
	//int i = playerPosition.y + 170.0f;
	//projectile.SetPosition(glm::vec3(0.0, i * projectile.GetSpeed() * deltaTime, 0.0));
	//i++;
	//bulletModel.position = playerLocation;
	//bulletModel.position.y = playerLocation.y + 170.0f;
	projectile->SetPosition(glm::vec3(playerPosition.x, playerPosition.y + 170.0f, playerPosition.z));
	projectile->Fire(deltaTime);
}

void cPlayerShipA::TakeHit(float deltaTime)
{
}

glm::vec3 cPlayerShipA::GetPosition()
{
	return playerPosition;
}

void cPlayerShipA::SetPosition(glm::vec3 position)
{
	this->playerPosition = position;
	playerModel.position = this->playerPosition;
}

float cPlayerShipA::GetSpeed()
{
	return speed;
}

void cPlayerShipA::SetSpeed(float speed)
{
	this->speed = speed;
}
