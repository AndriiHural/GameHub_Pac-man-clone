#ifndef __GAMEOVERSCENE_H__
#define __GAMEOVERSCENE_H__

#include "cocos2d.h"

class GameOverScene: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(GameOverScene);
	void Retry1(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
	void GoToExit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
