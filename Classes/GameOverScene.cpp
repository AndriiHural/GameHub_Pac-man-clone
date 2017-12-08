#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene2.h"
#include "MainMenu.h"

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
	auto playItem = MenuItemFont::create("Main menu", CC_CALLBACK_1(GameOverScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	this->addChild(menu);
	return true;
}
void GameOverScene::GoToGameScene(cocos2d::Ref *pSender)
{
	auto scene = PauseScene2::createScene();
	Director::getInstance()->replaceScene(scene);
}
void GameOverScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}