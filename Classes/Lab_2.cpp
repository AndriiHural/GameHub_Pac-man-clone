#include "Lab_2.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "PauseScene2.h"

USING_NS_CC;

Scene* Lab_2::createScene()
{
	auto scene = Scene::create();
	auto layer = Lab_2::create();
	scene->addChild(layer);
	return scene;
}
bool Lab_2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto badsprite = Sprite::create("5.png");
	auto sprite = Sprite::create("Idle (1).png");
	auto background = Sprite::create("2.jpg");
	background->setAnchorPoint(Vec2(0, 0));
	sprite->setAnchorPoint(Vec2(1, 0));
	badsprite->setAnchorPoint(Vec2(0.5, 0));
	sprite->setPosition(Vec2(100, 70));
	background->setPosition(Vec2(0, 0));
	badsprite->setPosition(Vec2(1000, 600));
	sprite->setScale(0.2);
	background->setScale(0.9);
	badsprite->setScale(0.1);


	auto idle = Animation::create();
	idle->addSpriteFrameWithFile("Idle (1).png");
	idle->addSpriteFrameWithFile("Idle (2).png");
	idle->addSpriteFrameWithFile("Idle (3).png");
	idle->addSpriteFrameWithFile("Idle (4).png");
	idle->addSpriteFrameWithFile("Idle (5).png");
	idle->addSpriteFrameWithFile("Idle (6).png");
	idle->addSpriteFrameWithFile("Idle (7).png");
	idle->addSpriteFrameWithFile("Idle (8).png");
	idle->addSpriteFrameWithFile("Idle (9).png");
	idle->addSpriteFrameWithFile("Idle (10).png");
	idle->setDelayPerUnit(0.2f);

	auto walk = Animation::create();
	walk->addSpriteFrameWithFile("Walk (1).png");
	walk->addSpriteFrameWithFile("Walk (2).png");
	walk->addSpriteFrameWithFile("Walk (3).png");
	walk->addSpriteFrameWithFile("Walk (4).png");
	walk->addSpriteFrameWithFile("Walk (5).png");
	walk->addSpriteFrameWithFile("Walk (6).png");
	walk->addSpriteFrameWithFile("Walk (7).png");
	walk->addSpriteFrameWithFile("Walk (8).png");
	walk->addSpriteFrameWithFile("Walk (9).png");
	walk->addSpriteFrameWithFile("Walk (10).png");
	walk->setDelayPerUnit(0.2f);

	auto jump = Animation::create();
	jump->addSpriteFrameWithFile("Jump (1).png");
	jump->addSpriteFrameWithFile("Jump (2).png");
	jump->addSpriteFrameWithFile("Jump (3).png");
	jump->addSpriteFrameWithFile("Jump (4).png");
	jump->addSpriteFrameWithFile("Jump (5).png");
	jump->addSpriteFrameWithFile("Jump (6).png");
	jump->addSpriteFrameWithFile("Jump (7).png");
	jump->addSpriteFrameWithFile("Jump (8).png");
	jump->addSpriteFrameWithFile("Jump (9).png");
	jump->addSpriteFrameWithFile("Jump (10).png");
	jump->setDelayPerUnit(0.2f);

	auto dead = Animation::create();
	dead->addSpriteFrameWithFile("Dead (1).png");
	dead->addSpriteFrameWithFile("Dead (2).png");
	dead->addSpriteFrameWithFile("Dead (3).png");
	dead->addSpriteFrameWithFile("Dead (4).png");
	dead->addSpriteFrameWithFile("Dead (5).png");
	dead->addSpriteFrameWithFile("Dead (6).png");
	dead->addSpriteFrameWithFile("Dead (7).png");
	dead->addSpriteFrameWithFile("Dead (8).png");
	dead->addSpriteFrameWithFile("Dead (9).png");
	dead->addSpriteFrameWithFile("Dead (10).png");
	dead->setDelayPerUnit(0.2f);

	auto delay34 = DelayTime::create(34);
	auto delay2 = DelayTime::create(2);
	auto delay0 = DelayTime::create(0);
	auto delay01 = DelayTime::create(0.1);
	auto move1 = MoveTo::create(2, Vec2(155, 70));
	auto move2 = MoveTo::create(2, Vec2(295, 150));
	auto move3 = MoveTo::create(2, Vec2(355, 150));
	auto move4 = MoveTo::create(2, Vec2(515, 270));
	auto move5 = MoveTo::create(2, Vec2(595, 270));
	auto move6 = MoveTo::create(2, Vec2(670, 270));
	auto move7 = MoveTo::create(2, Vec2(795, 150));
	auto move8 = MoveTo::create(2, Vec2(820, 300));
	auto move9 = MoveTo::create(2, Vec2(900, 180));
	auto move0 = MoveBy::create(1, Vec2(-8, -8));
	auto jump1 = JumpBy::create(2, Vec2(80, 80), 50, 1);
	auto jump2 = JumpBy::create(2, Vec2(80, 120), 50, 1);
	auto jump3 = JumpBy::create(2, Vec2(50, -110), 60, 1);
	auto out = FadeOut::create(2.0f);
	auto scale = ScaleTo::create(2, 0.4);

	Animate* aidle = Animate::create(idle);
	Animate* awalk = Animate::create(walk);
	Animate* ajump = Animate::create(jump);
	Animate* adead = Animate::create(dead);
	sprite->runAction(Sequence::create(delay2, move1, delay2, jump1, delay2, move2, delay0, move3, delay2, jump2, delay2,
		move4, delay0, move5, delay0, move6, delay2, jump3, delay2, move7, delay2, jump3, delay2, move8, delay0, nullptr));
	sprite->runAction(Sequence::create(aidle, delay0, awalk, delay0, aidle, delay0, ajump, delay0, aidle, delay0, awalk, delay0, awalk, delay0, aidle, delay0, ajump, delay0, aidle, delay0,
		awalk, delay0, awalk, delay0, awalk, delay0, aidle, delay0, ajump, delay0, aidle, delay0, awalk, delay0, aidle, delay0, ajump, delay0, adead, delay0, out, delay0, nullptr));
	badsprite->runAction(Sequence::create(delay34, move9, delay0, nullptr));
	badsprite->runAction(Sequence::create(delay34, scale, delay0, nullptr));
	background->runAction(Sequence::create(delay34, delay2, delay01, move0, delay0, move0->reverse(), nullptr));
	this->addChild(sprite, 2);
	this->addChild(background, 1);
	this->addChild(badsprite, 3);
	
	auto playItem = MenuItemFont::create("||", CC_CALLBACK_1(Lab_2::GoToGameScene, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(470, 280));
	this->addChild(menu,4);
	return true;
}
void Lab_2::GoToGameScene(cocos2d::Ref *pSender)
{
	auto scene = PauseScene2::createScene();
	Director::getInstance()->pushScene(scene);
}
void Lab_2::GoToGameOverScene(cocos2d::Ref *pSender)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}