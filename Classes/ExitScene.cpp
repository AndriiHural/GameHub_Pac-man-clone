#include "ExitScene.h"
#include "SimpleAudioEngine.h"
#include "Lab_1.h"
#include "Lab_2.h"
#include "Lab_3.h"

USING_NS_CC;
 
Scene* ExitScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ExitScene::create();
	scene->addChild(layer);
	return scene;
}
bool ExitScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto label = Label::createWithSystemFont("Are you sure want to exit?", "Arial", 32);
	auto playItem = MenuItemFont::create("No", CC_CALLBACK_1(ExitScene::Resume, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemFont::create("Yes", CC_CALLBACK_1(ExitScene::Exit, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(100, -50));
	playItem1->setPosition(Vec2(-100, -50));
	label->setPosition(Vec2(500, 400));
	this->addChild(menu);
	this->addChild(menu1);
	this->addChild(label);
	return true;

}
void ExitScene::Resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}
void ExitScene::Exit(cocos2d::Ref *pSender)
{
	Director::getInstance()->end();
}

