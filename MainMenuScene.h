#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

static float co_ordX	=	0.50,
    co_ordY	=	1.50;
static float co_ordX_dol = 0.90,
	co_ordY_dol = 2.4;

class MainMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

	

private:
	void GoToGameScene(cocos2d::Ref *sender);
	void GoToLeaderBoard(cocos2d::Ref *sender);
	void GoToInAppPurchases(cocos2d::Ref *sender);
};

#endif // __MAIN_MENU_SCENE_H__
