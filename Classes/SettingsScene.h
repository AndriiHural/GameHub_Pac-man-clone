#ifndef __SETTINGSSCENE_H__
#define _SETTINGSSCENE_H__

#include "cocos2d.h"


class SettingsScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SettingsScene);
	void GoToMainMenu(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
