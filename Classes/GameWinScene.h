#ifndef __GAMEOWINSCENE_H__
#define __GAMEOWINSCENE_H__

#include "cocos2d.h"

class GameWinScene: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	CREATE_FUNC(GameWinScene);
	void GoToMainMenu(Ref *pSender);
	void GoToLevelScene(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
