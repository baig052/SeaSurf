#include "Ring_2.h"
#include "Definitions.h"


USING_NS_CC;

Ring_2::Ring_2()
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Ring_2::SpawnRing_2( cocos2d::Layer *layer)
{
	CCLOG("SPAWN RING-2");

	auto topRing = Sprite::create( "TopRing.png" );
	auto bottomRing = Sprite::create( "BottomRing.png" );



	auto topNode = Node::create();
	auto RingtopBody = PhysicsBody::createBox(  Size( 10 , 15 ) );
	RingtopBody->setDynamic( false );	
	RingtopBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingtopBody->setContactTestBitmask( true );
	topNode->setPhysicsBody( RingtopBody );
	topNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.72 + origin.y) );

	layer->addChild( topNode , 2 );

	auto topRingActionNode = MoveBy::create( SECOND_RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width  , 0 ));

	topNode->runAction( topRingActionNode );



	auto bottomNode = Node::create();
	auto RingbottomBody = PhysicsBody::createBox(  Size( 10 , 15 ) );
	RingbottomBody->setDynamic( false );	
	RingbottomBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingbottomBody->setContactTestBitmask( true );
	bottomNode->setPhysicsBody( RingbottomBody );
	bottomNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.58 + origin.y) );

	layer->addChild( bottomNode , 4 );

	auto bottomRingActionNode = MoveBy::create( SECOND_RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width  , 0 ));

	bottomNode->runAction( bottomRingActionNode );


	
	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	pointBody->setDynamic( true );
	pointBody->setCollisionBitmask( POINT_COLLISION_BITMASK );
	pointBody->setContactTestBitmask( true );

	pointNode->setPhysicsBody( pointBody );
	pointNode->setPosition(Point( (VisibleSize.width   + origin.x) * 1.015  , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( pointNode , 4 );

	auto pointActionNode = MoveBy::create( SECOND_RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width  , 0 ));

	pointNode->runAction( pointActionNode );


	
	topRing->setPosition( Point( (VisibleSize.width   + origin.x) * 1.015  , VisibleSize.height  * 0.65 + origin.y) );
	bottomRing->setPosition( Point( VisibleSize.width  + origin.x  , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( topRing , 3 );
	layer->addChild( bottomRing , 1 );

	auto topRingAction = MoveBy::create( (SECOND_RING_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width  , 0 ));
	auto bottomRingAction = MoveBy::create( SECOND_RING_MOVEMENT_SPEED * VisibleSize.width  , Point( -VisibleSize.width  , 0 ));

	topRing->runAction( topRingAction );
	bottomRing->runAction( bottomRingAction );

	


}