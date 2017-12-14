#include "LevelScene.h"
#include "SimpleAudioEngine.h"
#include "Lab_1.h"
#include "Lab_2.h"
#include "Lab_3.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* LevelScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LevelScene::create();
	scene->addChild(layer);
	return scene;
}
bool LevelScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	

	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == false)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Heathen.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Heathen.mp3", true);
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.1);
	}


	auto playItem = MenuItemFont::create("Level 1", CC_CALLBACK_1(LevelScene::GoToLab_1, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemFont::create("Level 2", CC_CALLBACK_1(LevelScene::GoToLab_2, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemFont::create("Level 3", CC_CALLBACK_1(LevelScene::GoToLab_3, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	auto playItem3 = MenuItemFont::create("Back", CC_CALLBACK_1(LevelScene::GoToMainMenu, this));
	auto menu3 = Menu::create(playItem3, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(0, 200));
	playItem1->setPosition(Vec2(0, 100));
	playItem2->setPosition(Vec2(0,0));
	playItem3->setPosition(Vec2(0, -100));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	this->addChild(menu3);
	return true;
}
void LevelScene::GoToLab_1(cocos2d::Ref *pSender)
{
	auto scene = Lab_1::createScene();
	Director::getInstance()->pushScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/sail.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/sail.mp3", true);
}
void LevelScene::GoToLab_2(cocos2d::Ref *pSender)
{
	auto scene = Lab_2::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/sail.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/sail.mp3", true);

}
void LevelScene::GoToLab_3(cocos2d::Ref *pSender)
{
	auto scene = Lab_3::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/sail.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/sail.mp3", true);

}
void LevelScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/click.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Heathen.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Heathen.mp3", true);
	//CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

}