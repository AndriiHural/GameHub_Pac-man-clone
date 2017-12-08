#include "SettingsScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* SettingsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingsScene::create();
	scene->addChild(layer);
	return scene;
}
bool SettingsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("Back", CC_CALLBACK_1(SettingsScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(450, -280));
	this->addChild(menu);
	return true;
}
void SettingsScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}