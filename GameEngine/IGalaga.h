#pragma once
#include "cLoadModels.h"
#include <vector>

class IProjectile {
public:
    virtual cLoadModels GetModel() = 0;
    virtual void SetModel(cLoadModels& model) = 0;
    virtual void Fire(float deltaTime) = 0;
    virtual glm::vec3 GetPosition() = 0;
    virtual void SetPosition(glm::vec3 position) = 0;
    virtual float GetSpeed() = 0;
    virtual void SetSpeed(float speed) = 0;
    virtual ~IProjectile() {}
};

class IPlayerShip {
public:
    virtual cLoadModels* GetModel() = 0;
    virtual void SetModel(cLoadModels& model) = 0;
    virtual void MoveLeft(float deltaTime) = 0;
    virtual void MoveRight(float deltaTime) = 0;
    virtual void Shoot(float deltaTime, IProjectile* projectile) = 0;
    virtual void TakeHit(float deltaTime) = 0;
    virtual glm::vec3 GetPosition() = 0;
    virtual void SetPosition(glm::vec3 position) = 0;
    virtual float GetSpeed() = 0;
    virtual void SetSpeed(float speed) = 0;
    virtual ~IPlayerShip(){}
};

class IAlienAi {
public:
    virtual cLoadModels GetModel() = 0;
    virtual void SetModel(cLoadModels& model) = 0;
    virtual void MoveAlongCurve(float deltaTime) = 0;
    virtual void Shoot(float deltaTime, IProjectile* projectile) = 0;
    virtual void TakeHit(float deltaTime) = 0;
    virtual bool IsDestroyed(float deltaTime) = 0;
    virtual glm::vec3 GetPosition() = 0;
    virtual void SetPosition(glm::vec3 position) = 0;
    virtual float GetSpeed() = 0;
    virtual void SetSpeed(float speed) = 0;
    virtual ~IAlienAi(){}
};

class IAnimation {
public:
    virtual std::vector<cLoadModels*> GetExplosionAnimations() = 0;
    virtual void Animate(float deltaTime) = 0;
    virtual glm::vec3 GetPosition() = 0;
    virtual void SetPosition(glm::vec3 position) = 0;
    virtual ~IAnimation(){}
};