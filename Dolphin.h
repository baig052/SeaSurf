#ifndef __DOLPHIN_SCENE_H__
#define __DOLPHIN_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

class Dolphin
{
public:
	Dolphin(cocos2d::Layer *layer);

	void Jump() ;

	//void Fall( );

	//void Fly() {  //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Wing.mp3" );
	//isFalling = false ; }
	//void stopFlying() { isFalling = true; } 


		
private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *dolphin;

//	bool isFalling;

	
};

#endif // __DOLPHIN_SCENE_H__
