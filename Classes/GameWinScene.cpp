#include "GameWinScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene2.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* GameWinScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameWinScene::create();
	scene->addChild(layer);
	return scene;
}
bool GameWinScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("Main menu", CC_CALLBACK_1(GameWinScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	this->addChild(menu);
	return true;
}
void GameWinScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}