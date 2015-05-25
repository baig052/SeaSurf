#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Ring.h"
#include "Dolphin.h"
#include "Hurdles.h"
#include "Water.h"

static bool jumpflag;


class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
	
	

	

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *backgroundSprite;
	cocos2d::Sprite *ripple;
	cocos2d::Animation *animation;

	cocos2d::PhysicsWorld *sceneWorld;

	void setPhysicsWorld( cocos2d::PhysicsWorld *world) { sceneWorld = world ;  };
	
	bool onContactBegin( cocos2d::PhysicsContact &contact );

	bool onTouchBegan( cocos2d::Touch *touch , cocos2d::Event *event);
		
	/*void stopFlying( float dt );
	void update( float dt );*/

	unsigned int score;

	cocos2d::Label *scoreLabel;


};

#endif // __GAME_SCENE_H__
