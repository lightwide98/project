#include "HelloWorldScene.h"
#include "playgamescene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("background.png");
    //background->setPosition(visibleSize / 2);
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(background, -1);
    float rX = visibleSize.width / background->getContentSize().width;
    float rY = visibleSize.height / background->getContentSize().height;
    background->setScaleX(rX);
    background->setScaleY(rY);
    
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //if (label == nullptr)
    //{
    //    problemLoading("'fonts/Marker Felt.ttf'");
    //}
    //else
    //{
    //    // position the label on the center of the screen
    //    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
    //        origin.y + visibleSize.height - label->getContentSize().height));

    //    // add the label as a child to this layer
    //    this->addChild(label, 1);
    //}

    auto play = MenuItemLabel::create(Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf", 40),
        CC_CALLBACK_1(HelloWorld::play, this));
    // Assert that play is not null
    CCASSERT(play != nullptr, "problem loading fonts/Marker Felt.ttf");

    // Position PLAY in the middle of screen
    play->setPosition((Vec2(visibleSize.width / 6, visibleSize.height / 2 + 80)));

    // Add PLAY to menu
    menu->addChild(play);

    auto setting = MenuItemLabel::create(Label::createWithTTF("SETTING", "fonts/Marker Felt.ttf", 40),
        CC_CALLBACK_1(HelloWorld::setting, this));
    //
    //CCASSERT(setting != nullptr, "problem loading fonts/Marker Felt.ttf");
    setting->setPosition((Vec2(visibleSize.width / 6, visibleSize.height / 2 + 30)));
    menu->addChild(setting);
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{

    Director::getInstance()->end();

}

void HelloWorld::onClickMenuItem(cocos2d::Ref* sender)
{
    auto node = dynamic_cast<Node*>(sender);
    CCLOG("%d", node->getTag());
}

void HelloWorld::play(Ref* pSender)
{
    auto playgamescene = PlayGameScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.5, playgamescene, Color3B(0, 255, 255)));
}

void HelloWorld::onMouseDown(cocos2d::Event* event)
{
    
}
void HelloWorld::setting(Ref* pSender)
{

}

