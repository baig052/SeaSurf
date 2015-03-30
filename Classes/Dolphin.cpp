#include "Dolphin.h"
#include "Definitions.h"


USING_NS_CC;

Dolphin::Dolphin( cocos2d::Layer *layer)
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	

	dolphin = Sprite::create( "dolphin.png" );
	dolphin->setPosition( Point( (VisibleSize.width   + origin.x) * 0.30, VisibleSize.height / 2 + origin.y ));

	auto dolphinBody = PhysicsBody::createCircle( dolphin->getContentSize().width / 5 );
	dolphinBody->setCollisionBitmask( DOLPHIN_COLLISION_BITMASK );
	dolphinBody->setContactTestBitmask( true );

	dolphin->setPhysicsBody( dolphinBody );


	layer->addChild( dolphin , 3 );

	auto animation = Animation::create();
    for( int i=1 ; i < 5 ; i++ )
    {
        char szName[100] = {0};
        sprintf(szName, "Animation/Animation-%00d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    // should last 2.8 seconds. And there are 14 frames.
    animation->setDelayPerUnit( 0.5f / 3.0f );
	animation->setRestoreOriginalFrame(false);

    auto action = Animate::create(animation);
	dolphin->runAction(RepeatForever::create( action ) );

}

void Dolphin::Jump()
{	

    auto actionUp = JumpBy::create( 1.3 , Vec2(0,0), 100, 1);
     
	dolphin->runAction( actionUp );

}



