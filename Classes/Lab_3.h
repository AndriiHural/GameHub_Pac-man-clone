#ifndef __LAB_3_H__
#define __LAB_3_H__
#define n_row 21 // size row libirinte
#define n_col 22 //size colom libirinte
#include "cocos2d.h"




class Lab_3 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();


	virtual bool init();
	virtual void update(float df);
	// my sprite 
	cocos2d::Sprite *enemy;
	//enemy
	cocos2d::Sprite *sprite;

	cocos2d::Sprite *enemy1;

	// number pressed key
	int KeyPressed;
	bool isKeyPressed;
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event *event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event *event);

	/*An array describes a map of movements*/
	int arr[n_row][n_col] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 },
		{ 0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0 },
		{ 0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0 },
		{ 0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0 },
		{ 0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,0 },
		{ 0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0 },
		{ 0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,0 },
		{ 1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0 },
		{ 0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0 },
		{ 0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0 },
		{ 0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0 },
		{ 0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0 },
		{ 0,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0 },
		{ 0,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0 },//5
		{ 0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0 },//6
		{ 0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,0,0 },//7
		{ 0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0 },//8
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }//9
	};

	int can_go[12] = {
		0,4,//coordinate describe point that is located  on top sprite
		1,3,       1,5,// coordinate describe point that is located  on left and right sprite
		2,4,//coordinate describe point that is located  on bottom sprite
		0,0,30, //step on the axis X, step on the axis Y, size of the one square
		1// one step
	};
	int can_go_Enemy[12] = {
		0,1,//coordinate describe point that is located  on top sprite
		1,0,       1,2,// coordinate describe point that is located  on left and right sprite
		2,1,//coordinate describe point that is located  on bottom sprite
		0,0,30,//step on the axis X, step on the axis Y, size of the one square
		5// one step
	};

	int can_go_Enemy1[12] = {
		0,16,//coordinate describe point that is located  on top sprite
		1,15,       1,17,// coordinate describe point that is located  on left and right sprite
		2,16,//coordinate describe point that is located  on bottom sprite
		0,0,30,//step on the axis X, step on the axis Y, size of the one square
		5// one step
	};
	int randomInt;
	int randomInt1;
	int EnemyArrows = 0;
	int EnemyArrows1 = 0;
	void randomMoveEnemy(float df);
	void randomMoveEnemy1(float df);
	// implement the "static create()" method manually
	CREATE_FUNC(Lab_3);
	void GoToPauseScene(Ref *pSender);
	void GoToGameOverScene(Ref *pSender);

	void setPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		mWorld = world;
		mWorld->setGravity(cocos2d::Vect(0, 0));
	}
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	cocos2d::PhysicsWorld* mWorld;
};


#endif // __HELLOWORLD_SCENE_H__



