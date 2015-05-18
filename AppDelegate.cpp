#include "AppDelegate.h"
#include "MainMenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}



//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto pDirector = Director::getInstance();
    auto glview = pDirector->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Sea Surf");
        pDirector->setOpenGLView(glview);

		CCSize screenSize = glview->getFrameSize();
		CCSize designSize = CCSizeMake(800, 480);
		glview->setDesignResolutionSize(designSize.width,designSize.height, kResolutionExactFit);


		if(screenSize.height > 480 && screenSize.height < 720 )
		{

			CCSize resourceSize = CCSizeMake(960, 540);
			pDirector->setContentScaleFactor(resourceSize.height/screenSize.height);
		}


		else if (screenSize.height >= 720 && screenSize.height < 800)
		{

			CCSize resourceSize = CCSizeMake(1280, 720);
			pDirector->setContentScaleFactor(resourceSize.height/screenSize.height);

		}

		else if(screenSize.height > 800)
		{
			CCSize resourceSize = CCSizeMake(1920, 1080);
			pDirector->setContentScaleFactor(resourceSize.height/screenSize.height);

		}

		else
		{


		 pDirector->setContentScaleFactor(1);

		}

    }

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = MainMenuScene::createScene();

    // run
    pDirector->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
