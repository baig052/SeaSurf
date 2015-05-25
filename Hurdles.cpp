#include "Hurdles.h"
#include "Definitions.h"
#include "GameScene.h"
#include "Dolphin.h"
#include "Ring.h"
#include "SeaAnimals.h"


USING_NS_CC;

static	Ring *ring;

Ring *Rptr;

static Dolphin *dol;

Dolphin *ptr;
static SeaAnimals *sea_animals;

SeaAnimals *Sptr;
 
bool Hurdles::init()
{

	if(!Layer::init())
	{
		return false;
	}

	VisibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	
	schedule( schedule_selector( Hurdles::SpawnRing ) , RING_SPAWN_FREQUENCY * VisibleSize.width / 3 );
	schedule( schedule_selector( Hurdles::SpawnAnimals) , ANIMALS_SPAWN_FREQUENCY * VisibleSize.width /2 );
		

	dol = new Dolphin(this);
	ptr = dol;

	return true;
}




void Hurdles::SpawnRing( float dt )
{
	ring = new Ring () ; 
	ring->SpawnRing( this );
	Rptr = ring;
	
}


void Hurdles::SpawnAnimals( float dt )
{
	sea_animals = new SeaAnimals();
	sea_animals->SpawnAnimals( this );
	Sptr = sea_animals;
}

Hurdles::~Hurdles()
{
	
}






