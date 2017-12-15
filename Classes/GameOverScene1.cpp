#include "GameOverScene1.h"
#include "SimpleAudioEngine.h"
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
	auto bg = Sprite::create("bgGO.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto playItem = MenuItemImage::create("MainMenu.png", "", CC_CALLBACK_1(GameOverScene1::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Restart.png", "", CC_CALLBACK_1(GameOverScene1::Retry2, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemImage::create("Exit.png", "", CC_CALLBACK_1(GameOverScene1::GoToExit, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	playItem1->setPosition(Vec2(150, 80));
	playItem->setPosition(Vec2(150, -80));
	playItem2->setPosition(Vec2(150, -240));

	playItem->setScale(0.6);
	playItem1->setScale(0.6);
	playItem2->setScale(0.6);

	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	return true;
}
void GameOverScene1::Retry2(cocos2d::Ref *pSender)
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