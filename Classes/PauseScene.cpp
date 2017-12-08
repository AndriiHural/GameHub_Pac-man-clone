#include "PauseScene.h"
#include "SimpleAudioEngine.h"
#include "Lab_1.h"
#include "MainMenu.h"
#include "ExitScene.h"

USING_NS_CC;

Scene* PauseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseScene::create();
	scene->addChild(layer);
	return scene;
}
bool PauseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("Main menu", CC_CALLBACK_1(PauseScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemFont::create("Resume", CC_CALLBACK_1(PauseScene::Resume, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemFont::create("Retry", CC_CALLBACK_1(PauseScene::Retry, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	auto playItem3 = MenuItemFont::create("Exit", CC_CALLBACK_1(PauseScene::Exit, this));
	auto menu3 = Menu::create(playItem3, NULL);
	menu3->alignItemsVerticallyWithPadding(100);
	playItem1->setPosition(Vec2(0, 200));
	playItem2->setPosition(Vec2(0, 100));
	playItem->setPosition(Vec2(0, 0));
	playItem3->setPosition(Vec2(0, -100));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(menu2);
	this->addChild(menu3);
	return true;
}
void PauseScene::Resume(cocos2d::Ref *pSender)
{
	Director::getInstance()->popScene();
}
void PauseScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}
void PauseScene::Retry(cocos2d::Ref *pSender)
{
	auto scene = Lab_1::createScene();
	Director::getInstance()->replaceScene(scene);
}
void PauseScene::Exit(cocos2d::Ref *pSender)
{
	auto scene = ExitScene::createScene();
	Director::getInstance()->replaceScene(scene);
}