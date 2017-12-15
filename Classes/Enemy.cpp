#include "Enemy.h"



Enemy::Enemy()
{
	sprite = cocos2d::Sprite::create("bad_man/bup1.png");

	
}


Enemy::~Enemy()
{
}

void Enemy:: setSprite(std::string path) {
	sprite = cocos2d::Sprite::create(path);
}
cocos2d::Sprite* Enemy:: getSprite() {
	return sprite;
}