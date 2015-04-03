#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

unsigned int score;

UserDefault *def = UserDefault::getInstance();

auto highScore = def->getIntegerForKey( "HighScore SeaSurf" ,0 );


Scene* GameOverScene::createScene(unsigned int tempScore )
{
	score = tempScore ; 
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = GameOverScene::create();
		

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Background.png");
	backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y ) );
	this->addChild( backgroundSprite );

	auto titleSprite = Sprite::create( "GameOverTitle.png" );	
	titleSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	titleSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	titleSprite->setPosition( Point( visibleSize.width / 2, visibleSize.height / 2 * 1.70  ) );
	
	this->addChild(titleSprite);

	auto ScoreBoxSprite = Sprite::create( "ScoreBox.png" );	
	ScoreBoxSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	ScoreBoxSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	ScoreBoxSprite->setPosition( Point( visibleSize.width / 2, visibleSize.height / 2 * 1.25  ) );
	
	this->addChild(ScoreBoxSprite);



	auto PlayAgainOption = MenuItemImage::create( "PlayAgain.png" , "PlayAgain.png" , 
		CC_CALLBACK_1( GameOverScene::GoToGameScene , this ) );
	PlayAgainOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	PlayAgainOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	PlayAgainOption->setPosition( Point( visibleSize.width / 2 + origin.x , visibleSize.height / 3 * 1.05 ) );

	auto StatisticsOption = MenuItemImage::create( "home button.png" , "home button.png" , 
		CC_CALLBACK_1( GameOverScene::GoToMainMenuScene , this ) );
	StatisticsOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	StatisticsOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	StatisticsOption->setPosition( Point( visibleSize.width / 2 * 0.65  + origin.x , visibleSize.height / 3 * 0.70  ) );

	auto FacebookOption = MenuItemImage::create( "FaceBookShare.png" , "FaceBookShare.png" , 
		CC_CALLBACK_1( GameOverScene::GoToGameScene , this ) );
	FacebookOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	FacebookOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	FacebookOption->setPosition( Point( visibleSize.width / 2 * 1.35 + origin.x , visibleSize.height / 3 * 0.70  ) );

	auto LeaderBoardOption = MenuItemImage::create( "leaderboardbutton.png" , "leaderboardbutton.png" , 
		CC_CALLBACK_1( GameOverScene::GoToGameScene , this ) );
	LeaderBoardOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	LeaderBoardOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	LeaderBoardOption->setPosition( Point( visibleSize.width / 2 + origin.x , visibleSize.height / 3 * 0.35  ) );

	

	auto menu = Menu::create( PlayAgainOption , StatisticsOption , FacebookOption , LeaderBoardOption , NULL);
	menu->setPosition( Point::ZERO );

	this->addChild( menu );
    

	if( score > highScore )
	{
		highScore = score ;  

		def->setIntegerForKey( "HighScore SeaSurf" , highScore );
	}

	def->flush( );

	auto ScoreSprite = Sprite::create( "ScoreTitle.png" );
	ScoreSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	ScoreSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	ScoreSprite->setPosition( Point( visibleSize.width / 2 * 0.85 + origin.x , visibleSize.height / 2 * 1.45 + origin.y ) );

	this->addChild( ScoreSprite );

	auto RewardSprite = Sprite::create( "RewardTitle.png" );
	RewardSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	RewardSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	RewardSprite->setPosition( Point( visibleSize.width / 2 * 1.15 + origin.x , visibleSize.height / 2 * 1.45 + origin.y ) );

	this->addChild( RewardSprite );

	auto DolphinSprite = Sprite::create( "GameOverDolphin.png" );
	DolphinSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	DolphinSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	DolphinSprite->setPosition( Point( visibleSize.width / 2 * 1.15 + origin.x , visibleSize.height / 2 * 1.15 + origin.y ) );

	this->addChild( DolphinSprite );

	auto BestScoreSprite = Sprite::create( "BestTitle.png" );
	BestScoreSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	BestScoreSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	BestScoreSprite->setPosition( Point( visibleSize.width / 2 * 0.85 + origin.x , visibleSize.height / 2 * 1.20 + origin.y ) );

	this->addChild( BestScoreSprite );

   __String *tempNscore = __String::createWithFormat( "%i" , score);

   auto currentScoreLabel = LabelTTF::create( tempNscore->getCString() , "fonts/trendex-light-ssi-extra-light.ttf" , visibleSize.height 
	   * GAME_OVER_SCORE_FONT_SIZE );
   currentScoreLabel->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
   currentScoreLabel->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
   currentScoreLabel->setColor(Color3B::BLACK);
   currentScoreLabel->setPosition( Point( visibleSize.width / 2 * 0.85 + origin.x , visibleSize.height / 2 * 1.33 + origin.y )  );

   this->addChild( currentScoreLabel );

   __String *tempHighScore = __String::createWithFormat( "%i" , highScore );

    auto BestScoreLabel = LabelTTF::create( tempHighScore->getCString() , "fonts/trendex-light-ssi-extra-light.ttf" , visibleSize.height 
		* GAME_OVER_SCORE_FONT_SIZE ); 
	BestScoreLabel->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * co_ordX);
	BestScoreLabel->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * co_ordY);
	BestScoreLabel->setColor( Color3B::BLACK );
	BestScoreLabel->setPosition( Point( visibleSize.width / 2 * 0.85 + origin.x  , visibleSize.height / 2 * 1.08 + origin.y )  );

	this->addChild( BestScoreLabel );

    return true;
}

void GameOverScene::GoToMainMenuScene( cocos2d::Ref *sender )
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , scene ) );

}

void GameOverScene::GoToGameScene( cocos2d::Ref *sender )
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , scene ) );

}