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

	auto bg = Sprite::create("bgG.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto label1 = Label::createWithTTF("Developers:", "fonts/Marker Felt.ttf", 50);
	auto label2 = Label::createWithTTF("Hural Andriy", "fonts/Marker Felt.ttf", 50);
	auto label3 = Label::createWithTTF("Holub Ihor", "fonts/Marker Felt.ttf", 50);
	auto label4 = Label::createWithTTF("Kapko Bogdan", "fonts/Marker Felt.ttf", 50);
	auto label5 = Label::createWithTTF("Vishnevskiy Oleksandr", "fonts/Marker Felt.ttf", 50);
	auto label6 = Label::createWithTTF("Tumchuk Myhailo", "fonts/Marker Felt.ttf", 50);
	auto label7 = Label::createWithTTF("Study in Precarpathian National University.", "fonts/Marker Felt.ttf", 50);
	auto label8 = Label::createWithTTF("Faculty of Mathematics and Informatics.", "fonts/Marker Felt.ttf", 50);
	auto label9 = Label::createWithTTF("Made in GameHub laboratory.", "fonts/Marker Felt.ttf", 50);

	label1->setColor(Color3B::YELLOW);
	label2->setColor(Color3B::YELLOW);
	label3->setColor(Color3B::YELLOW);
	label4->setColor(Color3B::YELLOW);
	label5->setColor(Color3B::YELLOW);
	label6->setColor(Color3B::YELLOW);
	label7->setColor(Color3B::YELLOW);
	label8->setColor(Color3B::YELLOW);
	label9->setColor(Color3B::YELLOW);

	label1->setAnchorPoint(Vec2(0, 0));
	label2->setAnchorPoint(Vec2(0, 0));
	label3->setAnchorPoint(Vec2(0, 0));
	label4->setAnchorPoint(Vec2(0, 0));
	label5->setAnchorPoint(Vec2(0, 0));
	label6->setAnchorPoint(Vec2(0, 0));
	label7->setAnchorPoint(Vec2(0, 0));
	label8->setAnchorPoint(Vec2(0, 0));
	label9->setAnchorPoint(Vec2(0, 0));

	label1->setPosition(Vec2(10, 550));
	label2->setPosition(Vec2(10, 500));
	label3->setPosition(Vec2(10, 450));
	label4->setPosition(Vec2(10, 400));
	label5->setPosition(Vec2(10, 350));
	label6->setPosition(Vec2(10, 300));
	label7->setPosition(Vec2(10, 200));
	label8->setPosition(Vec2(10, 150));
	label9->setPosition(Vec2(10, 100));

	this->addChild(label1);
	this->addChild(label2);
	this->addChild(label3);
	this->addChild(label4);
	this->addChild(label5);
	this->addChild(label6);
	this->addChild(label7);
	this->addChild(label8);
	this->addChild(label9);

	auto Label1 = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 70);

	Label1->setColor(Color3B::YELLOW);

	auto playItem = MenuItemLabel::create(Label1, CC_CALLBACK_1(AboutScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(420, -270));
	this->addChild(menu);
	return true;
}
void AboutScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}