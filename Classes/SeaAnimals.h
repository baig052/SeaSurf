#ifndef __SEA_ANIMALS_SCENE_H__
#define __SEA_ANIMALS_SCENE_H__

#include "cocos2d.h"

class SeaAnimals 
{
public:
	SeaAnimals();

	void SpawnAnimals( cocos2d::Layer *layer );

private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
};

#endif // __SEA_ANIMALS_SCENE_H__
