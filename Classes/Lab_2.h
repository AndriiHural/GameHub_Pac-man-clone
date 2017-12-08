#ifndef __LAB_2_H__
#define _LAB_2_H__

#include "cocos2d.h"


class Lab_2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(Lab_2);
	void GoToPauseScene(Ref *pSender);
	void GoToGameOverScene(Ref *pSender);
	void GoToGameScene(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
