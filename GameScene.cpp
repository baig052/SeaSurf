#include "GameScene.h"
#include "cocos2d.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "Dolphin.h"
#include "Hurdles.h"
#include "Ring.h"

USING_NS_CC;

extern Dolphin *ptr;
extern Ring *Rptr;
		
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	auto backgroundSprite = Sprite::create("sky.png");
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
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Hit.mp3" );

		auto scene = GameOverScene::createScene( score );

		Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , scene ) );

	}
	 if( ( DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && POINT_COLLISION_BITMASK == 
		b->getCollisionBitmask() ) || ( DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() && 
		POINT_COLLISION_BITMASK == a->getCollisionBitmask() ) )
	{
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "Sounds/Point.mp3" );

		score++;

	    __String *tempscore = __String::createWithFormat( "%i" , score);

		scoreLabel->setString( tempscore->getCString() );

	}
	
	 if( (DOLPHIN_COLLISION_BITMASK == a->getCollisionBitmask() && WATER_COLLISION_BITMASK == 
		 b->getCollisionBitmask() ) || ( DOLPHIN_COLLISION_BITMASK == b->getCollisionBitmask() &&
		 WATER_COLLISION_BITMASK == a->getCollisionBitmask() ) )
	 {
		 jumpflag = true ;
		
	 }
	 if(( DELETION_COLLISION_BITMASK == a->getCollisionBitmask() && POINT_COLLISION_BITMASK ==
		 b->getCollisionBitmask() ) || ( DELETION_COLLISION_BITMASK == b->getCollisionBitmask() &&
		 POINT_COLLISION_BITMASK ==	 a->getCollisionBitmask() ) )
	{

		Rptr->DeleteRing( this );
		

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






