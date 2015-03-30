#include "Hurdles.h"
#include "Definitions.h"
#include "GameScene.h"
#include "Dolphin.h"


USING_NS_CC;

static Dolphin *dol;

Dolphin *ptr;
 
bool Hurdles::init()
{

	if(!Layer::init())
	{
		return false;
	}

	VisibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	
	schedule( schedule_selector( Hurdles::SpawnRing ) , RING_SPAWN_FREQUENCY * VisibleSize.width );
	schedule( schedule_selector( Hurdles::SpawnAnimals) , ANIMALS_SPAWN_FREQUENCY * VisibleSize.width /2 );
		
	dol = new Dolphin(this);
	ptr = dol;

	return true;
}




void Hurdles::SpawnRing( float dt )
{
	ring = new Ring () ; 
	ring->SpawnRing( this );
}

void Hurdles::SpawnAnimals( float dt )
{
	sea_animals = new SeaAnimals();
	sea_animals->SpawnAnimals( this );
}






