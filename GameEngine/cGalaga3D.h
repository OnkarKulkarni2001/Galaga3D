#pragma once
#include "IGalagaFactory.h"
#include "cLoadModels.h"
#include "cScene.h"
#include "cRenderModel.h"
#include "cVAOManager.h"
#include "cPhysicsUpdated.h"
#include <vector>

class cGalaga3D {
public:
	float bulletSpeed = 0.01f;
	float ROOM_SIZE = 2500.0f;

	float spacing = 270.0f;
	float startPositionX = -ROOM_SIZE / 2.0f;

	float currentTime;
	float lastFireTime;
	float fireInterval;

	int enemyProjectileIndex;

	int hitCount = 0;
	int numberOfLives = 3;

	std::vector<int> projectilesToDelete;
	//std::vector<int> enemiesToDelete;
	std::vector<int> mothEnemiesToDelete;
	std::vector<int> beeEnemiesToDelete;
	std::vector<int> butterflyEnemiesToDelete;
	//std::vector<IAlienAi*> vecEnemies;

	std::vector<IAlienAi*> vecBeeAliens;
	std::vector<IAlienAi*> vecButterflyAliens;
	std::vector<IAlienAi*> vecMothAliens;

	std::vector<IProjectile*> vecPlayerProjectiles;
	std::vector<IProjectile*> vecEnemyProjectiles;
	std::vector<cLoadModels> vecStars;

	cScene playerShipWhite;
	cScene playerShipRed;
	cScene alienShip_A;
	cScene alienShip_B;
	cScene alienShip_C;
	cScene playerExplosion;
	cScene alienExplosion;
	cScene projectile_A;
	cScene projectile_B;
	cScene alienBee_BlueWings;
	cScene alienBee_RedWings;
	cScene alienMothGreen;
	cScene alienMothBlue;
	cScene alienScorpion;
	cScene alienDragonfly;
	cScene alienShipGreen;
	cScene tractorBeam;
	cScene award;
	cScene star;

	GLuint shaderProgram;

	cRenderModel galagaRenderer;

	IPlayerShip* playerShip = nullptr;
	IAlienAi* beeAlien = nullptr;
	IAlienAi* butterflyAlien = nullptr;
	IAlienAi* mothGreenAlien = nullptr;
	IAlienAi* mothBlueAlien = nullptr;
	IProjectile* playerProjectile = nullptr;
	IProjectile* enemyProjectile = nullptr;
	IAnimation* enemyExplosionAnimation = nullptr;
	IAnimation* playerExplosionAnimation = nullptr;
	IAnimation* tractorBeamAnimation = nullptr;

	IGalagaFactory* pGalagaFactory = nullptr;
	cVAOManager* pVAOManager = nullptr;
	cPhysicsUpdated* pGalagaPhysics = nullptr;

	void InitializeGalaga(IGalagaFactory* pGalagaFactory, GLuint shaderProgram, cVAOManager& VAOManager);
	void SetupGalaga();
	void Tick(GLFWwindow* window, float deltaTime);
	void PopulateEnemies();
	void GalagaControls(GLFWwindow* window, float deltaTime);
	void InitializePlayerProjectiles();
	void InitializeEnemyProjectiles();

	void CheckCollision_Between_MothAlien_PlayerProjectile();
	void CheckCollision_Between_BeeAlien_PlayerProjectile();
	void CheckCollision_Between_ButterflyAlien_PlayerProjectile();
	void CheckCollision_Between_AlienProjectile_Player();

	int RandomInt(int min, int max);
	float RandomFloat(float min, float max);
	void GenerateRandomCoordinates(float& x, float& y, float& z);
};