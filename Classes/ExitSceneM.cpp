#include "ExitSceneM.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"

USING_NS_CC;
 
Scene* ExitSceneM::createScene()
{
	auto scene = Scene::create();
	auto layer = ExitSceneM::create();
	scene->addChild(layer);
	return scene;
}
bool ExitSceneM::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bg = Sprite::create("bgE.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto are = Sprite::create("Are.png");
	auto wont = Sprite::create("want.png");

	are->setScale(0.5);
	wont->setScale(0.5);

	auto playItem = MenuItemImage::create("No.png", "", CC_CALLBACK_1(ExitSceneM::Resume, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemImage::create("Yes.png", "", CC_CALLBACK_1(ExitSceneM::Exit, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(300, -100));
	playItem1->setPosition(Vec2(100, -100));
	playItem->setScale(0.5);
	playItem1->setScale(0.5);

	are->setPosition(Vec2(700, 500));
	wont->setPosition(Vec2(730, 400));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(are);
	this->addChild(wont);

	return true;

}
void ExitSceneM::Resume(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
void ExitSceneM::Exit(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
}

