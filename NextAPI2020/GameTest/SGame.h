#pragma once

// Standard includes
#include <string>

// Internal includes
#include "Scene.h"
#include "CBoxCollider.h"
#include "CTurretAimer.h"
#include "CLabel.h"
#include "CBank.h"
#include "CHealth.h"

class SGame : public Scene
{
public:
	//--- Constructors and Destructor ---//
	SGame();
	~SGame();

	//--- Scene Interface ---//
	virtual void Init() override;
	virtual void Update(float _deltaTime) override;
	virtual void Draw() override;

	//--- Game Logic Methods ---//
	void LoadLevel();
	void SetupPlayer();
	void CheckCollisions();
	void SpawnEnemy();
	void TriggerEnemyDirectionChange(CBoxCollider* _a, CBoxCollider* _b, Vec2& _overlap);
	void AttackPlayerBase(CBoxCollider* _a, CBoxCollider* _b, Vec2& _overlap);
	void FireBasicProjectile(CTransform* _turret, CTransform* _enemy);
	void DamageEnemy(CBoxCollider* _a, CBoxCollider* _b, Vec2& _overlap);
	void PlaceTower(Entity* _callingButton);
	void GameOver(Entity* _playerEntity);

	//--- Setters ---//
	void SetLevelName(std::string _levelName);

private:
	//--- Private Data ---//
	std::string m_levelName;
	std::vector<Entity*> m_levelPieces;
	CTransform* m_enemySpawner;
	float m_timeBetweenEnemies;
	float m_timeSinceLastEnemy;
	std::vector<Entity*> m_enemies;
	Entity* m_player;
	CBank* m_playerBank;
	CLabel* m_playerMoneyLabel;
	CHealth* m_playerHealth;
	CLabel* m_playerHealthLabel;
};