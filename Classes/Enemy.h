#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "cocos2d.h"
#include <string>
/*Class description enemy*/
class Enemy
{
private:
	cocos2d::Sprite *sprite;
	int can_go_Enemy[12] = {
		10,9,//coordinate describe point that is located  on top sprite
		11,8,       11,10,// coordinate describe point that is located  on left and right sprite
		12,9,//coordinate describe point that is located  on bottom sprite
		0,0,30,//step on the axis X, step on the axis Y, size of the one square
		5// one step
	};
	int randomInt;
	int EnemyArrows = 0;
public:
	/*Constructor */
	Enemy();
	/*Destructor*/
	~Enemy();
	/*if you want change sprite image*/
	void setSprite(std::string path);
	/*return sprite*/
	cocos2d::Sprite* getSprite();

};
#endif