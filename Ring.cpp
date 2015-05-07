#include "Ring.h"
#include "Definitions.h"
#include "MainMenuScene.h"


USING_NS_CC;

Ring::Ring()
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}
Ring::~Ring()
{
}


void Ring::SpawnRing( cocos2d::Layer *layer)
{
	CCLOG("SPAWN RING");
	 auto backgroundSprite = Sprite::create("Background.png");


	auto topRing = Sprite::create( "TopRing.png" );
	//topRing->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	//topRing->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * co_ordY);

	auto bottomRing = Sprite::create( "BottomRing.png" );
	//bottomRing->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	//bottomRing->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * co_ordY);



	auto topNode = Node::create();
	auto RingtopBody = PhysicsBody::createBox(  Size( 10 , 15 ) );
	RingtopBody->setDynamic( false );	
	RingtopBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingtopBody->setContactTestBitmask( true );
	topNode->setPhysicsBody( RingtopBody );
	topNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.72 + origin.y) );

	layer->addChild( topNode , 2 ,"UpperNode" );

	auto topRingActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * 1.7 , 0 ));

	topNode->runAction( topRingActionNode );



	auto bottomNode = Node::create();
	auto RingbottomBody = PhysicsBody::createBox(  Size( 10 , 15 ) );
	RingbottomBody->setDynamic( false );	
	RingbottomBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingbottomBody->setContactTestBitmask( true );
	bottomNode->setPhysicsBody( RingbottomBody );
	bottomNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.58 + origin.y) );

	layer->addChild( bottomNode , 4  , "BottomNode");

	auto bottomRingActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * 1.7, 0 ));

	bottomNode->runAction( bottomRingActionNode );


	
	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox( Size( 5, 5) ) ;

	pointBody->setDynamic( true );
	pointBody->setCollisionBitmask( POINT_COLLISION_BITMASK );
	pointBody->setContactTestBitmask( true );

	pointNode->setPhysicsBody( pointBody );
	pointNode->setPosition(Point( (VisibleSize.width   + origin.x) * 1.015  , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( pointNode , 4  , "PointNode");

	auto pointActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * 1.7 , 0 ));

	pointNode->runAction( pointActionNode );


	
	topRing->setPosition( Point( (VisibleSize.width   + origin.x) * 1.015  , VisibleSize.height  * 0.65 + origin.y) );
	bottomRing->setPosition( Point( VisibleSize.width  + origin.x  , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( topRing , 3 ,"TopRing" );
	layer->addChild( bottomRing , 1 , "BottomRing" );

	auto topRingAction = MoveBy::create( (RING_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width *  1.7 , 0 ));
	auto bottomRingAction = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width  , Point( -VisibleSize.width * 1.7 , 0 ));

	topRing->runAction( topRingAction );
	bottomRing->runAction( bottomRingAction );

	auto DeletionNode = Node::create();
	auto DeletionBody = PhysicsBody::createBox( Size( 25, 4) ) ;

	DeletionBody->setDynamic( true );
	DeletionBody->setCollisionBitmask( DELETION_COLLISION_BITMASK );
	DeletionBody->setContactTestBitmask( true );

	DeletionNode->setPhysicsBody( DeletionBody );
	DeletionNode->setPosition(Point( VisibleSize.width * 0.02   + origin.x   , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( DeletionNode , 5  , "DeletionNode");

	


}