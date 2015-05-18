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

	cocos2d::Sprite *snake;
	cocos2d::PhysicsBody *snakeBody;
	cocos2d::Animation *animation;

	int a;
	float rand_1;
	float rand_2;
	float rand_3;

	void update( float dt );

	

};

#endif // __SEA_ANIMALS_SCENE_H__
