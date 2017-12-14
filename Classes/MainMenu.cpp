#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "LevelScene.h"
#include "AboutScene.h"
#include "SettingsScene.h"
#include "ExitSceneM.h"

USING_NS_CC;
 
Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
	return scene;
}
bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("New Game",CC_CALLBACK_1(MainMenu::GoToLevelScene, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemFont::create("Settings", CC_CALLBACK_1(MainMenu::GoToSettingsScene, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemFont::create("About", CC_CALLBACK_1(MainMenu::GoToAboutScene, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	auto playItem3 = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenu::GoToExitScene, this));
	auto menu3 = Menu::create(playItem3, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(0, 200));
	playItem1->setPosition(Vec2(0,100));
	playItem2->setPosition(Vec2(0, 0));
	playItem3->setPosition(Vec2(0, -100));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	this->addChild(menu3);
	return true;

}
void MainMenu::GoToLevelScene(Ref *pSender)
{
	auto scene = LevelScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MainMenu::GoToAboutScene(Ref *pSender)
{
	auto scene = AboutScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MainMenu::GoToSettingsScene(Ref *pSender)
{
	auto scene = SettingsScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void MainMenu::GoToExitScene(cocos2d::Ref *pSender)
{
	auto scene = ExitSceneM::createScene();
	Director::getInstance()->replaceScene(scene);
}
