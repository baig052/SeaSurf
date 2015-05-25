#include "Water.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;



bool Water::init()
{

	if(!Layer::init())
	{
		return false;
	}

	VisibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	backgroundSprite = Sprite::create("background.png");

	ripple = Sprite::create("ripple-1.png");
	ripple->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.40);
	ripple->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.40);
	ripple->setPosition( Point( (VisibleSize.width   + origin.x) * 0.30, VisibleSize.height / 2 * 0.92 + origin.y ));

	this->addChild( ripple , 5);

	animation = Animation::create();
	for( int i=1 ; i < 10 ; i++ )
	{
		char szName[100] = {0};
		sprintf(szName, "ripple/ripple-%00d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit( 2.0f / 9.0f );
	animation->setRestoreOriginalFrame(false);

	action = Animate::create(animation);
	auto seq  = Sequence::create( action , nullptr);
	ripple->runAction( RepeatForever::create(seq) );

	


	Water1 = CCSprite::create("water_new.png");
	Water1->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	Water1->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.75);

	Water1->setAnchorPoint(ccp(0, 0));
	Water1->setPosition(ccp(VisibleSize.width*0.0, VisibleSize.height*0));
	 this-> addChild(Water1, 4);

	Water2 = CCSprite::create("water_new.png");
	Water2->setAnchorPoint(ccp(0, 0));
	Water2->setPosition(ccp(0 - Water2->getContentSize().width, VisibleSize.height*0));

	Water2->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	Water2->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.75);
	this->addChild(Water2 ,4);
	 
	this->schedule(schedule_selector(Water::update));

	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	pointBody->setDynamic( true );
	pointBody->setCollisionBitmask( WATER_COLLISION_BITMASK );
	pointBody->setContactTestBitmask( true );

	pointNode->setPhysicsBody( pointBody );
	pointNode->setPosition(Point( (VisibleSize.width   + origin.x) * 0.30  , VisibleSize.height  * 0.48 + origin.y) );

	this->addChild( pointNode , 3 );
	

	//auto water_action = MoveBy::create( (WATER_FLOW_SPEED * VisibleSize.width) , -Point(VisibleSize.width , 0));

	//waterSprite->runAction(water_action);
	plant_1= CCSprite::create("bottom_plants.png");
	plant_1->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.56);
	plant_1->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	plant_1->setAnchorPoint(ccp(0, 0));
	plant_1->setPosition(ccp(0 - plant_1->getContentSize().width, VisibleSize.height*0));
	this->addChild(plant_1 , 5);

	plant_2 = CCSprite::create("bottom_plants.png");
	plant_2->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.56);
	plant_2->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	plant_2->setAnchorPoint(ccp(0, 0));
	plant_2->setPosition(ccp(0 - plant_2->getContentSize().width, VisibleSize.height*0));

	this->addChild(plant_2 , 5 );

	this->schedule(schedule_selector(Water::update_plants));


	return true;
}
void Water::update( float dt )
{
	Water1->setPosition( ccp(Water1->getPosition().x-3, Water1->getPosition().y) );
	Water2->setPosition( ccp(Water2->getPosition().x-3, Water2->getPosition().y) );

	if( Water1->getPosition().x < -Water1->boundingBox().size.width)
	{
		Water1->setPosition( ccp( Water2->getPosition().x + Water2->boundingBox().size.width, Water1->getPosition().y));
	}

	if( Water2->getPosition().x < -Water2->boundingBox().size.width){
	Water2->setPosition( ccp( Water1->getPosition().x + Water1->boundingBox().size.width, Water2->getPosition().y));
	}
}

void Water::update_plants( float dt )
{
	plant_1->setPosition( ccp(plant_1->getPosition().x-3, plant_1->getPosition().y) );
	plant_2->setPosition( ccp(plant_2->getPosition().x-3, plant_2->getPosition().y) );

	if( plant_1->getPosition().x < -plant_1->boundingBox().size.width)
	{
		plant_1->setPosition( ccp( plant_2->getPosition().x + plant_2->boundingBox().size.width, plant_1->getPosition().y));
	}

	if( plant_2->getPosition().x < -plant_2->boundingBox().size.width)
	{
		plant_2->setPosition( ccp( plant_1->getPosition().x + plant_1->boundingBox().size.width, plant_2->getPosition().y));
	}
}




