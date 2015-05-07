#ifndef __RING_SCENE_H__
#define __RING_SCENE_H__

#include "cocos2d.h"

class Ring 
{
public:
	Ring();
	~Ring();
	void SpawnRing( cocos2d::Layer *layer );

private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
};

#endif // __RING_SCENE_H__
