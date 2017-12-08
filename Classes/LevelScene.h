#ifndef __LEVELSCENE_H__
#define __LEVELSCENE_H__

#include "cocos2d.h"


class LevelScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(LevelScene);
	void GoToLab_1(Ref *pSender);
	void GoToLab_2(Ref *pSender);
	void GoToLab_3(Ref *pSender);
	void GoToMainMenu(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
