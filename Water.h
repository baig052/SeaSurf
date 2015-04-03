#ifndef __WATER_SCENE_H__
#define __WATER_SCENE_H__

#include "cocos2d.h"



class Water : public cocos2d::Layer
{
public:

	virtual bool init();
	
	CREATE_FUNC(Water);
	
private:

	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
	
};
#endif // __WATER_SCENE_H__
