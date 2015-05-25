#include "SeaAnimals.h"
#include "Definitions.h"


USING_NS_CC;



SeaAnimals::SeaAnimals()
{
	VisibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

}


void SeaAnimals::SpawnAnimals( cocos2d::Layer *layer )
{
	templay= layer ;
	auto backgroundSprite = Sprite::create("Background.png");
	a = 2.0 ;
	rand_1 = ((float)rand()/(float)(RAND_MAX)) * a;
	while( rand_1 < 1.2000 )
	{
		rand_1 = ((float)rand()/(float)(RAND_MAX)) * a;

	}
	a = 2;
	rand_2 = ((float)rand()/(float)(RAND_MAX)) * a;
	while( rand_2 < 1.2000 )
	{
		rand_2 = ((float)rand()/(float)(RAND_MAX)) * a;

	}
	
	blue_fish = Sprite::create("blue_fish.png");
	blue_fish->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	blue_fish->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	blue_fish->setPosition(	Point(	(VisibleSize.width + origin.x) * 1.2 ,	VisibleSize.height / 2	* 0.65 + origin.y	)	);

	auto blue_fish_Action = MoveBy::create( (FISH_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width * rand_2 , 0 ));

	blue_fish->runAction(blue_fish_Action);

	
	layer->addChild( blue_fish ,2 );

	auto gold_fish = Sprite::create("goldfish_2.png");
	gold_fish->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	gold_fish->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	gold_fish->setPosition(	Point(	(VisibleSize.width + origin.x)  ,	VisibleSize.height / 2	* 0.50 + origin.y	)	);

	auto gold_fish_Action = MoveTo::create( (FISH_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width * 1.50 , 0 ));

	gold_fish->runAction(gold_fish_Action);

	
	layer->addChild( gold_fish ,2 );


	auto seahorse = Sprite::create("sea_horse.png");
	seahorse->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	seahorse->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	seahorse->setPosition(	Point(	(VisibleSize.width + origin.x) * 1.5 ,	VisibleSize.height / 2	* 0.20 + origin.y	)	);

	auto seahorse_Action = MoveBy::create( (FISH_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width * rand_2  , 0 ));

	seahorse->runAction(seahorse_Action);

	
	layer->addChild( seahorse ,2 );

	auto DeletionNode = Node::create();
	auto DeletionBody = PhysicsBody::createBox( Size( 0, 0) ) ;

	//DeletionBody->setDynamic( false );
	DeletionBody->setCollisionBitmask( SNAKE_DELETION_COLLISION_BITMASK );
	DeletionBody->setContactTestBitmask( true );

	DeletionNode->setPhysicsBody( DeletionBody );
	DeletionNode->setPosition(Point( VisibleSize.width * 0.02  + origin.x   , VisibleSize.height / 2  * 0.97 + origin.y) );
	DeletionNode->setTag(DELETE_TAG);

	layer->addChild( DeletionNode , 5 );

	
	 
	snake= CCSprite::create("snake-1.png");
	snake->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.65);
	snake->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	//snake->setAnchorPoint( ccp(( VisibleSize.width + origin.x ) * rand_1 , VisibleSize .height /2 * 0.92 + origin.y ) );

	//layer->scheduleUpdate(schedule_selector( SeaAnimals::update) );
	snake->setPosition( Point( (VisibleSize.width   + origin.x) * rand_1 , VisibleSize.height / 2 * 0.92 + origin.y ) );

	snakeBody = PhysicsBody::createBox( Size ( 20 , 0 ) );

	snakeBody->setCollisionBitmask( SNAKE_COLLISION_BITMASK );
	snakeBody->setContactTestBitmask( true );

	//snakeBody->setDynamic( true );

	snake->setPhysicsBody( snakeBody );

	auto snake_Action = MoveBy::create( 0.003 * VisibleSize.width, Point( -VisibleSize.width * rand_1 , 0 ) );

	//MoveBy::create( (SNAKE_MOVEMENT_SPEED * VisibleSize.width ) , Point( -VisibleSize.width * rand_1 , 0 ));


	animation = Animation::create();
    for( int i=1 ; i < 11 ; i++ )
    {
        char szName[100] = {0};
        sprintf(szName, "snake/snake-%00d.png", i);
        animation->addSpriteFrameWithFile(szName);
    }
    animation->setDelayPerUnit( 1.0f / 11.0f );
	animation->setRestoreOriginalFrame(false);

    auto action = Animate::create(animation);
	auto seq  = Sequence::create( action , nullptr);
	snake->runAction(RepeatForever::create( seq ) );

	snake->runAction( snake_Action );
	snake->setTag(SNAKE_TAG);

	layer->addChild(snake , 5 ,"snake");


}





