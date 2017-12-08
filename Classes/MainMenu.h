#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(MainMenu);
	void GoToGameScene(Ref *pSender); 
	void GoToLevelScene(Ref *pSender);
	void GoToAboutScene(Ref *pSender);
	void GoToSettingsScene(Ref *pSender);
	void GoToExitScene(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
