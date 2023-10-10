#include "Hero.h"


USING_NS_CC;

Hero* Hero::createHero()
{
	return Hero::create();
}

bool Hero::init()
{
	if (!Node::init())
	{
		return false;
	}

	SpriteBatchNode* spritenode = SpriteBatchNode::create("animation/idle.png");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("animation/idle.plist", "animation/idle.png");
	spriteHero = Sprite::createWithSpriteFrameName("Idle__001.png");
	this->addChild(spriteHero);

	Animate* animatehero = Animate::create(Hero::createAnimation("Idle__000.png", 10, 0.08f));
	spriteHero->runAction(RepeatForever::create(animatehero));

	return true;

}
Animation* Hero::createAnimation(std::string tenFrame, int soFrame, float delay)
{
	Vector<SpriteFrame*> frameAni;
	for (int i = 1; i < soFrame; i++)
	{
		char buffer[20] = { 0 };
		sprintf(buffer, "%d.png", i);
		std::string str = tenFrame + buffer;
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		frameAni.pushBack(frame);

	}

	Animation* animation = Animation::createWithSpriteFrames(frameAni, delay);
	return animation;

}
