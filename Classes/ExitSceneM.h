#ifndef __EXITSCENEM_H__
#define __EXITSCENEM_H__

#include "cocos2d.h"

class ExitSceneM : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(ExitSceneM);
	void Resume(Ref *pSender); 
	void Exit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
