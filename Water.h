#ifndef __WATER_SCENE_H__
#define __WATER_SCENE_H__

#include "cocos2d.h"



class Water : public cocos2d::Layer
{
public:

	virtual bool init();
	
	CREATE_FUNC(Water);
	
private:
	void update( float dt );
	cocos2d::CCSprite *Water1;
	cocos2d::CCSprite *Water2;

	void update_plants( float dt );
	cocos2d::CCSprite *plant_1;
	cocos2d::CCSprite *plant_2;


	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
	
};
#endif // __WATER_SCENE_H__
