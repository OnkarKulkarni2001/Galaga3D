#pragma once
#include "IPlayer.h"
#include "cPlayer.h"
#include "cAiEnemy.h"
#include "cScene.h"
#include "cLoadModels.h"
#include "cRenderModel.h"
#include <vector>
#include "cPhysicsUpdated.h"

class cGalaga {
public:
	cGalaga(cScene& scene, cRenderModel renderer, GLuint shaderProgram);
	~cGalaga();

	void GalagaControls(GLFWwindow* window, float deltaTime);
	//void Fire(cLoadModels bulletModel);
	void SetupGalaga3D(float deltaTime);
	void GalagaTick(float deltaTime);
	void PopulateEnemies();

	int RandomInt(int min, int max);
	float RandomFloat(float min, float max);
	void GenerateRandomCoordinates(float& x, float& y, float& z);

private:
	GLuint shaderProgram;
	cRenderModel renderer;
	std::vector<cLoadModels> vecGameModels;
	std::vector<cLoadModels> vecPlayerProjectiles;			// Need to check collisions
	std::vector<cLoadModels> vecAlienProjectiles;			// Need to check collisions
	std::vector<cLoadModels> vecStars;
	std::vector<cLoadModels> vecAlienExplosionAnimations;
	std::vector<cLoadModels> vecPlayerExplosionAnimations;

	std::vector<cAiEnemy> vecBeeAliens;
	std::vector<cAiEnemy> vecButterflyAliens;
	std::vector<cAiEnemy> vecMothGreenAliens;
	std::vector<cAiEnemy> vecMothBlueAliens;
	std::vector<cAiEnemy> vecEnemies;						// Need to check collisions

	bool enemiesInitialized;

	float bulletSpeed = 0.01f;
	float ROOM_SIZE = 2500.0f;

	float spacing = 270.0f;
	float startPositionX = -ROOM_SIZE / 2.0f;

	float lastFireTime;
	float fireInterval;

	int playerProjectileIndex;
	int enemyIndex;

	cPlayer playerShip;
	cPhysicsUpdated* pGalagaPhysics = nullptr;
};