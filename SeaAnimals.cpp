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

	auto backgroundSprite = Sprite::create("Background.png");
	
	auto blue_fish = Sprite::create("blue_fish.png");
	blue_fish->setScaleX(VisibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	blue_fish->setScaleY(VisibleSize.height/backgroundSprite->getContentSize().height * 1.50);

	blue_fish->setPosition(	Point(	(VisibleSize.width + origin.x) * 1.2 ,	VisibleSize.height / 2	* 0.65 + origin.y	)	);

	auto blue_fish_Action = MoveBy::create( (FISH_MOVEMENT_SPEED *  VisibleSize.width) , Point( -VisibleSize.width * 1.2 , 0 ));

	blue_fish->runAction(blue_fish_Action);
	
	layer->addChild( blue_fish ,2 );

	
	


}