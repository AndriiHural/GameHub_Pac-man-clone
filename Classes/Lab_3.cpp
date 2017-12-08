#include "Lab_3.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* Lab_3::createScene()
{
	auto scene = Scene::create();
	auto layer = Lab_3::create();
	scene->addChild(layer);
	return scene;
}
bool Lab_3::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto sprite = Sprite::create("2.png");
	auto background = Sprite::create("4.png");
	sprite->setScale(0.15);
	background->setScale(1.15);
	sprite->setAnchorPoint(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(70, 430));
	int t = rand() % 5 + 1;
	auto move = MoveTo::create(t, Vec2(70, 360));
	auto move1 = MoveTo::create(t, Vec2(178, 360));
	auto move2 = MoveTo::create(t, Vec2(178, 290));
	auto move3 = MoveTo::create(t, Vec2(217, 290));
	auto move4 = MoveTo::create(t, Vec2(217, 215));
	auto move5 = MoveTo::create(t, Vec2(70, 215));
	auto move6 = MoveTo::create(t, Vec2(70, 75));
	auto move7 = MoveTo::create(t, Vec2(325, 75));
	auto move8 = MoveTo::create(t, Vec2(325, 15));
	auto move9 = MoveTo::create(t, Vec2(340, 0));
	auto move0 = MoveTo::create(t, Vec2(350, 320));
	auto delay = DelayTime::create(0.3);
	auto delay1 = DelayTime::create((0.3 * 8) + t * 8);
	sprite->runAction(Sequence::create(move, delay, move1, delay->clone(), move2, delay->clone(),
		move3, delay->clone(), move4, delay->clone(), move5, delay->clone(), move6, delay->clone(),
		move7, delay->clone(), move8, nullptr));
	this->addChild(background, 1);
	this->addChild(sprite, 2);
	
	auto playItem = MenuItemFont::create("||", CC_CALLBACK_1(Lab_3::GoToPauseScene, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(470, 280));
	this->addChild(menu,3);
	return true;
}
void Lab_3::GoToPauseScene(cocos2d::Ref *pSender)
{
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}
void Lab_3::GoToGameOverScene(cocos2d::Ref *pSender)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}