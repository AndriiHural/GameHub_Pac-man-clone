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

	auto bg = Sprite::create("bgP.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto playItem = MenuItemImage::create("MainMenu.png", "", CC_CALLBACK_1(PauseScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Resume.png", "", CC_CALLBACK_1(PauseScene::Resume, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	auto playItem2 = MenuItemImage::create("Restart.png", "", CC_CALLBACK_1(PauseScene::Retry, this));
	auto menu2 = Menu::create(playItem2, NULL);
	menu2->alignItemsVerticallyWithPadding(100);
	auto playItem3 = MenuItemImage::create("Exit.png", "", CC_CALLBACK_1(PauseScene::Exit, this));
	auto menu3 = Menu::create(playItem3, NULL);
	menu3->alignItemsVerticallyWithPadding(100);
	playItem1->setPosition(Vec2(150, 50));
	playItem2->setPosition(Vec2(150,-50 ));
	playItem->setPosition(Vec2(150, -150));
	playItem3->setPosition(Vec2(150, -250));

	playItem->setScale(0.5);
	playItem1->setScale(0.5);
	playItem2->setScale(0.5);
	playItem3->setScale(0.5);

	this->addChild(menu,1);
	this->addChild(menu1,1);
	this->addChild(menu2,1);
	this->addChild(menu3,1);
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