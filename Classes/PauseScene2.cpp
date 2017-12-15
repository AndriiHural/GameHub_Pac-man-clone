#include "PauseScene2.h"
#include "SimpleAudioEngine.h"
#include "Lab_2.h"
#include "MainMenu.h"
#include "ExitScene.h"

USING_NS_CC;

Scene* PauseScene2::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseScene2::create();
	scene->addChild(layer);
	return scene;
}
bool PauseScene2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto bg = Sprite::create("bgP.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto playItem = MenuItemImage::create("MainMenu.png", "", CC_CALLBACK_1(PauseScene2::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Resume.png", "", CC_CALLBACK_1(PauseScene2::Resume, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemImage::create("Restart.png", "", CC_CALLBACK_1(PauseScene2::Retry, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	auto playItem3 = MenuItemImage::create("Exit.png", "", CC_CALLBACK_1(PauseScene2::Exit, this));
	auto menu3 = Menu::create(playItem3, NULL);
	menu3->alignItemsVerticallyWithPadding(100);
	playItem1->setPosition(Vec2(150, 50));
	playItem2->setPosition(Vec2(150, -50));
	playItem->setPosition(Vec2(150, -150));
	playItem3->setPosition(Vec2(150, -250));

	playItem->setScale(0.5);
	playItem1->setScale(0.5);
	playItem2->setScale(0.5);
	playItem3->setScale(0.5);

	this->addChild(menu, 1);
	this->addChild(menu1, 1);
	this->addChild(menu2, 1);
	this->addChild(menu3, 1);
	return true;
}
void PauseScene2::Resume(cocos2d::Ref *pSender)
{
	Director::getInstance()->popScene();
}
void PauseScene2::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}
void PauseScene2::Retry(cocos2d::Ref *pSender)
{
	auto scene = Lab_2::createScene();
	Director::getInstance()->replaceScene(scene);
}
void PauseScene2::Exit(cocos2d::Ref *pSender)
{
	auto scene = ExitScene::createScene();
	Director::getInstance()->replaceScene(scene);
}