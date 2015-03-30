#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
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

	auto titleSprite = Sprite::create( "titlenew.png" );	
	titleSprite->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	titleSprite->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * 1.50);
	titleSprite->setPosition( Point( visibleSize.width / 2, visibleSize.height / 2 * 1.40  ) );
	
	this->addChild(titleSprite);

	auto PlayOption = MenuItemImage::create( "full button.png" , "full button.png" , 
		CC_CALLBACK_1( MainMenuScene::GoToGameScene , this ) );
	PlayOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	PlayOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * 1.50);
	PlayOption->setPosition( Point( visibleSize.width / 2 + origin.x , visibleSize.height / 3  ) );

	auto StatisticsOption = MenuItemImage::create( "home button.png" , "home button.png" , 
		CC_CALLBACK_1( MainMenuScene::GoToGameScene , this ) );
	StatisticsOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	StatisticsOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * 1.50);
	StatisticsOption->setPosition( Point( visibleSize.width / 2 * 0.70  + origin.x , visibleSize.height / 3 * 0.40  ) );


	auto LeaderBoardOption = MenuItemImage::create( "leaderboardbutton.png" , "leaderboardbutton.png" , 
		CC_CALLBACK_1( MainMenuScene::GoToGameScene , this ) );
	LeaderBoardOption->setScaleX(visibleSize.width/backgroundSprite->getContentSize().width * 0.55);
	LeaderBoardOption->setScaleY(visibleSize.height/backgroundSprite->getContentSize().height * 1.50);
	LeaderBoardOption->setPosition( Point( visibleSize.width / 2 * 1.30  + origin.x , visibleSize.height / 3 * 0.40  ) );
	

	auto menu = Menu::create( PlayOption , StatisticsOption , LeaderBoardOption  , NULL);
	menu->setPosition( Point::ZERO );

	this->addChild( menu );
    
    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
{
	auto Scene = GameScene::createScene();
	Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME , Scene ));

}

void MainMenuScene::GoToInAppPurchases(cocos2d::Ref *sender)
{
}

void MainMenuScene::GoToLeaderBoard(cocos2d::Ref *sender)
{
}
