#include "GameOverScene2.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"
#include "Lab_3.h"



USING_NS_CC;

Scene* GameOverScene2::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene2::create();
	scene->addChild(layer);
	return scene;
}
bool GameOverScene2::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto bg = Sprite::create("bgGO.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto playItem = MenuItemImage::create("MainMenu.png", "", CC_CALLBACK_1(GameOverScene2::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Restart.png", "", CC_CALLBACK_1(GameOverScene2::Retry3, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemImage::create("Exit.png", "", CC_CALLBACK_1(GameOverScene2::GoToExit, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	playItem1->setPosition(Vec2(150, 80));
	playItem->setPosition(Vec2(150, -80));
	playItem2->setPosition(Vec2(150, -240));

	playItem->setScale(0.6f);
	playItem1->setScale(0.6f);
	playItem2->setScale(0.6f);

	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	return true;
}
void GameOverScene2::Retry3(cocos2d::Ref *pSender)
{
	auto scene = Lab_3::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Heathen.mp3");
	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Heathen.mp3", true);
}
void GameOverScene2::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Heathen.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Heathen.mp3", true);
}
void GameOverScene2::GoToExit(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
}