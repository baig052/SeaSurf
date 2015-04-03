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

		
private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *dolphin;
};

#endif // __DOLPHIN_SCENE_H__
