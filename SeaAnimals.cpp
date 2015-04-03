#include "SeaAnimals.h"
#include "Definitions.h"


USING_NS_CC;

SeaAnimals::SeaAnimals()
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void SeaAnimals::SpawnAnimals( cocos2d::Layer *layer)
{
	CCLOG("SPAWN ANIMALS");

	auto backgroundSprite = Sprite::create("Background.png");


	auto lobster = Sprite::create( "SeaAnimal_1.png" );
	lobster->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	lobster->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);
	
	auto lobsterBody = PhysicsBody::createBox(  Size( 10 , 15 ) );
	lobsterBody->setDynamic( true );	
	lobsterBody->setCollisionBitmask( LOBSTER_COLLISION_BITMASK );
	lobsterBody->setContactTestBitmask( true );
	lobster->setPhysicsBody( lobsterBody );

	layer->addChild( lobster , 2 );

	lobster->setPosition( Point( (VisibleSize.width   + origin.x) * 1.2  , VisibleSize.height / 2  * 0.80 + origin.y) );

	auto lobsterAction = MoveBy::create( (ANIMALS_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width * 1.5 , 0 ));

	auto UpDownAction = MoveBy::create( (ANIMALS_VERTICAL_MOVEMENT_SPEED *  VisibleSize.height) ,
		Point (0 , VisibleSize.height/2 * 0.10  )  );


	auto action = RepeatForever::create(Sequence::create(lobsterAction , UpDownAction , UpDownAction->reverse() ,  nullptr));

	lobster->runAction( action  );

}