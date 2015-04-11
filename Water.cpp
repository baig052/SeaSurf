#include "Water.h"
#include "Definitions.h"

USING_NS_CC;

bool Water::init()
{

	if(!Layer::init())
	{
		return false;
	}

	VisibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("background.png");

	auto waterSprite = Sprite::create("water.png");
	waterSprite->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.57);
	waterSprite->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.77);

	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	pointBody->setDynamic( true );
	pointBody->setCollisionBitmask( WATER_COLLISION_BITMASK );
	pointBody->setContactTestBitmask( true );

	pointNode->setPhysicsBody( pointBody );
	pointNode->setPosition(Point( (VisibleSize.width   + origin.x) * 0.30  , VisibleSize.height  * 0.48 + origin.y) );

	this->addChild( pointNode , 3 );

	waterSprite->setPosition( Point( VisibleSize.width / 2  + origin.x , VisibleSize.height / 2 * 0.48 + origin.y ) );

	this->addChild( waterSprite , 4 );
	
	return true;
}



