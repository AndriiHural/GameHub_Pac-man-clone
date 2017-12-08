#ifndef __PAUSESCENE_H__
#define __PAUSESCENE_H__

#include "cocos2d.h"

class PauseScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(PauseScene);
	void Resume(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
	void Retry(Ref *pSender);
	void Exit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
