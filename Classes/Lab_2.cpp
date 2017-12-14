#include "Lab_2.h"
#include "SimpleAudioEngine.h"
#include "PauseScene2.h"
#include "GameOverScene1.h"


USING_NS_CC;


Scene* Lab_2::createScene()
{
	auto scene = Scene::createWithPhysics();

	auto layer = Lab_2::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);

	return scene;
}
bool Lab_2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 3. add your codes below...

	/*Background*/
	//create fild baground
	//way/st- can go
	//wall/zb-can`t go
	int start_cord_y = visibleSize.height - 30;

	for (int i = 0; i<n_row; i++) {
		int start_cord_x = 165;
		for (int j = 0; j<n_col; j++) {


			if (arr[i][j] == 0) {
				CCLOG("arr 0");
				auto wall = Sprite::create("pac_man/zb.png");
				wall->setAnchorPoint(Vec2(0, 0));
				wall->setPosition(Vec2(start_cord_x, start_cord_y));
				this->addChild(wall, -2);

				start_cord_x += 30;

			}
			if (arr[i][j] == 1) {
				CCLOG("arr 1");
				auto way = Sprite::create("pac_man/st.png");
				way->setAnchorPoint(Vec2(0, 0));
				way->setPosition(Vec2(start_cord_x, start_cord_y));
				this->addChild(way, -2);

				start_cord_x += 30;

			}


		}
		start_cord_y -= 30;
	}

	/*Pac-map*/
	sprite = Sprite::create("pac_man/pac5.png");
	sprite->setPosition(Vec2(255 + 45, visibleSize.height - 45));
	this->addChild(sprite, -1);

	auto body = PhysicsBody::createCircle
	(sprite->getContentSize().width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	sprite->setPhysicsBody(body);

	/*Enemy*/
	enemy = Sprite::create("bad_man/bup1.png");
	enemy->setPosition(Vec2(210, visibleSize.height - 45));
	this->addChild(enemy, -1);

	auto body_enemy = PhysicsBody::createCircle
	(enemy->getContentSize().width / 2);
	body_enemy->setContactTestBitmask(true);
	body_enemy->setDynamic(true);
	enemy->setPhysicsBody(body_enemy);
	/*Enemy1*/
	enemy1 = Sprite::create("bad_man/bup1.png");
	enemy1->setPosition(Vec2(660, visibleSize.height - 45));
	enemy1->setColor(Color3B::GREEN);
	this->addChild(enemy1, -1);

	auto body_enemy1 = PhysicsBody::createCircle
	(enemy1->getContentSize().width / 2);
	body_enemy1->setContactTestBitmask(true);
	body_enemy1->setDynamic(true);
	enemy1->setPhysicsBody(body_enemy1);

	/*listener onKeyPressed*/
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Lab_2::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	/*listener onKeyReleased*/
	auto listenerReleased = EventListenerKeyboard::create();
	listenerReleased->onKeyReleased = CC_CALLBACK_2(Lab_2::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerReleased, this);

	/*Update*/
	this->scheduleUpdate();
	this->schedule(schedule_selector(Lab_2::randomMoveEnemy), 0.08f);
	this->schedule(schedule_selector(Lab_2::randomMoveEnemy1), 0.08f);

	/*Menu pause*/
	auto playItem = MenuItemFont::create("||", CC_CALLBACK_1(Lab_2::GoToPauseScene, this));
	auto menu = Menu::create(playItem, NULL);
	menu->alignItemsVerticallyWithPadding(100);
	playItem->setPosition(Vec2(470, 280));
	this->addChild(menu, 3);

	//COLISION
	auto contactListener =
	EventListenerPhysicsContact::create();
	contactListener->onContactBegin =
	CC_CALLBACK_1(Lab_2::onContactBegin, this);
	this->getEventDispatcher()->
	addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}


void Lab_2::update(float dt)
{
	if (isKeyPressed) {
		Point p = sprite->getPosition();
		Animate *action;
		switch (KeyPressed)
		{
		case 28:// move up
		{
			auto up = Animation::create();
			up->addSpriteFrameWithFile("pac_man/up1.png");
			up->addSpriteFrameWithFile("pac_man/up2.png");
			up->setDelayPerUnit(0.1f / 2);
			action = Animate::create(up);
			if ((arr[can_go[0]][can_go[1]] == 1) && (can_go[9] == 0)) {
				if (can_go[8] < can_go[10])
				{
					can_go[8] = can_go[8] + can_go[11];
					p.y = p.y + can_go[11];
				}
				if (can_go[8] == can_go[10]) {
					can_go[0]--;
					can_go[2]--;
					can_go[4]--;
					can_go[6]--;
					can_go[8] = 0;
				}
			}
		}
		break;
		case 29://move down
		{
			auto down = Animation::create();
			down->addSpriteFrameWithFile("pac_man/down1.png");
			down->addSpriteFrameWithFile("pac_man/down2.png");
			down->setDelayPerUnit(0.1f / 2);
			action = Animate::create(down);
			if ((can_go[8] >0) && (can_go[9] == 0)) {
				p.y = p.y - can_go[11];
				can_go[8] = can_go[8] - can_go[11];
			}
			else {
				if ((arr[can_go[6]][can_go[7]] == 1) && (can_go[9] == 0)) {
					can_go[0]++;
					can_go[2]++;
					can_go[4]++;
					can_go[6]++;
					can_go[8] = can_go[10];
					p.y = p.y - can_go[11];
					can_go[8] = can_go[8] - can_go[11];
					//sprite->setPositionY(next_y);


				}
			}
		}
		break;
		case 26://move left
		{
			auto left = Animation::create();
			left->addSpriteFrameWithFile("pac_man/pac11.png");
			left->addSpriteFrameWithFile("pac_man/pac22.png");
			left->addSpriteFrameWithFile("pac_man/pac33.png");
			left->addSpriteFrameWithFile("pac_man/pac44.png");
			left->addSpriteFrameWithFile("pac_man/pac55.png");
			left->addSpriteFrameWithFile("pac_man/pac44.png");
			left->addSpriteFrameWithFile("pac_man/pac33.png");
			left->addSpriteFrameWithFile("pac_man/pac22.png");
			left->setDelayPerUnit(0.1f / 8);
			action = Animate::create(left);

			if ((can_go[9] >0) && (can_go[8] == 0)) {
				p.x = p.x - can_go[11];
				can_go[9] = can_go[9] - can_go[11];
			}
			else {
				if ((arr[can_go[2]][can_go[3]] == 1) && (can_go[8] == 0)) {
					can_go[1]--;
					can_go[3]--;
					can_go[5]--;
					can_go[7]--;
					can_go[9] = can_go[10];
					p.x = p.x - can_go[11];
					can_go[9] = can_go[9] - can_go[11];


				}
			}
		}
		break;
		case 27://move right
		{
			auto right = Animation::create();
			right->addSpriteFrameWithFile("pac_man/pac1.png");
			right->addSpriteFrameWithFile("pac_man/pac2.png");
			right->addSpriteFrameWithFile("pac_man/pac3.png");
			right->addSpriteFrameWithFile("pac_man/pac4.png");
			right->addSpriteFrameWithFile("pac_man/pac5.png");
			right->addSpriteFrameWithFile("pac_man/pac4.png");
			right->addSpriteFrameWithFile("pac_man/pac3.png");
			right->addSpriteFrameWithFile("pac_man/pac2.png");
			right->setDelayPerUnit(0.1f / 8);
			action = Animate::create(right);

			if ((arr[can_go[4]][can_go[5]] == 1) && (can_go[8] == 0)) {
				if (can_go[9] < can_go[10])
				{
					can_go[9] = can_go[9] + can_go[11];
					p.x = p.x + can_go[11];
				}
				if (can_go[9] == can_go[10]) {
					can_go[1]++;
					can_go[3]++;
					can_go[5]++;
					can_go[7]++;
					can_go[9] = 0;
				}
			}
		}
		break;
		default:
			break;
		}
		auto move = MoveTo::create(0.1f, Point(p));
		auto moveWithAnimation = Spawn::create(move, action, nullptr);
		sprite->runAction(moveWithAnimation);
	}




}


/*
The method determines which key is pressed and save numder key,
which is used to simulate the sticking of a key
*/
void Lab_2::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	CCLOG("Key press %d", keyCode);
	isKeyPressed = true;
	switch ((int)keyCode)
	{
	case 28:// ÒÚ≥ÎÍ‡ ‚ „ÓÛ
		KeyPressed = 28;
		break;
	case 29://ÒÚ≥ÎÍ‡ ‚ ‚ÌËÁ
		KeyPressed = 29;
		break;
	case 26://ÒÚ≥ÎÍ‡ ‚ Î≥‚Ó
		KeyPressed = 26;
		break;
	case 27://ÒÚ≥ÎÍ‡ ‚ Ô‡‚Ó
		KeyPressed = 27;
		break;
	default:
		break;
	}
}


/*
when you released key
*/
void Lab_2::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	isKeyPressed = false;
	KeyPressed = 9999;
}
/*Move enemy*/
void Lab_2::randomMoveEnemy(float df) {
	int arrows[4];
	/*check way when sprite  is on the fork*/
	/*up and down*/
	if ((arr[can_go_Enemy[0]][can_go_Enemy[1]] == 1) &&
		(arr[can_go_Enemy[6]][can_go_Enemy[7]] == 1))
	{
		if ((EnemyArrows != 28) && (EnemyArrows != 29) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 29;
			EnemyArrows = arrows[randomInt];
		}
	}
	/*right and left*/
	if ((arr[can_go_Enemy[2]][can_go_Enemy[3]] == 1) &&
		(arr[can_go_Enemy[4]][can_go_Enemy[5]] == 1))
	{
		if ((EnemyArrows != 26) && (EnemyArrows != 27) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 26;
			arrows[1] = 27;
			EnemyArrows = arrows[randomInt];
		}
	}
	/* up and right*/
	if ((arr[can_go_Enemy[0]][can_go_Enemy[1]] == 1) &&
		(arr[can_go_Enemy[4]][can_go_Enemy[5]] == 1))
	{
		if ((EnemyArrows != 28) && (EnemyArrows != 27) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 27;
			EnemyArrows = arrows[randomInt];
		}
	}
	/*up and left*/
	if ((arr[can_go_Enemy[0]][can_go_Enemy[1]] == 1) &&
		(arr[can_go_Enemy[2]][can_go_Enemy[3]] == 1))
	{
		if ((EnemyArrows != 26) && (EnemyArrows != 28) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 26;
			EnemyArrows = arrows[randomInt];
		}
	}
	/*right and down*/
	if ((arr[can_go_Enemy[4]][can_go_Enemy[5]] == 1) &&
		(arr[can_go_Enemy[6]][can_go_Enemy[7]] == 1))
	{
		if ((EnemyArrows != 27) && (EnemyArrows != 29) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 27;
			arrows[1] = 29;
			EnemyArrows = arrows[randomInt];
		}
	}
	/*left and down*/
	if ((arr[can_go_Enemy[2]][can_go_Enemy[3]] == 1) &&
		(arr[can_go_Enemy[6]][can_go_Enemy[7]] == 1))
	{
		if ((EnemyArrows != 27) && (EnemyArrows != 29) && (can_go_Enemy[8] == 0) && (can_go_Enemy[9] == 0)) {
			randomInt = (random(0, 1));
			arrows[0] = 26;
			arrows[1] = 29;
			EnemyArrows = arrows[randomInt];
		}
	}
	CCLOG("Random key %d,  %d", randomInt, EnemyArrows);




	Point p = enemy->getPosition();
	Point p_befor = p;
	switch (EnemyArrows)
	{
	case 28:// move up
		if ((arr[can_go_Enemy[0]][can_go_Enemy[1]] == 1) && (can_go_Enemy[9] == 0)) {
			if (can_go_Enemy[8] < can_go_Enemy[10])
			{
				can_go_Enemy[8] = can_go_Enemy[8] + can_go_Enemy[11];
				p.y = p.y + can_go_Enemy[11];
			}
			if (can_go_Enemy[8] == can_go_Enemy[10]) {
				can_go_Enemy[0]--;
				can_go_Enemy[2]--;
				can_go_Enemy[4]--;
				can_go_Enemy[6]--;
				can_go_Enemy[8] = 0;
			}
		}
		break;
	case 29://move down
		if ((can_go_Enemy[8] >0) && (can_go_Enemy[9] == 0)) {
			p.y = p.y - can_go_Enemy[11];
			can_go_Enemy[8] = can_go_Enemy[8] - can_go_Enemy[11];
		}
		else {
			if ((arr[can_go_Enemy[6]][can_go_Enemy[7]] == 1) && (can_go_Enemy[9] == 0)) {
				can_go_Enemy[0]++;
				can_go_Enemy[2]++;
				can_go_Enemy[4]++;
				can_go_Enemy[6]++;
				can_go_Enemy[8] = can_go_Enemy[10];
				p.y = p.y - can_go_Enemy[11];
				can_go_Enemy[8] = can_go_Enemy[8] - can_go_Enemy[11];
			}
		}
		break;
	case 26://move left
		if ((can_go_Enemy[9] >0) && (can_go_Enemy[8] == 0)) {
			p.x = p.x - can_go_Enemy[11];
			can_go_Enemy[9] = can_go_Enemy[9] - can_go_Enemy[11];
		}
		else {
			if ((arr[can_go_Enemy[2]][can_go_Enemy[3]] == 1) && (can_go_Enemy[8] == 0)) {
				can_go_Enemy[1]--;
				can_go_Enemy[3]--;
				can_go_Enemy[5]--;
				can_go_Enemy[7]--;
				can_go_Enemy[9] = can_go_Enemy[10];
				p.x = p.x - can_go_Enemy[11];
				can_go_Enemy[9] = can_go_Enemy[9] - can_go_Enemy[11];
			}
		}
		break;
	case 27:// move right
		if ((arr[can_go_Enemy[4]][can_go_Enemy[5]] == 1) && (can_go_Enemy[8] == 0)) {
			if (can_go_Enemy[9] < can_go_Enemy[10])
			{
				can_go_Enemy[9] = can_go_Enemy[9] + can_go_Enemy[11];
				p.x = p.x + can_go_Enemy[11];
			}
			if (can_go_Enemy[9] == can_go_Enemy[10]) {
				can_go_Enemy[1]++;
				can_go_Enemy[3]++;
				can_go_Enemy[5]++;
				can_go_Enemy[7]++;
				can_go_Enemy[9] = 0;
			}
		}
		break;
	default:
		break;
	}
	auto move = MoveTo::create(0.05f, Point(p));
	enemy->runAction(move);
	Point p_after = p;
	if (p_befor == p_after) {
		randomInt = 0;
		EnemyArrows = 0;
	}
}







void Lab_2::randomMoveEnemy1(float df) {
	int arrows[4];
	/*check way when sprite  is on the fork*/
	/*up and down*/
	if ((arr[can_go_Enemy1[0]][can_go_Enemy1[1]] == 1) &&
		(arr[can_go_Enemy1[6]][can_go_Enemy1[7]] == 1))
	{
		if ((EnemyArrows1 != 28) && (EnemyArrows1 != 29) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 29;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	/*right and left*/
	if ((arr[can_go_Enemy1[2]][can_go_Enemy1[3]] == 1) &&
		(arr[can_go_Enemy1[4]][can_go_Enemy1[5]] == 1))
	{
		if ((EnemyArrows1 != 26) && (EnemyArrows1 != 27) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 26;
			arrows[1] = 27;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	/* up and right*/
	if ((arr[can_go_Enemy1[0]][can_go_Enemy1[1]] == 1) &&
		(arr[can_go_Enemy1[4]][can_go_Enemy1[5]] == 1))
	{
		if ((EnemyArrows1 != 28) && (EnemyArrows1 != 27) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 27;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	/*up and left*/
	if ((arr[can_go_Enemy1[0]][can_go_Enemy1[1]] == 1) &&
		(arr[can_go_Enemy1[2]][can_go_Enemy1[3]] == 1))
	{
		if ((EnemyArrows1 != 26) && (EnemyArrows1 != 28) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 28;
			arrows[1] = 26;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	/*right and down*/
	if ((arr[can_go_Enemy1[4]][can_go_Enemy1[5]] == 1) &&
		(arr[can_go_Enemy1[6]][can_go_Enemy1[7]] == 1))
	{
		if ((EnemyArrows1 != 27) && (EnemyArrows1 != 29) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 27;
			arrows[1] = 29;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	/*left and down*/
	if ((arr[can_go_Enemy1[2]][can_go_Enemy1[3]] == 1) &&
		(arr[can_go_Enemy1[6]][can_go_Enemy1[7]] == 1))
	{
		if ((EnemyArrows1 != 27) && (EnemyArrows1 != 29) && (can_go_Enemy1[8] == 0) && (can_go_Enemy1[9] == 0)) {
			randomInt1 = (random(0, 1));
			arrows[0] = 26;
			arrows[1] = 29;
			EnemyArrows1 = arrows[randomInt1];
		}
	}
	CCLOG("Random key %d,  %d", randomInt1, EnemyArrows1);




	Point p1 = enemy1->getPosition();
	Point p1_befor = p1;
	switch (EnemyArrows1)
	{
	case 28:// move up
		if ((arr[can_go_Enemy1[0]][can_go_Enemy1[1]] == 1) && (can_go_Enemy1[9] == 0)) {
			if (can_go_Enemy1[8] < can_go_Enemy1[10])
			{
				can_go_Enemy1[8] = can_go_Enemy1[8] + can_go_Enemy1[11];
				p1.y = p1.y + can_go_Enemy1[11];
			}
			if (can_go_Enemy1[8] == can_go_Enemy1[10]) {
				can_go_Enemy1[0]--;
				can_go_Enemy1[2]--;
				can_go_Enemy[4]--;
				can_go_Enemy1[6]--;
				can_go_Enemy1[8] = 0;
			}
		}
		break;
	case 29://move down
		if ((can_go_Enemy1[8] >0) && (can_go_Enemy1[9] == 0)) {
			p1.y = p1.y - can_go_Enemy1[11];
			can_go_Enemy1[8] = can_go_Enemy1[8] - can_go_Enemy1[11];
		}
		else {
			if ((arr[can_go_Enemy1[6]][can_go_Enemy1[7]] == 1) && (can_go_Enemy1[9] == 0)) {
				can_go_Enemy1[0]++;
				can_go_Enemy1[2]++;
				can_go_Enemy1[4]++;
				can_go_Enemy1[6]++;
				can_go_Enemy1[8] = can_go_Enemy1[10];
				p1.y = p1.y - can_go_Enemy1[11];
				can_go_Enemy1[8] = can_go_Enemy1[8] - can_go_Enemy1[11];
			}
		}
		break;
	case 26://move left
		if ((can_go_Enemy1[9] >0) && (can_go_Enemy1[8] == 0)) {
			p1.x = p1.x - can_go_Enemy1[11];
			can_go_Enemy1[9] = can_go_Enemy1[9] - can_go_Enemy1[11];
		}
		else {
			if ((arr[can_go_Enemy1[2]][can_go_Enemy1[3]] == 1) && (can_go_Enemy1[8] == 0)) {
				can_go_Enemy1[1]--;
				can_go_Enemy1[3]--;
				can_go_Enemy1[5]--;
				can_go_Enemy1[7]--;
				can_go_Enemy1[9] = can_go_Enemy1[10];
				p1.x = p1.x - can_go_Enemy1[11];
				can_go_Enemy1[9] = can_go_Enemy1[9] - can_go_Enemy1[11];
			}
		}
		break;
	case 27:// move right
		if ((arr[can_go_Enemy1[4]][can_go_Enemy1[5]] == 1) && (can_go_Enemy1[8] == 0)) {
			if (can_go_Enemy1[9] < can_go_Enemy1[10])
			{
				can_go_Enemy1[9] = can_go_Enemy1[9] + can_go_Enemy1[11];
				p1.x = p1.x + can_go_Enemy1[11];
			}
			if (can_go_Enemy1[9] == can_go_Enemy1[10]) {
				can_go_Enemy1[1]++;
				can_go_Enemy1[3]++;
				can_go_Enemy1[5]++;
				can_go_Enemy1[7]++;
				can_go_Enemy1[9] = 0;
			}
		}
		break;
	default:
		break;
	}
	auto move1 = MoveTo::create(0.05f, Point(p1));
	enemy1->runAction(move1);
	Point p1_after = p1;
	if (p1_befor == p1_after) {
		randomInt = 0;
		EnemyArrows1 = 0;
	}
}





void Lab_2::GoToPauseScene(cocos2d::Ref *pSender)
{
	auto scene = PauseScene2::createScene();
	Director::getInstance()->pushScene(scene);
}
void Lab_2::GoToGameOverScene(cocos2d::Ref *pSender)
{
	auto scene = GameOverScene1::createScene();
	Director::getInstance()->replaceScene(scene);
}
// when pac-man touch enemy
bool Lab_2::onContactBegin(PhysicsContact& contact)
{
	GoToGameOverScene(this);
	return true;
}



