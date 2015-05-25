#include "Ring.h"
#include "Definitions.h"
#include "MainMenuScene.h"


USING_NS_CC;

Ring::Ring()
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	backgroundSprite = Sprite::create("Background.png");

}
Ring::~Ring()
{

}


void Ring::SpawnRing( cocos2d::Layer *layer)
{
	CCLOG("SPAWN RING");

	float a= 2.2;
	float random = ((float)rand()/(float)(RAND_MAX)) * a;

	while( random < 1.7000 )
	{
		random = ((float)rand()/(float)(RAND_MAX)) * a;

	}

	topRing = Sprite::create( "TopRing.png" );
	topRing->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	topRing->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	topRing->setTag(TOP_RING_TAG);

	bottomRing = Sprite::create( "BottomRing.png" );
	bottomRing->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	bottomRing->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	bottomRing->setTag(BOTTOM_RING_TAG);



	topNode = Node::create();
	auto RingtopBody = PhysicsBody::createBox(  Size( 0 , 0 ) );
	//RingtopBody->setDynamic( false );	
	RingtopBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingtopBody->setContactTestBitmask( true );
	topNode->setPhysicsBody( RingtopBody );
	topNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.72 + origin.y) );
	topNode->setTag(RING_TOP_NODE_TAG);

	layer->addChild( topNode , 4 ,"UpperNode" );

	auto topRingActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * random , 0 ));

	topNode->runAction( topRingActionNode );



	bottomNode = Node::create();
	auto RingbottomBody = PhysicsBody::createBox(  Size( 0 ,0 ) );
	//RingbottomBody->setDynamic( false );	
	RingbottomBody->setCollisionBitmask( UPPER_RING_COLLISION_BITMASK );
	RingbottomBody->setContactTestBitmask( true );
	bottomNode->setPhysicsBody( RingbottomBody );
	bottomNode->setPosition( Point( (VisibleSize.width   + origin.x) * 1.007  , VisibleSize.height  * 0.58 + origin.y) );
	bottomNode->setTag(RING_BOTTOM_NODE_TAG);

	layer->addChild( bottomNode , 4  , "BottomNode");

	auto bottomRingActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * random , 0 ));

	bottomNode->runAction( bottomRingActionNode );


	
	pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	//pointBody->setDynamic( true );
	pointBody->setCollisionBitmask( POINT_COLLISION_BITMASK );
	pointBody->setContactTestBitmask( true );

	pointNode->setPhysicsBody( pointBody );
	pointNode->setPosition(Point( (VisibleSize.width   + origin.x) * 1.015  , VisibleSize.height  * 0.64 + origin.y) );
	pointNode->setTag(POINT_TAG);

	layer->addChild( pointNode , 4  , "PointNode");

	auto pointActionNode = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width , Point( -VisibleSize.
		width * random , 0 ));

	pointNode->runAction( pointActionNode );


	
	topRing->setPosition( Point( (VisibleSize.width   + origin.x) * 1.014   , VisibleSize.height  * 0.65 + origin.y) );
	bottomRing->setPosition( Point( VisibleSize.width  + origin.x  , VisibleSize.height  * 0.65 + origin.y) );

	layer->addChild( topRing , 3 ,"TopRing" );
	layer->addChild( bottomRing , 2 , "BottomRing" );

	topRingAction = MoveBy::create( (RING_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width *  random , 0 ));
	bottomRingAction = MoveBy::create( RING_MOVEMENT_SPEED * VisibleSize.width  , Point( -VisibleSize.width * random , 0 ));

	topRing->runAction( topRingAction );
	bottomRing->runAction( bottomRingAction );

	DeletionNode = Node::create();
	auto DeletionBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	//DeletionBody->setDynamic( true );
	DeletionBody->setCollisionBitmask( DELETION_COLLISION_BITMASK );
	DeletionBody->setContactTestBitmask( true );

	DeletionNode->setPhysicsBody( DeletionBody );
	DeletionNode->setPosition(Point( VisibleSize.width * 0.02  + origin.x   , VisibleSize.height  * 0.64 + origin.y) );
	DeletionNode->setTag(RING_DELETE_TAG);

	layer->addChild( DeletionNode , 5  , "DeletionNode");

	


}