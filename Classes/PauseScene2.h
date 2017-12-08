#ifndef __PAUSESCENE2_H__
#define __PAUSESCENE2_H__

#include "cocos2d.h"


class PauseScene2: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(PauseScene2);
	void Resume(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
	void Retry(Ref *pSender);
	void Exit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
