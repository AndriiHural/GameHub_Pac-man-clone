#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"
#include "Lab_1.h"



USING_NS_CC;

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}
bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto bg = Sprite::create("bgGO.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto playItem = MenuItemImage::create("MainMenu.png","", CC_CALLBACK_1(GameOverScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Restart.png", "", CC_CALLBACK_1(GameOverScene::Retry1, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemImage::create("Exit.png", "", CC_CALLBACK_1(GameOverScene::GoToExit, this));
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
void GameOverScene::Retry1(cocos2d::Ref *pSender)
{
	auto scene = Lab_1::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/sail.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/sail.mp3", true);
}
void GameOverScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Heathen.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Heathen.mp3", true);
}
void GameOverScene::GoToExit(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
}