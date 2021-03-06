#include "GameScene.h"
#include "cocos2d.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "Dolphin.h"
#include "Hurdles.h"
#include "Ring.h"
#include "SeaAnimals.h"

USING_NS_CC;

extern Dolphin *ptr;
extern Ring *Rptr;
extern SeaAnimals *Sptr;
		
Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
	scene->getPhysicsWorld()->setGravity( Vect( 0 , 0));

    // 'layer' is an autorelease object
	auto layer = GameScene::create();
	layer->setPhysicsWorld( scene->getPhysicsWorld( ) );
    // add layer as a child to scene
    scene->addChild(layer,0);

	auto Hurldes_layer = Hurdles::create();
	scene->addChild(Hurldes_layer,1);

	auto Water_layer = Water::create();
	scene->addChild( Water_layer , 2);


    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	auto backp = Sprite::create("Background.png");

	backgroundSprite = Sprite::create("sky.png");
	backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y ) );
	this->addChild( backgroundSprite , 1);

		jumpflag = true ;

	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1( GameScene::onContactBegin , this );
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		contactListener ,this);

	

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches( true );
	touchListener->onTouchBegan = CC_CALLBACK_2( GameScene::onTouchBegan , this); 
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority( touchListener , this );

	


	score = 0;

	__String *tempscore = __String::createWithFormat( "%i" , score);

	scoreLabel = Label::createWithTTF( tempscore->getCString() , "fonts/trendex-light-ssi-extra-light.ttf" , visibleSize.height 
		* SCORE_FONT_SIZE );
	scoreLabel->setColor( Color3B::BLACK );
	scoreLabel->setPosition( Point( visibleSize.width / 2 * 0.05 + origin.x , 
		visibleSize.height * 0.95   + origin.y)  );

	this->addChild( scoreLabel , 6 );

    return true;
}


bool GameScene::onContactBegin( cocos2d::PhysicsContact &contact )
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	if( ( DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && UPPER_RING_COLLISION_BITMASK == 
		b->getCollisionBitmask() ) || (DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() && 
		UPPER_RING_COLLISION_BITMASK == a->getCollisionBitmask() )  || 
		( DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && LOWER_RING_COLLISION_BITMASK == 
		b->getCollisionBitmask() ) || (DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() && 
		LOWER_RING_COLLISION_BITMASK == a->getCollisionBitmask() ))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Hit.mp3" );
		

		auto scene = GameOverScene::createScene( score );

		Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , scene ) );

	}
	else if( ( DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && POINT_COLLISION_BITMASK == 
		b->getCollisionBitmask() ) || ( DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() && 
		POINT_COLLISION_BITMASK == a->getCollisionBitmask() ) )
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Point.mp3" );

		score++;

	    __String *tempscore = __String::createWithFormat( "%i" , score);

		scoreLabel->setString( tempscore->getCString() );

	}
	
	else if( (DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && WATER_COLLISION_BITMASK == 
		 b->getCollisionBitmask() ) || ( DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() &&
		 WATER_COLLISION_BITMASK == a->getCollisionBitmask() ) )
	 {

		 jumpflag = true ;

		ripple = Sprite::create("ripple-1.png");
		ripple->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * 1.20);
		ripple->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * 0.70 );
		ripple->setPosition( Point( (visibleSize.width   + origin.x) * 0.30, visibleSize.height / 2 * 0.92 + origin.y ));

		this->addChild( ripple , 5);

		auto animation = Animation::create();
		for( int i=1 ; i < 10 ; i++ )
		{
			char szName[100] = {0};
			sprintf(szName, "ripple/ripple-%00d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		animation->setDelayPerUnit( 2.0f / 9.0f );
		animation->setRestoreOriginalFrame(false);

		auto action = Animate::create(animation);
		auto seq  = Sequence::create( action , nullptr);
		ripple->runAction( seq );
	 }

	else if(( DELETION_COLLISION_BITMASK == a->getCollisionBitmask() && POINT_COLLISION_BITMASK ==
		 b->getCollisionBitmask() ) || ( DELETION_COLLISION_BITMASK == b->getCollisionBitmask() &&
		 POINT_COLLISION_BITMASK ==	 a->getCollisionBitmask() ) )
	{
		//delete Rptr;
		Rptr->topRing->autorelease();
		Rptr->bottomRing->autorelease();
		Rptr->topNode->autorelease();
		Rptr->bottomNode->autorelease();
		Rptr->pointNode->autorelease();

	}

		if( (DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && SNAKE_COLLISION_BITMASK == 
			b->getCollisionBitmask() ) || ( DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() &&
			SNAKE_COLLISION_BITMASK == a->getCollisionBitmask() ) )
		{

			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Hit.mp3" );

			auto scene = GameOverScene::createScene( score );

			Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , scene ) );
		}

		if( a->getNode()->getTag() == SNAKE_TAG || b->getNode()->getTag() == DELETE_TAG )
		{
			a->getNode()->removeFromParentAndCleanup(true);
		}
		else if( b->getNode()->getTag () == SNAKE_TAG  || a->getNode()->getTag() == DELETE_TAG )
		{
			b->getNode()->removeFromParentAndCleanup(true);
		}

	return true;
}





bool GameScene::onTouchBegan( cocos2d::Touch *touch , cocos2d::Event *event)
{


	if( jumpflag == true )
	{
		ptr->Jump();
		jumpflag = false ;
	
	}
	return true; 

}








