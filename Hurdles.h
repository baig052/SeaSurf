#ifndef __HURDLES_SCENE_H__
#define __HURDLES_SCENE_H__

#include "cocos2d.h"
#include "Ring.h"
#include "Hurdles.h"
#include "Dolphin.h"
#include "SeaAnimals.h"
 

class Hurdles : public cocos2d::Layer
{
public:

	virtual bool init();
	
	CREATE_FUNC(Hurdles);

private:	

	cocos2d::Layer *templayer;

	SeaAnimals *sea_animals;

	void SpawnRing( float dt );

	void SpawnAnimals( float dt );
	
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;

	~Hurdles();
	

};

#endif // __HURDLES_SCENE_H__
