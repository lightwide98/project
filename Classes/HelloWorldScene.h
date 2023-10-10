#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    void onClickMenuItem(cocos2d::Ref* sender);
    
    void onMouseDown(cocos2d::Event* event);
    void play(Ref* pSender);
    void setting(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
