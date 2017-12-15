#ifndef __GAMEOVERSCENE1_H__
#define __GAMEOVERSCENE1_H__

#include "cocos2d.h"

class GameOverScene1: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(GameOverScene1);
	void Retry2(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
	void GoToExit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
