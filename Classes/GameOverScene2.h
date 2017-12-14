#ifndef __GAMEOVERSCENE2_H__
#define __GAMEOVERSCENE2_H__

#include "cocos2d.h"

class GameOverScene2: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(GameOverScene2);
	void Retry(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
	void GoToExit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
