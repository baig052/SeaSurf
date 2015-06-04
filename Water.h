#ifndef __WATER_SCENE_H__
#define __WATER_SCENE_H__

#include "cocos2d.h"


class Water : public cocos2d::Layer
{
public:

	virtual bool init();
	
	CREATE_FUNC(Water);
	

	
private:
	cocos2d::Sprite *backgroundSprite;
	cocos2d::Sprite *ripple;

	cocos2d::Animation *animation;
	cocos2d::Animate *action;

	void update( float dt );
	cocos2d::Sprite *Water1;
	cocos2d::Sprite *Water2;

	void update_plants( float dt );
	cocos2d::Sprite *plant_1;
	cocos2d::Sprite *plant_2;


	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;
	
};
#endif // __WATER_SCENE_H__
