#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"

using namespace cocos2d;

class Hero :public Node
{
public:
	static Hero* createHero();
	virtual bool init();

	Sprite* spriteHero;
	Animation* createAnimation(std::string tenFrame, int soFrame, float delay);

	CREATE_FUNC(Hero);
};

#endif