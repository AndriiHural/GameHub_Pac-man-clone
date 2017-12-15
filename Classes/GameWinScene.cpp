#include "GameWinScene.h"
#include "SimpleAudioEngine.h"
#include "LevelScene.h"
#include "ExitSceneM.h"
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

	auto bg = Sprite::create("bgW.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto Label1 = Label::createWithTTF("New Game", "fonts/Marker Felt.ttf", 70);
	auto Label2 = Label::createWithTTF("Settings", "fonts/Marker Felt.ttf", 70);

	Label1->setColor(Color3B::YELLOW);
	Label2->setColor(Color3B::YELLOW);

	auto playItem = MenuItemLabel::create(Label1, CC_CALLBACK_1(GameWinScene::GoToLevelScene, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	auto playItem1 = MenuItemLabel::create(Label2, CC_CALLBACK_1(GameWinScene::GoToLevelScene, this));
	auto menu1 = Menu::create(playItem1, NULL);
	menu1->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(-150, -50));
	playItem1->setPosition(Vec2(-150, -150));
	this->addChild(menu, 0);
	this->addChild(menu1, 0);
	return true;

}
void GameWinScene::GoToLevelScene(Ref *pSender)
{
	auto scene = LevelScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void GameWinScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

