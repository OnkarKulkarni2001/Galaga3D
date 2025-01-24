#include "IGalagaFactory.h"
#include "cGalaga3D.h"
#include "cScene.h"
#include <algorithm>

void cGalaga3D::InitializeGalaga(IGalagaFactory* pGalagaFactory, GLuint shaderProgram, cVAOManager& VAOManager) {
	this->shaderProgram = shaderProgram;
	this->pVAOManager = &VAOManager;
	this->pGalagaPhysics = new cPhysicsUpdated();
	this->pGalagaFactory = pGalagaFactory;

	// Creating all components
	playerShip = pGalagaFactory->CreatePlayerShip(ePlayerType::PLAYER_SHIP_A);
	beeAlien = pGalagaFactory->CreateAlien(eAlienType::BEE);
	butterflyAlien = pGalagaFactory->CreateAlien(eAlienType::BUTTERFLY);
	mothGreenAlien = pGalagaFactory->CreateAlien(eAlienType::MOTH_GREEN);
	mothBlueAlien = pGalagaFactory->CreateAlien(eAlienType::MOTH_BLUE);
	playerProjectile = pGalagaFactory->CreateProjectile(eProjectileType::PLAYER_PROJECTILE);
	enemyProjectile = pGalagaFactory->CreateProjectile(eProjectileType::ENEMY_PROJECTILE);
	enemyExplosionAnimation = pGalagaFactory->CreateExplosion(eExplosionType::ENEMY_EXPLOSION);
	playerExplosionAnimation = pGalagaFactory->CreateExplosion(eExplosionType::PLAYER_EXPLOSION);
	//tractorBeamAnimation = pGalagaFactory->CreateTractorBeam();

	playerShipWhite.CreateScene("../components/PlayerShipWhite.txt");
	playerShipRed.CreateScene("../components/PlayerShipRed.txt");
	alienShip_A.CreateScene("../components/AlienShip_A.txt");
	alienShip_B.CreateScene("../components/AlienShip_B.txt");
	alienShip_C.CreateScene("../components/AlienShip_C.txt");
	playerExplosion.CreateScene("../components/Ship_Explosion.txt");
	alienExplosion.CreateScene("../components/Alien_Explosion.txt");
	projectile_A.CreateScene("../components/projectile_A.txt");
	projectile_B.CreateScene("../components/projectile_B.txt");
	alienBee_BlueWings.CreateScene("../components/AlienBee_BlueWings.txt");
	alienBee_RedWings.CreateScene("../components/AlienBee_RedWings.txt");
	alienMothGreen.CreateScene("../components/AlienMothGreen.txt");
	alienMothBlue.CreateScene("../components/AlienMothBlue.txt");
	alienScorpion.CreateScene("../components/AlienScorpion.txt");
	alienDragonfly.CreateScene("../components/AlienDragonfly.txt");
	alienShipGreen.CreateScene("../components/AlienShip_Green.txt");
	tractorBeam.CreateScene("../components/Tractor_Beam.txt");
	award.CreateScene("../components/Award.txt");
	star.CreateScene("../components/Star.txt");

	// Getting model ready to render with creating model matrix, setting up VAO and physics as well
	for (int i = 0; i != playerShipWhite.pModels.size(); i++) {
		playerShipWhite.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[playerShipWhite.pModels[i].numberOfVertices];
		glm::mat4 model = playerShipWhite.pModels[i].CreateModelMatrix(shaderProgram, playerShipWhite.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		playerShipWhite.pModels[i].GenerateTransformedVertices(model);
		
		pVAOManager->GettingModelReadyToRender(playerShipWhite.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(playerShipWhite.pModels[i]);
	}
	for (int i = 0; i != playerShipRed.pModels.size(); i++) {
		playerShipRed.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[playerShipRed.pModels[i].numberOfVertices];
		glm::mat4 model = playerShipRed.pModels[i].CreateModelMatrix(shaderProgram, playerShipRed.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		playerShipRed.pModels[i].GenerateTransformedVertices(model);
		
		pVAOManager->GettingModelReadyToRender(playerShipRed.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(playerShipRed.pModels[i]);
	}
	for (int i = 0; i != alienShip_A.pModels.size(); i++) {
		alienShip_A.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienShip_A.pModels[i].numberOfVertices];
		glm::mat4 model = alienShip_A.pModels[i].CreateModelMatrix(shaderProgram, alienShip_A.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienShip_A.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienShip_A.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienShip_A.pModels[i]);
	}
	for (int i = 0; i != alienShip_B.pModels.size(); i++) {
		alienShip_B.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienShip_B.pModels[i].numberOfVertices];
		glm::mat4 model = alienShip_B.pModels[i].CreateModelMatrix(shaderProgram, alienShip_B.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienShip_B.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienShip_B.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienShip_B.pModels[i]);
	}
	for (int i = 0; i != alienShip_C.pModels.size(); i++) {
		alienShip_C.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienShip_C.pModels[i].numberOfVertices];
		glm::mat4 model = alienShip_C.pModels[i].CreateModelMatrix(shaderProgram, alienShip_C.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienShip_C.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienShip_C.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienShip_C.pModels[i]);
	}
	for (int i = 0; i != playerExplosion.pModels.size(); i++) {
		playerExplosion.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[playerExplosion.pModels[i].numberOfVertices];
		glm::mat4 model = playerExplosion.pModels[i].CreateModelMatrix(shaderProgram, playerExplosion.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		playerExplosion.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(playerExplosion.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(playerExplosion.pModels[i]);
	}
	for (int i = 0; i != alienExplosion.pModels.size(); i++) {
		alienExplosion.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienExplosion.pModels[i].numberOfVertices];
		glm::mat4 model = alienExplosion.pModels[i].CreateModelMatrix(shaderProgram, alienExplosion.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienExplosion.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienExplosion.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienExplosion.pModels[i]);
	}
	for (int i = 0; i != projectile_A.pModels.size(); i++) {
		projectile_A.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[projectile_A.pModels[i].numberOfVertices];
		glm::mat4 model = projectile_A.pModels[i].CreateModelMatrix(shaderProgram, projectile_A.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		projectile_A.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(projectile_A.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(projectile_A.pModels[i]);
	}
	for (int i = 0; i != projectile_B.pModels.size(); i++) {
		projectile_B.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[projectile_B.pModels[i].numberOfVertices];
		glm::mat4 model = projectile_B.pModels[i].CreateModelMatrix(shaderProgram, projectile_B.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		projectile_B.pModels[i].GenerateTransformedVertices(model);
		
		pVAOManager->GettingModelReadyToRender(projectile_B.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(projectile_B.pModels[i]);
	}
	for (int i = 0; i != alienBee_BlueWings.pModels.size(); i++) {
		alienBee_BlueWings.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienBee_BlueWings.pModels[i].numberOfVertices];
		glm::mat4 model = alienBee_BlueWings.pModels[i].CreateModelMatrix(shaderProgram, alienBee_BlueWings.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienBee_BlueWings.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienBee_BlueWings.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienBee_BlueWings.pModels[i]);
	}
	for (int i = 0; i != alienBee_RedWings.pModels.size(); i++) {
		alienBee_RedWings.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienBee_RedWings.pModels[i].numberOfVertices];
		glm::mat4 model = alienBee_RedWings.pModels[i].CreateModelMatrix(shaderProgram, alienBee_RedWings.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienBee_RedWings.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienBee_RedWings.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienBee_RedWings.pModels[i]);
	}
	for (int i = 0; i != alienMothGreen.pModels.size(); i++) {
		alienMothGreen.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienMothGreen.pModels[i].numberOfVertices];
		glm::mat4 model = alienMothGreen.pModels[i].CreateModelMatrix(shaderProgram, alienMothGreen.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienMothGreen.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienMothGreen.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienMothGreen.pModels[i]);
	}
	for (int i = 0; i != alienMothBlue.pModels.size(); i++) {
		alienMothBlue.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienMothBlue.pModels[i].numberOfVertices];
		glm::mat4 model = alienMothBlue.pModels[i].CreateModelMatrix(shaderProgram, alienMothBlue.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienMothBlue.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienMothBlue.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienMothBlue.pModels[i]);
	}
	for (int i = 0; i != alienScorpion.pModels.size(); i++) {
		alienScorpion.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienScorpion.pModels[i].numberOfVertices];
		glm::mat4 model = alienScorpion.pModels[i].CreateModelMatrix(shaderProgram, alienScorpion.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienScorpion.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienScorpion.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienScorpion.pModels[i]);
	}
	for (int i = 0; i != alienDragonfly.pModels.size(); i++) {
		alienDragonfly.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienDragonfly.pModels[i].numberOfVertices];
		glm::mat4 model = alienDragonfly.pModels[i].CreateModelMatrix(shaderProgram, alienDragonfly.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienDragonfly.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienDragonfly.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienDragonfly.pModels[i]);
	}
	for (int i = 0; i != alienShipGreen.pModels.size(); i++) {
		alienShipGreen.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[alienShipGreen.pModels[i].numberOfVertices];
		glm::mat4 model = alienShipGreen.pModels[i].CreateModelMatrix(shaderProgram, alienShipGreen.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		alienShipGreen.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(alienShipGreen.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(alienShipGreen.pModels[i]);
	}
	for (int i = 0; i != tractorBeam.pModels.size(); i++) {
		tractorBeam.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[tractorBeam.pModels[i].numberOfVertices];
		glm::mat4 model = tractorBeam.pModels[i].CreateModelMatrix(shaderProgram, tractorBeam.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		tractorBeam.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(tractorBeam.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(tractorBeam.pModels[i]);
	}
	for (int i = 0; i != award.pModels.size(); i++) {
		award.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[award.pModels[i].numberOfVertices];
		glm::mat4 model = award.pModels[i].CreateModelMatrix(shaderProgram, award.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		award.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(award.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(award.pModels[i]);
	}
	for (int i = 0; i != star.pModels.size(); i++) {
		star.pModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[star.pModels[i].numberOfVertices];
		glm::mat4 model = star.pModels[i].CreateModelMatrix(shaderProgram, star.pModels[i]);      // Creation of model matrix with arguements passed in sceneFile.txt
		star.pModels[i].GenerateTransformedVertices(model);

		pVAOManager->GettingModelReadyToRender(star.pModels[i]);         // This thing is new just because I created whole new VAO thing which creates several different VAOs and now I can render a single model multiple times
		pGalagaPhysics->CalculateBoundingSpheres(star.pModels[i]);
	}

	//vecEnemies.clear();		// Clearing the vecEnemies vector so that it doesn't store junk and which will be used to store rendered enemies in it
	vecMothAliens.clear();
	vecBeeAliens.clear();
	vecButterflyAliens.clear();
	projectilesToDelete.clear();
	//enemiesToDelete.clear();
	mothEnemiesToDelete.clear();
	beeEnemiesToDelete.clear();
	butterflyEnemiesToDelete.clear();
}

void cGalaga3D::SetupGalaga()
{
	numberOfLives = 3;
	playerProjectile->SetModel(projectile_A.pModels[0]);
	playerProjectile->SetSpeed(100.0f);
	playerShip->SetModel(playerShipWhite.pModels[0]);
	playerShip->GetModel()->position.y = -ROOM_SIZE + 1;
	playerShip->SetPosition(playerShip->GetModel()->position);
	playerShip->SetSpeed(790.0f);

	// Populating Stars
	for (int i = 0; i != 50; i++) {             // 50 stars
		vecStars.push_back(star.pModels.back());
		GenerateRandomCoordinates(vecStars[i].position.x, vecStars[i].position.y, vecStars[i].position.z);
	}
}

void cGalaga3D::Tick(GLFWwindow* window, float deltaTime)
{

	GalagaControls(window, deltaTime);

	// Rendering Player
	if (playerShip != nullptr) {
		galagaRenderer.DrawMesh(playerShip->GetModel(), playerShip->GetPosition(), shaderProgram);
	}
	// Rendering Player Projectiles
	if (vecPlayerProjectiles.size() > 0) {
		for (int i = 0; i != vecPlayerProjectiles.size(); i++) {
			vecPlayerProjectiles[i]->SetPosition(glm::vec3(vecPlayerProjectiles[i]->GetPosition().x, vecPlayerProjectiles[i]->GetPosition().y + deltaTime * vecPlayerProjectiles[i]->GetSpeed() + 70.0f, vecPlayerProjectiles[i]->GetPosition().z));
			cLoadModels projectileMesh = vecPlayerProjectiles[i]->GetModel();			// Needed to do this as it asked me for I-value (Error: & requires I-value)
			pGalagaPhysics->CalculateBoundingSpheres(projectileMesh);
			galagaRenderer.DrawMesh(&projectileMesh, vecPlayerProjectiles[i]->GetPosition(), shaderProgram);
		}
	}

	// Deleting Projectiles which are out of boundary
	for (int i = 0; i != vecPlayerProjectiles.size(); i++) {
		if (vecPlayerProjectiles[i]->GetPosition().y > ROOM_SIZE) {
			delete vecPlayerProjectiles[i];
			vecPlayerProjectiles.erase(vecPlayerProjectiles.begin() + i);
			i--;
		}
	}

	if (vecMothAliens.size() + vecBeeAliens.size() + vecButterflyAliens.size() < 1) {
		PopulateEnemies();
	}
	// Rendering Enemies
	for (int i = 0; i != vecMothAliens.size(); i++) {
		//vecEnemies[i]->SetSpeed(1000.0f);
		//vecEnemies[i]->MoveAlongCurve(deltaTime);
		if (vecMothAliens.size() > 0) {
			vecMothAliens[i]->MoveAlongCurve(deltaTime);
			if (vecMothAliens[i]->GetPosition().y < -ROOM_SIZE) {
				vecMothAliens[i]->SetPosition(glm::vec3(startPositionX + (i % vecMothAliens.size()) * spacing, ROOM_SIZE, 0.0f));    // Setting back all aliens to original position when they cross room boundary
			}
			cLoadModels mothEnemyMesh = vecMothAliens[i]->GetModel();
			pGalagaPhysics->CalculateBoundingSpheres(mothEnemyMesh);
			cLoadModels* pMothEnemyMesh = new cLoadModels(mothEnemyMesh);				// Needed to do this as it asked me for I-value (Error: & requires I-value)
			galagaRenderer.DrawMesh(pMothEnemyMesh, vecMothAliens[i]->GetPosition(), shaderProgram);
		}
	}
	for (int i = 0; i != vecBeeAliens.size(); i++) {
		if (vecBeeAliens.size() > 0) {
			vecBeeAliens[i]->MoveAlongCurve(deltaTime);
			if (vecBeeAliens[i]->GetPosition().y < -ROOM_SIZE) {
				vecBeeAliens[i]->SetPosition(glm::vec3(startPositionX + (i % vecBeeAliens.size()) * spacing, ROOM_SIZE, 0.0f));    // Setting back all aliens to original position when they cross room boundary
			}
			cLoadModels beeEnemyMesh = vecBeeAliens[i]->GetModel();
			pGalagaPhysics->CalculateBoundingSpheres(beeEnemyMesh);
			cLoadModels* pBeeEnemyMesh = new cLoadModels(beeEnemyMesh);				// Needed to do this as it asked me for I-value (Error: & requires I-value)
			galagaRenderer.DrawMesh(pBeeEnemyMesh, vecBeeAliens[i]->GetPosition(), shaderProgram);
		}
	}
	for (int i = 0; i != vecButterflyAliens.size(); i++) {
		if (vecButterflyAliens.size() > 0) {
			vecButterflyAliens[i]->MoveAlongCurve(deltaTime);
			if (vecButterflyAliens[i]->GetPosition().y < -ROOM_SIZE) {
				vecButterflyAliens[i]->SetPosition(glm::vec3(startPositionX + (i % vecButterflyAliens.size()) * spacing, ROOM_SIZE, 0.0f));    // Setting back all aliens to original position when they cross room boundary
			}
			cLoadModels butterflyEnemyMesh = vecButterflyAliens[i]->GetModel();
			pGalagaPhysics->CalculateBoundingSpheres(butterflyEnemyMesh);
			cLoadModels* pButterflyEnemyMesh = new cLoadModels(butterflyEnemyMesh);				// Needed to do this as it asked me for I-value (Error: & requires I-value)
			galagaRenderer.DrawMesh(pButterflyEnemyMesh, vecButterflyAliens[i]->GetPosition(), shaderProgram);
		}
	}

	// Initializing Enemy projectiles
	InitializeEnemyProjectiles();

	// Rendering Enemy Projectiles
	for (int i = 0; i != vecEnemyProjectiles.size(); i++) {
		vecEnemyProjectiles[i]->SetPosition(glm::vec3(vecEnemyProjectiles[i]->GetPosition().x, vecEnemyProjectiles[i]->GetPosition().y - deltaTime * 1000.0f, vecEnemyProjectiles[i]->GetPosition().z));
		vecEnemyProjectiles[i]->SetSpeed(500.0f);
		cLoadModels tempEnemyProjectile = vecEnemyProjectiles[i]->GetModel();
		cLoadModels* pTempEnemeyProjectile = new cLoadModels(tempEnemyProjectile);
		galagaRenderer.DrawMesh(pTempEnemeyProjectile, vecEnemyProjectiles[i]->GetPosition(), shaderProgram);
	}

	// Deleting Enemy Projectiles which are out of boundary
	for (int i = 0; i != vecEnemyProjectiles.size(); i++) {
		if (vecEnemyProjectiles[i]->GetPosition().y < -ROOM_SIZE) {
			delete vecEnemyProjectiles[i];
			vecEnemyProjectiles.erase(vecEnemyProjectiles.begin() + i);
			i--;
		}
	}

	// Rendering Stars
	for (int i = 0; i < vecStars.size(); i++) {
		vecStars[i].position.y -= deltaTime * 150.0f;  // Falling speed
		vecStars[i].pMeshTransform.xScale = 25.0f;
		vecStars[i].pMeshTransform.yScale = 10.0f;
		vecStars[i].pMeshTransform.zScale = 10.0f;

		// Reset star to the top when it goes below the room boundary
		if (vecStars[i].position.y < -ROOM_SIZE) {
			vecStars[i].position.y = RandomFloat(ROOM_SIZE / 2, ROOM_SIZE);  // Reset to the top with some randomness
			vecStars[i].position.x = RandomFloat(-ROOM_SIZE, ROOM_SIZE);  // Randomize x position again
		}
		galagaRenderer.DrawMesh(&vecStars[i], vecStars[i].position, shaderProgram);  // Draw star
	}

	CheckCollision_Between_MothAlien_PlayerProjectile();
	CheckCollision_Between_BeeAlien_PlayerProjectile();
	CheckCollision_Between_ButterflyAlien_PlayerProjectile();
	CheckCollision_Between_AlienProjectile_Player();
}

void cGalaga3D::PopulateEnemies()
{
	if (mothGreenAlien != nullptr && beeAlien != nullptr && butterflyAlien != nullptr) {
		for (int i = 0; i != 10; i++) {
			mothGreenAlien = pGalagaFactory->CreateAlien(eAlienType::MOTH_GREEN);
			beeAlien = pGalagaFactory->CreateAlien(eAlienType::BEE);
			butterflyAlien = pGalagaFactory->CreateAlien(eAlienType::BUTTERFLY);

			mothGreenAlien->SetModel(alienMothGreen.pModels[0]);
			beeAlien->SetModel(alienBee_BlueWings.pModels[0]);
			butterflyAlien->SetModel(alienBee_RedWings.pModels[0]);

			mothGreenAlien->SetSpeed(300.0f);
			beeAlien->SetSpeed(300.0f);
			butterflyAlien->SetSpeed(300.0f);

			mothGreenAlien->SetPosition(glm::vec3(startPositionX + i * spacing, ROOM_SIZE - 1.0f, 0.0f));              // Lineup
			beeAlien->SetPosition(glm::vec3(startPositionX + i * spacing, ROOM_SIZE - 191.0f, 0.0f));
			butterflyAlien->SetPosition(glm::vec3(startPositionX + i * spacing, ROOM_SIZE - 381.0f, 0.0f));

			vecMothAliens.push_back(mothGreenAlien);
			vecBeeAliens.push_back(beeAlien);
			vecButterflyAliens.push_back(butterflyAlien);
		}
	}
}

void cGalaga3D::GalagaControls(GLFWwindow* window, float deltaTime)
{
	if (playerShip != nullptr) {
		if (playerShip->GetPosition().x <= -ROOM_SIZE) {
			playerShip->SetPosition(glm::vec3(-ROOM_SIZE, playerShip->GetPosition().y, playerShip->GetPosition().z));
		}
		if (playerShip->GetPosition().x >= ROOM_SIZE) {
			playerShip->SetPosition(glm::vec3(ROOM_SIZE, playerShip->GetPosition().y, playerShip->GetPosition().z));
		}
		if (playerShip->GetPosition().y >= ROOM_SIZE) {
			playerShip->SetPosition(glm::vec3(playerShip->GetPosition().x, ROOM_SIZE, playerShip->GetPosition().z));
		}
		if (playerShip->GetPosition().y <= -ROOM_SIZE) {
			playerShip->SetPosition(glm::vec3(playerShip->GetPosition().x, -ROOM_SIZE, playerShip->GetPosition().z));
		}
		else {
			if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
				playerShip->MoveRight(deltaTime);
				//std::cout << playerShip->GetPosition().x << " " << playerShip->GetPosition().y << " " << playerShip->GetPosition().z << std::endl;
			}
			if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
				playerShip->MoveLeft(deltaTime);
				//std::cout << playerShip->GetPosition().x << " " << playerShip->GetPosition().y << " " << playerShip->GetPosition().z << std::endl;
			}
			if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
				InitializePlayerProjectiles();
				playerProjectile->Fire(deltaTime);
				vecPlayerProjectiles.push_back(playerProjectile);
			}
		}
	}
}

void cGalaga3D::InitializePlayerProjectiles()
{
	playerProjectile = pGalagaFactory->CreateProjectile(eProjectileType::PLAYER_PROJECTILE);
	playerProjectile->SetModel(projectile_A.pModels[0]);
	playerProjectile->SetPosition(glm::vec3(playerShip->GetPosition().x, playerShip->GetPosition().y, 0.0f));
	playerProjectile->SetSpeed(100.0f);
}

void cGalaga3D::InitializeEnemyProjectiles()
{
	currentTime = glfwGetTime();
	if (currentTime - lastFireTime > fireInterval) {
		lastFireTime = currentTime; // Reset fire time
		fireInterval = RandomFloat(0.6f, 1.6f); // Set a new random interval
		//enemyProjectile->SetPosition(vecEnemies[RandomInt(0, vecEnemies.size())]->GetPosition());
		if (vecMothAliens.size() > 0) {

			enemyProjectile = pGalagaFactory->CreateProjectile(eProjectileType::ENEMY_PROJECTILE);
			enemyProjectile->SetModel(projectile_B.pModels[0]);
			enemyProjectile->SetPosition(vecMothAliens[RandomInt(0, vecMothAliens.size() - 1)]->GetPosition());
			enemyProjectile->SetSpeed(100.0f);

			// Fire projectile
			vecEnemyProjectiles.push_back(enemyProjectile);
		}
		if (vecBeeAliens.size() > 0) {

			enemyProjectile = pGalagaFactory->CreateProjectile(eProjectileType::ENEMY_PROJECTILE);
			enemyProjectile->SetModel(projectile_B.pModels[0]);
			enemyProjectile->SetPosition(vecBeeAliens[RandomInt(0, vecBeeAliens.size() - 1)]->GetPosition());
			enemyProjectile->SetSpeed(100.0f);

			// Fire projectile
			vecEnemyProjectiles.push_back(enemyProjectile);
		}
		if (vecButterflyAliens.size() > 0) {

			enemyProjectile = pGalagaFactory->CreateProjectile(eProjectileType::ENEMY_PROJECTILE);
			enemyProjectile->SetModel(projectile_B.pModels[0]);
			enemyProjectile->SetPosition(vecButterflyAliens[RandomInt(0, vecButterflyAliens.size() - 1)]->GetPosition());
			enemyProjectile->SetSpeed(100.0f);

			// Fire projectile
			vecEnemyProjectiles.push_back(enemyProjectile);
		}
		//else {
		//	delete enemyProjectile;
		//}
	}
}

void cGalaga3D::CheckCollision_Between_MothAlien_PlayerProjectile()
{

	//hitCount = 0;
	for (int playerProjectileIndex = 0; playerProjectileIndex != vecPlayerProjectiles.size(); playerProjectileIndex++) {
		cLoadModels* physicsPlayerProjectile = new cLoadModels(vecPlayerProjectiles[playerProjectileIndex]->GetModel());
		
		glm::mat4 modelMatrix = glm::mat4(1.0f);  // Identity matrix for transformation
		modelMatrix = glm::translate(modelMatrix, vecPlayerProjectiles[playerProjectileIndex]->GetPosition()); // Position sync

		// Apply other transformations if necessary (e.g., rotation, scaling)
		physicsPlayerProjectile->GenerateTransformedVertices(modelMatrix);
		
		pGalagaPhysics->CalculateBoundingSpheres(*physicsPlayerProjectile);

		for (int enemyIndex = 0; enemyIndex != vecMothAliens.size(); enemyIndex++) {
			cLoadModels* physicsEnemy = new cLoadModels(vecMothAliens[enemyIndex]->GetModel());
			
			modelMatrix = glm::mat4(1.0f);  // Reset the identity matrix
			modelMatrix = glm::translate(modelMatrix, vecMothAliens[enemyIndex]->GetPosition()); // Sync position with model

			// Apply any other necessary transformations for the enemy model (e.g., rotation, scaling)
			physicsEnemy->GenerateTransformedVertices(modelMatrix);
			
			pGalagaPhysics->CalculateBoundingSpheres(*physicsEnemy);

			if (pGalagaPhysics->CheckBoundingSphereCollision(physicsPlayerProjectile->modelSphere, physicsEnemy->modelSphere)) {     // Checking collision between player projectiles and enemies		physicsPlayerProjectile.CreateModelMatrix(shaderProgram, physicsPlayerProjectile);

				vecMothAliens[enemyIndex]->SetModel(alienMothBlue.pModels[0]);
				hitCount++;
				if (!(std::count(projectilesToDelete.begin(), projectilesToDelete.end(), playerProjectileIndex) > 0)) {
					projectilesToDelete.push_back(playerProjectileIndex);
				}
				if (hitCount == 2) {
					if (std::count(mothEnemiesToDelete.begin(), mothEnemiesToDelete.end(), enemyIndex) == 0) {
						mothEnemiesToDelete.push_back(enemyIndex);
					}
					hitCount = 0;
				}
				//break;
			}
			delete physicsEnemy;
		}
		delete physicsPlayerProjectile;
	}
	if (projectilesToDelete.size() > 0) {
		for (int i = 0; i != projectilesToDelete.size(); i++) {
			int projectileIndex = projectilesToDelete[i];
			//std::cout << projectileIndex << " projectile to be deleted" << std::endl;

			if (projectileIndex < vecPlayerProjectiles.size()) {
				delete vecPlayerProjectiles[projectileIndex];
				vecPlayerProjectiles[projectileIndex] = nullptr;
				vecPlayerProjectiles.erase(vecPlayerProjectiles.begin() + projectileIndex);
				//projectilesToDelete.erase(projectilesToDelete.begin() + i);
			}
		}
		projectilesToDelete.clear();
	}
	for (int i = 0; i != mothEnemiesToDelete.size(); i++) {
		int enemyIndex = mothEnemiesToDelete[i];

		if (enemyIndex < vecMothAliens.size()) {

			// Render explosion
			for (int i = 0; i != alienExplosion.pModels.size(); i++)
				galagaRenderer.DrawMesh(&alienExplosion.pModels[0], vecMothAliens[enemyIndex]->GetPosition(), shaderProgram);

			delete vecMothAliens[enemyIndex];
			vecMothAliens[enemyIndex] = nullptr;
			vecMothAliens.erase(vecMothAliens.begin() + enemyIndex);
		}
	}
	mothEnemiesToDelete.clear();
}

void cGalaga3D::CheckCollision_Between_BeeAlien_PlayerProjectile()
{
	for (int playerProjectileIndex = 0; playerProjectileIndex != vecPlayerProjectiles.size(); playerProjectileIndex++) {
		cLoadModels* physicsPlayerProjectile = new cLoadModels(vecPlayerProjectiles[playerProjectileIndex]->GetModel());
		
		glm::mat4 modelMatrix = glm::mat4(1.0f);  // Identity matrix for transformation
		modelMatrix = glm::translate(modelMatrix, vecPlayerProjectiles[playerProjectileIndex]->GetPosition()); // Position sync

		// Apply other transformations if necessary (e.g., rotation, scaling)
		physicsPlayerProjectile->GenerateTransformedVertices(modelMatrix);
		
		pGalagaPhysics->CalculateBoundingSpheres(*physicsPlayerProjectile);

		for (int enemyIndex = 0; enemyIndex != vecBeeAliens.size(); enemyIndex++) {
			cLoadModels* physicsEnemy = new cLoadModels(vecBeeAliens[enemyIndex]->GetModel());
			
			modelMatrix = glm::mat4(1.0f);  // Reset the identity matrix
			modelMatrix = glm::translate(modelMatrix, vecBeeAliens[enemyIndex]->GetPosition()); // Sync position with model

			// Apply any other necessary transformations for the enemy model (e.g., rotation, scaling)
			physicsEnemy->GenerateTransformedVertices(modelMatrix);
			
			pGalagaPhysics->CalculateBoundingSpheres(*physicsEnemy);

			if (pGalagaPhysics->CheckBoundingSphereCollision(physicsPlayerProjectile->modelSphere, physicsEnemy->modelSphere)) {     // Checking collision between player projectiles and enemies

				vecBeeAliens[enemyIndex]->TakeHit(1.0f);
				if (!(std::count(projectilesToDelete.begin(), projectilesToDelete.end(), playerProjectileIndex) > 0)) {
					projectilesToDelete.push_back(playerProjectileIndex);
				}
				if (std::count(beeEnemiesToDelete.begin(), beeEnemiesToDelete.end(), enemyIndex) == 0) {
					beeEnemiesToDelete.push_back(enemyIndex);
				}
				break;
			}
		}
	}
	if (projectilesToDelete.size() > 0) {
		for (int i = 0; i != projectilesToDelete.size(); i++) {
			int projectileIndex = projectilesToDelete[i];
			//std::cout << projectileIndex << " projectile to be deleted" << std::endl;

			if (projectileIndex < vecPlayerProjectiles.size()) {
				delete vecPlayerProjectiles[projectileIndex];
				vecPlayerProjectiles[projectileIndex] = nullptr;
				vecPlayerProjectiles.erase(vecPlayerProjectiles.begin() + projectileIndex);
			}
		}
		projectilesToDelete.clear();
	}
	for (int i = 0; i != beeEnemiesToDelete.size(); i++) {
		int enemyIndex = beeEnemiesToDelete[i];

		if (enemyIndex < vecBeeAliens.size()) {

			// Render explosion
			for (int i = 0; i != alienExplosion.pModels.size(); i++)
				galagaRenderer.DrawMesh(&alienExplosion.pModels[0], vecBeeAliens[enemyIndex]->GetPosition(), shaderProgram);

			delete vecBeeAliens[enemyIndex];
			vecBeeAliens[enemyIndex] = nullptr;
			vecBeeAliens.erase(vecBeeAliens.begin() + enemyIndex);
		}
	}
	beeEnemiesToDelete.clear();
}

void cGalaga3D::CheckCollision_Between_ButterflyAlien_PlayerProjectile()
{
	for (int playerProjectileIndex = 0; playerProjectileIndex != vecPlayerProjectiles.size(); playerProjectileIndex++) {
		cLoadModels* physicsPlayerProjectile = new cLoadModels(vecPlayerProjectiles[playerProjectileIndex]->GetModel());
		
		glm::mat4 modelMatrix = glm::mat4(1.0f);  // Identity matrix for transformation
		modelMatrix = glm::translate(modelMatrix, vecPlayerProjectiles[playerProjectileIndex]->GetPosition()); // Position sync

		// Apply other transformations if necessary (e.g., rotation, scaling)
		physicsPlayerProjectile->GenerateTransformedVertices(modelMatrix);
		
		pGalagaPhysics->CalculateBoundingSpheres(*physicsPlayerProjectile);

		for (int enemyIndex = 0; enemyIndex != vecButterflyAliens.size(); enemyIndex++) {
			cLoadModels* physicsEnemy = new cLoadModels(vecButterflyAliens[enemyIndex]->GetModel());
			
			modelMatrix = glm::mat4(1.0f);  // Reset the identity matrix
			modelMatrix = glm::translate(modelMatrix, vecButterflyAliens[enemyIndex]->GetPosition()); // Sync position with model

			// Apply any other necessary transformations for the enemy model (e.g., rotation, scaling)
			physicsEnemy->GenerateTransformedVertices(modelMatrix);
			
			pGalagaPhysics->CalculateBoundingSpheres(*physicsEnemy);

			if (pGalagaPhysics->CheckBoundingSphereCollision(physicsPlayerProjectile->modelSphere, physicsEnemy->modelSphere)) {     // Checking collision between player projectiles and enemies

				if (!(std::count(projectilesToDelete.begin(), projectilesToDelete.end(), playerProjectileIndex) > 0)) {
					projectilesToDelete.push_back(playerProjectileIndex);
				}
				if (std::count(butterflyEnemiesToDelete.begin(), butterflyEnemiesToDelete.end(), enemyIndex) == 0) {
					butterflyEnemiesToDelete.push_back(enemyIndex);
				}
				break;
			}
		}
	}
	if (projectilesToDelete.size() > 0) {
		for (int i = 0; i != projectilesToDelete.size(); i++) {
			int projectileIndex = projectilesToDelete[i];
			//std::cout << projectileIndex << " projectile to be deleted" << std::endl;

			if (projectileIndex < vecPlayerProjectiles.size()) {
				delete vecPlayerProjectiles[projectileIndex];
				vecPlayerProjectiles[projectileIndex] = nullptr;
				vecPlayerProjectiles.erase(vecPlayerProjectiles.begin() + projectileIndex);
			}
		}
		projectilesToDelete.clear();
	}
	for (int i = 0; i != butterflyEnemiesToDelete.size(); i++) {
		int enemyIndex = butterflyEnemiesToDelete[i];

		if (enemyIndex < vecButterflyAliens.size()) {
			// Render explosion
			for(int i = 0; i != alienExplosion.pModels.size(); i++)
				galagaRenderer.DrawMesh(&alienExplosion.pModels[0], vecButterflyAliens[enemyIndex]->GetPosition(), shaderProgram);

			delete vecButterflyAliens[enemyIndex];
			vecButterflyAliens[enemyIndex] = nullptr;
			vecButterflyAliens.erase(vecButterflyAliens.begin() + enemyIndex);
		}
	}
	butterflyEnemiesToDelete.clear();
}

void cGalaga3D::CheckCollision_Between_AlienProjectile_Player()
{
	for (int alienProjectileIndex = 0; alienProjectileIndex != vecEnemyProjectiles.size(); alienProjectileIndex++) {
		cLoadModels* physicsEnemyProjectile = new cLoadModels(vecEnemyProjectiles[alienProjectileIndex]->GetModel());

		glm::mat4 modelMatrix = glm::mat4(1.0f);  // Identity matrix for transformation
		modelMatrix = glm::translate(modelMatrix, vecEnemyProjectiles[alienProjectileIndex]->GetPosition()); // Position sync

		// Apply other transformations if necessary (e.g., rotation, scaling)
		physicsEnemyProjectile->GenerateTransformedVertices(modelMatrix);

		pGalagaPhysics->CalculateBoundingSpheres(*physicsEnemyProjectile);

		if (playerShip != nullptr) {
			cLoadModels* physicsPlayer = new cLoadModels(*playerShip->GetModel());

			modelMatrix = glm::mat4(1.0f);  // Reset the identity matrix
			modelMatrix = glm::translate(modelMatrix, playerShip->GetPosition()); // Sync position with model

			// Apply any other necessary transformations for the enemy model (e.g., rotation, scaling)
			physicsPlayer->GenerateTransformedVertices(modelMatrix);

			pGalagaPhysics->CalculateBoundingSpheres(*physicsPlayer);

			if (pGalagaPhysics->CheckBoundingSphereCollision(physicsEnemyProjectile->modelSphere, physicsPlayer->modelSphere)) {     // Checking collision between player projectiles and enemies

				if (!(std::count(projectilesToDelete.begin(), projectilesToDelete.end(), alienProjectileIndex) > 0)) {
					projectilesToDelete.push_back(alienProjectileIndex);
				}

				// Render explosion
				for (int i = 0; i != playerExplosion.pModels.size(); i++)
					galagaRenderer.DrawMesh(&playerExplosion.pModels[0], playerShip->GetPosition(), shaderProgram);

				numberOfLives--;
				if (numberOfLives > 0) {
					//playerShip = pGalagaFactory->CreatePlayerShip(ePlayerType::PLAYER_SHIP_A);
					playerShip->SetModel(playerShipWhite.pModels[0]);
					playerShip->GetModel()->position.y = -ROOM_SIZE + 1;
					playerShip->SetPosition(playerShip->GetModel()->position);
					playerShip->SetSpeed(790.0f);
				}
				else if(numberOfLives == 0) {
					delete playerShip;
					playerShip = nullptr;
				}
				break;
			}
		}
	}
	if (projectilesToDelete.size() > 0) {
		for (int i = 0; i != projectilesToDelete.size(); i++) {
			int projectileIndex = projectilesToDelete[i];
			//std::cout << projectileIndex << " projectile to be deleted" << std::endl;

			if (projectileIndex < vecEnemyProjectiles.size()) {
				delete vecEnemyProjectiles[projectileIndex];
				vecEnemyProjectiles[projectileIndex] = nullptr;
				vecEnemyProjectiles.erase(vecEnemyProjectiles.begin() + projectileIndex);
			}
		}
		projectilesToDelete.clear();
	}
}

int cGalaga3D::RandomInt(int min, int max) {
	int temp = min + (rand() % (max - min + 1));
	return temp;
}

float cGalaga3D::RandomFloat(float min, float max) {
	float range = max - min;
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / range);
}

void cGalaga3D::GenerateRandomCoordinates(float& x, float& y, float& z) {
	x = RandomFloat(-ROOM_SIZE, ROOM_SIZE);
	y = RandomFloat(-ROOM_SIZE, ROOM_SIZE);
	z = RandomFloat(-ROOM_SIZE, -10);       // Range taken from screenshots of camLocation
}