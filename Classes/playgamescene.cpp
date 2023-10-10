#include "PlayGameScene.h"
#include <HelloWorldScene.h>
#include <Hero.h>

USING_NS_CC;

Scene* PlayGameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PlayGameScene::create();
    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool PlayGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    map = new TMXTiledMap();
    map->initWithTMXFile("tiles/background.tmx");
    //auto layer2 = map->getLayer("Layer2");
    addChild(map);
    map->setScaleX(visibleSize.width / map->getContentSize().width);
    map->setScaleY(visibleSize.height / map->getContentSize().height);

    hero = Hero::create();
    hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 10));
    addChild(hero);

    auto back = MenuItemImage::create("back1.png", "back2.png",
        CC_CALLBACK_1(PlayGameScene::back, this));
    CCASSERT(back != nullptr, "Fail to load BACK images");

    auto menu = Menu::create(back, nullptr);
    this->addChild(menu);
    menu->setPosition(origin);
    back->setPosition(origin + Vec2(back->getContentSize().width / 2,visibleSize.height - back->getContentSize().height / 2));
    
    


    return true;
}
void PlayGameScene::back(Ref * pSender)
{
    auto homeScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.5, homeScene, Color3B(0, 255, 255)));
}
