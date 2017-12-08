#ifndef __LAB_3_H__
#define __LAB_3_H__

#include "cocos2d.h"


class Lab_3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(Lab_3);
	void GoToPauseScene(Ref *pSender);
	void GoToGameOverScene(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
