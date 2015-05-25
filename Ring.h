#ifndef __RING_SCENE_H__
#define __RING_SCENE_H__

#include "cocos2d.h"

class Ring 
{
public:
	Ring();
	~Ring();
	void SpawnRing( cocos2d::Layer *layer );
	cocos2d::Sprite *topRing;
	cocos2d::Sprite *bottomRing;
	cocos2d::Node *pointNode;
	cocos2d::Node *topNode;
	cocos2d::Node *bottomNode;

private:
	cocos2d::Size VisibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *backgroundSprite;
	
	cocos2d::Node *DeletionNode;
	
	cocos2d::MoveBy *topRingAction;
	cocos2d::MoveBy *bottomRingAction;



};

#endif // __RING_SCENE_H__
