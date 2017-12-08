#ifndef __EXITSCENE_H__
#define __EXITSCENE_H__

#include "cocos2d.h"

class ExitScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(ExitScene);
	void Resume(Ref *pSender); 
	void Exit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
