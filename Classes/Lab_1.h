﻿#ifndef __LAB_1_H__
#define __LAB_1_H__
#define n_row 21 // size row libirinte
#define n_col 22 //size colom libirinte
#include "cocos2d.h"
#include "LevelMaps.h"




class Lab_1 : public cocos2d::Layer,public LevelMaps
{
	/*field*/
private:
	// my sprite 
	cocos2d::Sprite *enemy;
	//enemy
	cocos2d::Sprite *sprite;

	/*Label score*/
	cocos2d::Label *myLabel;
	/*Value score*/
	int score = 0;

	// number pressed key
	int KeyPressed;
	bool isKeyPressed;

	int can_go[12] = {
		0,4,//coordinate describe point that is located  on top sprite
		1,3,       1,5,// coordinate describe point that is located  on left and right sprite
		2,4,//coordinate describe point that is located  on bottom sprite
		0,0,30, //step on the axis X, step on the axis Y, size of the one square
		1// one step
	};
	int can_go_Enemy[12] = {
		10,9,//coordinate describe point that is located  on top sprite
		11,8,       11,10,// coordinate describe point that is located  on left and right sprite
		12,9,//coordinate describe point that is located  on bottom sprite
		0,0,30,//step on the axis X, step on the axis Y, size of the one square
		5// one step
	};
	int randomInt;
	int EnemyArrows = 0;

	/*array of enemy*/
	std::vector<cocos2d::Sprite *> enemys;
	/*method*/
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float df);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event *event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event *event);
	void randomMoveEnemy(float df);
	// implement the "static create()" method manually
	CREATE_FUNC(Lab_1);
	void GoToPauseScene(Ref *pSender);
	void GoToGameOverScene(Ref *pSender);

	///*Tiner*/
	//void TimerMethod(float dt);

	//cocos2d::Label *label;
	//float time;

	//float laps[3];

	//int lapIndex;

	void setPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		mWorld = world;
		mWorld->setGravity(cocos2d::Vect(0, 0));
	}
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	cocos2d::PhysicsWorld* mWorld;
};


#endif 



