#include "GameOverScene1.h"
#include "SimpleAudioEngine.h"
#include "PauseScene2.h"
#include "MainMenu.h"
#include "Lab_2.h"



USING_NS_CC;

Scene* GameOverScene1::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene1::create();
	scene->addChild(layer);
	return scene;
}
bool GameOverScene1::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("Main menu", CC_CALLBACK_1(GameOverScene1::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemFont::create("Retry", CC_CALLBACK_1(GameOverScene1::Retry, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemFont::create("Exit", CC_CALLBACK_1(GameOverScene1::GoToExit, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(0, 0));
	playItem1->setPosition(Vec2(0, 150));
	playItem2->setPosition(Vec2(0, -150));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	return true;
}
void GameOverScene1::Retry(cocos2d::Ref *pSender)
{
	auto scene = Lab_2::createScene();
	Director::getInstance()->replaceScene(scene);
}
void GameOverScene1::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
void GameOverScene1::GoToExit(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
}