#include "SettingsScene.h"
#include "ui/CocosGUI.h"
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

	auto bg = Sprite::create("bgG.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));
	this->addChild(bg, -1);

	auto Label1 = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 70);

	Label1->setColor(Color3B::YELLOW);

	auto playItem = MenuItemLabel::create(Label1, CC_CALLBACK_1(SettingsScene::GoToMainMenu, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(420, -260));
	this->addChild(menu);

	/*slider move speed  pac-man*/
	auto slider = ui::Slider::create("slider/sliderTrack.png", "slider/sliderThumb.png");
	slider->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			CCLOG("Slider move");
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	slider->addEventListener([](Ref* sender, ui::Slider::EventType type) {
		auto  slider = dynamic_cast<ui::Slider*>(sender);
		if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
			CCLOG("pres = %d", slider->getPercent());
		}
	});
	slider->setPosition(Vec2(200, 200));
	this->addChild(slider, -1);


	return true;
}
void SettingsScene::GoToMainMenu(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}