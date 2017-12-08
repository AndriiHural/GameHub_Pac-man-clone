#ifndef __ABOUTSCENE_H__
#define _ABOUTSCENE_H__

#include "cocos2d.h"


class AboutScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(AboutScene);
	void GoToMainMenu(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
