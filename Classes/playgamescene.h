#ifndef __PLAYGAME_SCENE_H__
#define __PLAYGAME_SCENE_H__

#include "cocos2d.h"

class PlayGameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    cocos2d::Vec2 bgDirection;
    Hero* hero;

    void onMouseDown(cocos2d::Event* event);

    void back(Ref* pSender);
    cocos2d::TMXTiledMap* map;
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayGameScene);
};

#endif // __HELLOWORLD_SCENE_H__
