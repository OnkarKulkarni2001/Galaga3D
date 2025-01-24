#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "cLoadModels.h"
#include "FlyCam.h"
#include "cShaderCompiler.h"
#include "cVAOManager.h"
#include "cScene.h"
#include "IPlayer.h"
#include "cPlayer.h"
#include "cAiEnemy.h"
#include "cLightManager.h"
#include "cLightMover.h"
#include "cPhysicsUpdated.h"
#include "cRenderModel.h"
//#include "cGalaga.h"
#include "IGalaga.h"
#include "IGalagaFactory.h"
#include "cGalaga3D.h"
#include "cGalagaFactory.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set OpenGL version (3.3 core profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(600, 800, "OpenGL Triangle", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Refer cShaderCompiler class for more info.
    cShaderCompiler shader;
    GLuint shaderProgram = shader.CompileShader();

    cVAOManager VAOManager;

    cRenderModel renderer;

    cLightManager lightManager;
    lightManager.LoadLights("../lightsFile.txt");
    // Camera Initialization
    FlyCam flyCam(600, 800, glm::vec3(-21.52f, -29.10f, 8617.0f), -90.0f);

    flyCam.camSpeed = 100.0f;

    cLightMover lightMover(lightManager, flyCam, 5);

    float deltaTime = 0;
    float startTime, endTime;

    startTime = glfwGetTime();
    //cPlayer bunny(scene.pModels[0]);
    //bunny.SetSpeed(0.06f);
    //
    //cPlayer dragon(scene.pModels[2]);
    //dragon.SetSpeed(0.06f);

    //cPlayer playerShip(scene.pModels[0]);
    //playerShip.SetSpeed(5.0f);
    //
    //cGalaga GalagaGame(scene, renderer, shaderProgram);
    //GalagaGame.SetupGalaga3D(deltaTime);

    IGalagaFactory* pGalagaFactory = new cGalagaFactory();
    cGalaga3D galagaGame;
    galagaGame.InitializeGalaga(pGalagaFactory, shaderProgram, VAOManager);
    galagaGame.SetupGalaga();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Render loop
    while (!glfwWindowShouldClose(window)) {

        // Input handling
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        glfwGetWindowSize(window, &flyCam.camWidth, &flyCam.camHeight);

        std::string cameraPositionInTitle = "Camera Location: (" + to_string(flyCam.camLocation.x) + ", " + to_string(flyCam.camLocation.y) + ", " + to_string(flyCam.camLocation.z) + ") Camera Speed: " + to_string(flyCam.camSpeed) + " Camera Roll: " + to_string(flyCam.camRoll) + " Cam yaw: " + to_string(flyCam.camYaw) + " Cam pitch: " + to_string(flyCam.camPitch);
        glfwSetWindowTitle(window, cameraPositionInTitle.c_str());

        endTime = glfwGetTime();
        deltaTime = endTime - startTime;
        startTime = endTime;
        //std::cout << deltaTime << " Time passed" << std::endl;\

        
        flyCam.cameraMatrix(45.0f, 0.1f, 100000.0f, shaderProgram, "camMatrix", window);

        // Rendering commands here
        glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
        glEnable(GL_DEPTH_TEST);   // Enable depth testing
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader program and draw the triangle
        glUseProgram(shaderProgram);

        //lightMover.MoveForward();
        //lightMover.MoveUp();
        //lightMover.MoveRight();

        lightManager.TurnOnLights(shaderProgram, 5);


        //glBindVertexArray(VAO);
        //int offset = 0;
        //for (int index = 0; index != scene.pModels.size(); index++) {
        //
        //    glm::mat4 model = scene.pModels[index].CreateModelMatrix(shaderProgram, scene.pModels[index]);      // Creation of model matrix with arguements passed in sceneFile.txt
        //    scene.pModels[index].GenerateTransformedVertices(model);            // this is here because collisions want transformed vertices
        //
        //    unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
        //    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //
        //    glDrawArrays(GL_TRIANGLES, offset, scene.pModels[index].numberOfVerticesToRender);
        //    offset += scene.pModels[index].numberOfVerticesToRender;
        //}
        shader.SetSceneView(window);        // Press 1, 2 or 3 for different viewModes like wireframe, fill or point

        galagaGame.Tick(window, deltaTime);

        //renderer.DrawDebugSphere(&scene.pModels[0], glm::vec3(0, 0, 0), glm::vec4(0, 1, 0, 1), 1, shaderProgram);
        //
        //if (deltaTime >= 10) {
        //physicsEngine.CheckCollision(scene);
            //startTime = endTime;
        //}
            //dragon.SetSpeed(0.1f);
        //
        
        // Swap buffers and poll IO events (keys pressed/released, mouse moved, etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // Cleanup
    //VAOManager.VAOVBOCleanup();
    delete pGalagaFactory;
    // Terminate GLFW
    glfwTerminate();
    return 0;
}