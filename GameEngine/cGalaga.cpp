#include "cGalaga.h"

cGalaga::cGalaga(cScene& scene, cRenderModel renderer, GLuint shaderProgram)
{
    for (int i = 0; i != scene.pModels.size(); i++) {
        vecGameModels.push_back(scene.pModels[i]);
        pGalagaPhysics->CalculateAABB(scene.pModels[i]);
    }
    scene.pModels[0].position.y = -ROOM_SIZE + 1;
    playerShip.playerModel = &scene.pModels[0];
    playerShip.SetLocation(scene.pModels[0].position.x, scene.pModels[0].position.y, scene.pModels[0].position.z);
    playerShip.SetSpeed(790.0f);
    this->shaderProgram = shaderProgram;
    this->renderer = renderer;
    enemiesInitialized = false;
    vecEnemies.clear();
}

cGalaga::~cGalaga()
{

}

void cGalaga::GalagaControls(GLFWwindow* window, float deltaTime)
{
    if (playerShip.GetLocation().x <= -ROOM_SIZE) {
        playerShip.SetLocation(-ROOM_SIZE, playerShip.GetLocation().y, playerShip.GetLocation().z);
    }
    if (playerShip.GetLocation().x >= ROOM_SIZE) {
        playerShip.SetLocation(ROOM_SIZE, playerShip.GetLocation().y, playerShip.GetLocation().z);
    }
    if (playerShip.GetLocation().y >= ROOM_SIZE) {
        playerShip.SetLocation(playerShip.GetLocation().x, ROOM_SIZE, playerShip.GetLocation().z);
    }
    if (playerShip.GetLocation().y <= -ROOM_SIZE) {
        playerShip.SetLocation(playerShip.GetLocation().x, -ROOM_SIZE, playerShip.GetLocation().z);
    }
    else {
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            playerShip.MoveRight(deltaTime);
            std::cout << playerShip.GetLocation().x << " " << playerShip.GetLocation().y << " " << playerShip.GetLocation().z << std::endl;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            playerShip.MoveLeft(deltaTime);
            std::cout << playerShip.GetLocation().x << " " << playerShip.GetLocation().y << " " << playerShip.GetLocation().z << std::endl;
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            vecGameModels[87].position = playerShip.GetLocation();
            playerShip.Fire(vecGameModels[87]);        // 87 is player projectile and 84 is alien projectile
            vecPlayerProjectiles.push_back(vecGameModels[87]);
        }
    }
}

//void cGalaga::Fire(cLoadModels bulletModel)
//{
//    bulletModel.position = playerShip.GetLocation();
//    bulletModel.position.y = playerShip.GetLocation().y + 170.0f;
//    //renderer.DrawMesh(&bulletModel, bulletModel.position, shaderProgram);
//    vecPlayerProjectiles.push_back(bulletModel);
//    std::cout << "BulletPos: " << bulletModel.position.x << " " << bulletModel.position.y << " " << bulletModel.position.z << std::endl;
//    //std::cout << "firing" << std::endl;
//}

void cGalaga::SetupGalaga3D(float deltaTime)
{
    for (int i = 0; i != 50; i++) {             // 50 stars
        vecStars.push_back(vecGameModels.back());
        GenerateRandomCoordinates(vecStars[i].position.x, vecStars[i].position.y, vecStars[i].position.z);
    }

    // Initializing Enemies
    if (!enemiesInitialized) {

        for (int j = 28; j <= 34; j++) {        // 28 is starting index of bee in sceneFile.txt
            cAiEnemy bee(vecGameModels[j]);
            //GenerateRandomCoordinates(vecGameModels[j].position.x, vecGameModels[j].position.y, vecGameModels[j].position.z);
            vecGameModels[j].position.y = ROOM_SIZE;
            vecGameModels[j].position.z = 0;
            vecBeeAliens.push_back(*bee.enemyModel);
        }

        for (int j = 35; j <= 41; j++) {        // 35 is starting index of butterfly in sceneFile.txt
            cAiEnemy butterfly(vecGameModels[j]);
            //GenerateRandomCoordinates(vecGameModels[j].position.x, vecGameModels[j].position.y, vecGameModels[j].position.z);
            vecGameModels[j].position.y = ROOM_SIZE;
            vecGameModels[j].position.z = 0;
            vecButterflyAliens.push_back(*butterfly.enemyModel);
        }

        for (int j = 14; j <= 21; j++) {        // 14 is starting index of green moth aliens in sceneFile.txt
            cAiEnemy greenMoth(vecGameModels[j]);
            //GenerateRandomCoordinates(vecGameModels[j].position.x, vecGameModels[j].position.y, vecGameModels[j].position.z);
            vecGameModels[j].position.y = ROOM_SIZE;
            vecGameModels[j].position.z = 0;
            vecMothGreenAliens.push_back(*greenMoth.enemyModel);
        }

        for (int j = 22; j <= 28; j++) {        // 22 is starting index of blue moth aliens in sceneFile.txt
            cAiEnemy blueMoth(vecGameModels[j]);
            //GenerateRandomCoordinates(vecGameModels[j].position.x, vecGameModels[j].position.y, vecGameModels[j].position.z);
            vecGameModels[j].position.y = ROOM_SIZE;
            vecGameModels[j].position.z = 0;
            vecMothBlueAliens.push_back(*blueMoth.enemyModel);
        }

        PopulateEnemies();
        enemiesInitialized = true;
    }
    
    for (int j = 80; j <= 83; j++) {        // 80 is starting index of player explosions
        vecPlayerExplosionAnimations.push_back(vecGameModels[j]);
    }

    for (int j = 93; j <= 96; j++) {        //93 is starting index of alien explosions
        vecAlienExplosionAnimations.push_back(vecGameModels[j]);
    }

    //if (!enemiesInitialized) {
    //    for (int i = 0; i != 10; i++) {    // considering only 10 enemies spawn at one time
    //        cAiEnemy bee(vecBeeAliens[0]);
    //        GenerateRandomCoordinates(vecBeeAliens[0].position.x, vecBeeAliens[0].position.y, vecBeeAliens[0].position.z);
    //        vecBeeAliens[0].position.z = 0;
    //        vecBeeAliens.push_back(*bee.enemyModel);
    //    }
    //    enemiesInitialized = true;
    //}

    // populating enemies
    //for (int j = 0; j != vecBeeAliens.size(); j++) {
    //    vecEnemies.push_back(vecBeeAliens[j]);
    //}
    //
    //for (int j = 0; j != vecButterflyAliens.size(); j++) {
    //    vecEnemies.push_back(vecButterflyAliens[j]);
    //}
    //
    //for (int j = 0; j != vecMothGreenAliens.size(); j++) {
    //    vecEnemies.push_back(vecMothGreenAliens[j]);
    //}


    playerProjectileIndex = 0;
    enemyIndex = 0;

    cPhysicsUpdated galagaPhysics;
    pGalagaPhysics = &galagaPhysics;

    pGalagaPhysics->vecPhysicsMeshes.clear();
    //pGalagaPhysics->vecCollidingAABBs.clear();
    pGalagaPhysics->vecCollidingSpheres.clear();
    pGalagaPhysics->vecCollidingTriangles.clear();

    // Generating transformed vertices as it is required to calculate aabbs
    //for (int i = 0; i != vecGameModels.size(); i++) {
    //    vecGameModels[i].pTransformedVertices = new cLoadModels::sTransformedVertex[vecGameModels[i].numberOfVertices];
    //    glm::mat4 model = vecGameModels[i].CreateModelMatrix(shaderProgram, vecGameModels[i]);
    //    vecGameModels[i].GenerateTransformedVertices(model);
    //}
}

void cGalaga::GalagaTick(float deltaTime)
{

    // Render player
    renderer.DrawMesh(playerShip.playerModel, playerShip.GetLocation(), shaderProgram);

    // Player fires projectiles
    for (int i = 0; i != vecPlayerProjectiles.size(); i++) {
        vecPlayerProjectiles[i].position.y += deltaTime * 1000.0f + 50.0f;
        renderer.DrawMesh(&vecPlayerProjectiles[i], vecPlayerProjectiles[i].position, shaderProgram);
    }

    // Background Stars 
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
        renderer.DrawMesh(&vecStars[i], vecStars[i].position, shaderProgram);  // Draw star
    }

    
    // Rendering enemies    (Enemy projectiles initialization inside below loop)
    for (int i = 0; i != 30; i++) {
        vecEnemies[i].SetSpeed(100.0f);
        vecEnemies[i].MoveDown(deltaTime);

        if (vecEnemies[i].GetLocation().y < -ROOM_SIZE) {
            vecEnemies[i].SetLocation(startPositionX + (i % 10) * spacing, ROOM_SIZE, 0.0f);    // Setting back all aliens to original position when they cross room boundary
        }

        renderer.DrawMesh(vecEnemies[i].enemyModel, vecEnemies[i].GetLocation(), shaderProgram);

        // Initializing Enemy projectiles
        float currentTime = glfwGetTime();
        if (currentTime - lastFireTime > fireInterval) {
            lastFireTime = currentTime; // Reset fire time
            fireInterval = RandomFloat(0.2f, 0.6f); // Set a new random interval

            // Fire projectile
            cLoadModels alienProjectile = vecGameModels[84];
            alienProjectile.position = vecEnemies[RandomInt(i, vecEnemies.size() % 10)].GetLocation();      // Random enemies will fire
            vecAlienProjectiles.push_back(alienProjectile);
        }
    }

    // Update and render alien projectiles
    for (int i = 0; i < vecAlienProjectiles.size(); i++) {
        vecAlienProjectiles[i].position.y -= deltaTime * 1000.0f + 50.0f;
        renderer.DrawMesh(&vecAlienProjectiles[i], vecAlienProjectiles[i].position, shaderProgram);

        // Remove projectile if out of bounds
        if (vecAlienProjectiles[i].position.y < -ROOM_SIZE) {
            vecAlienProjectiles.erase(vecAlienProjectiles.begin() + i);
            i--;
        }
    }

    // Physics
    
    if (vecPlayerProjectiles.size() > 0 && enemyIndex < vecEnemies.size()) {
        for (int playerProjectileIndex = 0; playerProjectileIndex != vecPlayerProjectiles.size(); playerProjectileIndex++) {
            pGalagaPhysics->CalculateAABB(vecPlayerProjectiles[playerProjectileIndex]);
            for (int enemyIndex = 0; enemyIndex != vecEnemies.size(); enemyIndex++) {
                pGalagaPhysics->CalculateAABB(*vecEnemies[enemyIndex].enemyModel);
                
                if (pGalagaPhysics->CheckAABBCollision(vecPlayerProjectiles[playerProjectileIndex].modelAABB, vecEnemies[enemyIndex].enemyModel->modelAABB)) {     // Checking collision between player projectiles and enemies
                    //cPhysicsUpdated::sAABBAABB_Collision collision;
                    //collision.collidingAABBs[0] = &vecPlayerProjectiles[playerProjectileIndex].modelAABB;
                    //collision.collidingAABBs[1] = &vecEnemies[enemyIndex].enemyModel->modelAABB;
                    //collision.model[0] = vecPlayerProjectiles[playerProjectileIndex];
                    //collision.model[1] = vecEnemies[enemyIndex].enemyModel;

                    //pGalagaPhysics->vecCollidingAABBs.push_back(collision);

                    //std::cout << "Collision occured between: " << playerProjectileIndex << " and " << enemyIndex << std::endl;
                    glm::vec3 collisionPoint = pGalagaPhysics->GetAABBCollisionPoint(vecPlayerProjectiles[playerProjectileIndex].modelAABB, vecEnemies[enemyIndex].enemyModel->modelAABB);

                    std::cout << "CollisionPoint: " << collisionPoint.x << " " << collisionPoint.y << " " << collisionPoint.z << std::endl;
                    for (int i = 0; i != vecAlienExplosionAnimations.size(); i++) {
                        renderer.DrawMesh(&vecAlienExplosionAnimations[i], collisionPoint, shaderProgram);
                    }

                    vecEnemies.erase(vecEnemies.begin() + enemyIndex);
                    vecPlayerProjectiles.erase(vecPlayerProjectiles.begin() + playerProjectileIndex);

                    // Adjust indices after erasing elements
                    enemyIndex--;
                    playerProjectileIndex--;
                }
            }
        }
    }
}


void cGalaga::PopulateEnemies()
{
    for (int i = 0; i != 30; i++) {
        vecMothGreenAliens[0].SetLocation(startPositionX + i * spacing, ROOM_SIZE - 1.0f, 0.0f);              // Lineup
        vecBeeAliens[0].SetLocation(startPositionX + i * spacing, ROOM_SIZE - 191.0f, 0.0f);
        vecButterflyAliens[0].SetLocation(startPositionX + i * spacing, ROOM_SIZE - 381.0f, 0.0f);

        vecEnemies.push_back(vecBeeAliens[0]);
        vecEnemies.push_back(vecMothGreenAliens[0]);
        vecEnemies.push_back(vecButterflyAliens[0]);
    }
}

int cGalaga::RandomInt(int min, int max) {
    return min + rand() % (max - min + 1); // Including max
}

float cGalaga::RandomFloat(float min, float max) {
    float range = max - min;
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / range);
}

void cGalaga::GenerateRandomCoordinates(float& x, float& y, float& z) {
    x = RandomFloat(-ROOM_SIZE, ROOM_SIZE);
    y = RandomFloat(-ROOM_SIZE, ROOM_SIZE);
    z = RandomFloat(-ROOM_SIZE, -10);       // Range taken from screenshots of camLocation
}