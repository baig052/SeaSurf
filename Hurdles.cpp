#include "Hurdles.h"
#include "Definitions.h"
#include "GameScene.h"
#include "Dolphin.h"
#include "Ring.h"


USING_NS_CC;

static	Ring *ring;

Ring *Rptr;

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
	
	schedule( schedule_selector( Hurdles::SpawnRing ) , RING_SPAWN_FREQUENCY * VisibleSize.width / 3 );
	//schedule( schedule_selector( Hurdles::SpawnRing_2 ) , RING_SPAWN_FREQUENCY * VisibleSize.width  );
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

void Hurdles::SpawnRing_2(float dt)
{
	ring_2 = new Ring_2();
	ring_2->SpawnRing_2( this );
}
void Hurdles::SpawnAnimals( float dt )
{
	sea_animals = new SeaAnimals();
	sea_animals->SpawnAnimals( this );
}

Hurdles::~Hurdles()
{
	/*delete ring;
	delete ring_2;*/
}






