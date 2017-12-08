#include "AboutScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* AboutScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}
bool AboutScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto playItem = MenuItemFont::create("Back", CC_CALLBACK_1(AboutScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(450, -280));
	this->addChild(menu);
	return true;
}
void AboutScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}