#ifndef __RING_2_SCENE_H__
#define __RING_2_SCENE_H__

#include "cocos2d.h"

class Ring_2
{
public:
	Ring_2();

	void SpawnRing_2( cocos2d::Layer *layer );

private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
};

#endif // __RING_2_SCENE_H__
