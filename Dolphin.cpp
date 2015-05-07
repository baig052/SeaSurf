#include "Dolphin.h"
#include "Definitions.h"
#include "MainMenuScene.h"


USING_NS_CC;

Dolphin::Dolphin( cocos2d::Layer *layer)
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	 auto backgroundSprite = Sprite::create("Background.png");

	 dolphin = Sprite::create( "dolphin.png" );
	dolphin->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * co_ordX_dol);
	dolphin->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * co_ordY_dol);
	dolphin->setPosition( Point( (VisibleSize.width   + origin.x) * 0.30, VisibleSize.height / 2 * 0.96 + origin.y ));

	auto dolphinBody = PhysicsBody::createCircle( dolphin->getContentSize().width / 7 );
	
	dolphinBody->setCollisionBitmask( DOLPHIN_COLLISION_BITMASK );
	dolphinBody->setContactTestBitmask( true );

	dolphin->setPhysicsBody( dolphinBody );


	layer->addChild( dolphin , 3 );

	auto animation = Animation::create();
    for( int i=1 ; i < 4 ; i++ )
    {
        char szName[100] = {0};
        sprintf(szName, "Animation/Animation-%00d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    animation->setDelayPerUnit( 0.2f / 3.0f );
	animation->setRestoreOriginalFrame(false);

    auto action = Animate::create(animation);
	auto seq  = Sequence::create( action , action->reverse() , nullptr);
	dolphin->runAction(RepeatForever::create( seq ) );
		//isFalling = true ;




}

void Dolphin::Jump()
{	
	auto rotateUp = RotateBy::create(0.2f, -45.0f);
    auto actionUp = JumpBy::create( 1.2 , Vec2(0,0), 110, 1);
	auto rotateStraight = RotateBy::create(0.3f , 45.0f);
	auto rotateStraight_2 = RotateBy::create(0.2f , -45.0f);
	auto rotateDown = RotateTo::create( 0.7f , 45.0f );
	auto group = Spawn::create(actionUp , rotateStraight , rotateDown  ,  nullptr );
	
	auto seq = Sequence::create( rotateUp , group ,rotateStraight_2,nullptr);
     
	dolphin->runAction( seq );

}

//void Dolphin::Fall( )
//{
//	if( true == isFalling )
//	{
//		dolphin->setPositionX( VisibleSize.width / 2 +origin.x );
//		dolphin->setPositionY( dolphin->getPositionY() - ( DOLPHIN_FALLING_SPEED * VisibleSize.height ));
//	}
//	else
//	{
//		dolphin->setPositionX( VisibleSize.width / 2 +origin.x );
//		dolphin->setPositionY( dolphin->getPositionY() + ( DOLPHIN_FALLING_SPEED * VisibleSize.height ));
//	}
//}



