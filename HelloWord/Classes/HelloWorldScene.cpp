/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
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
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

   

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("background.png");
    if (sprite == nullptr)
    {
        problemLoading("'background.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    //add sprite
    auto character = Sprite::create("character/character_01.png");
    character->setPosition({ 250.0f,400.f });
    this->addChild(character);

    //add animation 
    auto characterAnimation = Animation::create();

    characterAnimation->setDelayPerUnit(0.15f);

    characterAnimation->setLoops(-1);

    characterAnimation->addSpriteFrame(Sprite::create("character/character_01.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_02.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_03.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_04.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_05.png")->getSpriteFrame());
    characterAnimation->addSpriteFrame(Sprite::create("character/character_06.png")->getSpriteFrame());

    Animate* animate = Animate::create(characterAnimation);

    character->runAction(animate);


    auto shadow = Sprite::create("character/shadow.png");

    shadow->setPosition(Vec2(character->getContentSize().width / 2, 10.5f));

    character->addChild(shadow, -1);

    //create animation cache
    auto skillAnimation = Animation::create();
    skillAnimation->setDelayPerUnit(0.15f);
    skillAnimation->setLoops(1);

    skillAnimation->addSpriteFrame(Sprite::create("skill/attack1.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack2.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack3.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack4.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack5.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack6.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack7.png")->getSpriteFrame());
    skillAnimation->addSpriteFrame(Sprite::create("skill/attack8.png")->getSpriteFrame());

    const std::string k_skillAnimationName = "skillAnimation";

    AnimationCache::getInstance()->addAnimation(skillAnimation, k_skillAnimationName);

    //skillAnimation 2
    auto skillAnimation2 = Animation::create();
    skillAnimation2->setDelayPerUnit(0.15f);
    skillAnimation2->setLoops(1);

    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_0.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_1.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_2.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_3.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_4.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_5.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_6.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_7.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_8.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_8.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_10.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_11.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_12.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_13.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_14.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_15.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_16.png")->getSpriteFrame());
    skillAnimation2->addSpriteFrame(Sprite::create("skill_02/skill_02_17.png")->getSpriteFrame());
 
    const std::string k_skillAnimationName2 = "skillAnimation2";

    AnimationCache::getInstance()->addAnimation(skillAnimation2, k_skillAnimationName2);
    //onpress clipkeyboard
    auto keyboardListener = EventListenerKeyboard::create();

    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event) {
        switch (keycode)
        {
        case (EventKeyboard::KeyCode::KEY_A):
        {
            auto skill = Sprite::create("skill_02/skill_02_0.png");
            skill->setPosition(character->getPosition() + Vec2(+100, 0));
           

            auto skill1 = Sprite::create("skill_02/skill_02_0.png");
            skill1->setPosition(character->getPosition() + Vec2(+100, +300));
           

            auto skill2 = Sprite::create("skill_02/skill_02_0.png");
            skill2->setPosition(character->getPosition() + Vec2(+200, +100));

            this->addChild(skill);
            this->addChild(skill1);
            this->addChild(skill2);

            Animate* animate = Animate::create(AnimationCache::getInstance()->getAnimation("skillAnimation2"));
            Animate* animate2 = Animate::create(AnimationCache::getInstance()->getAnimation("skillAnimation2"));
            Animate* animate3 = Animate::create(AnimationCache::getInstance()->getAnimation("skillAnimation2"));

            skill->runAction(Sequence::createWithTwoActions(animate, RemoveSelf::create()));
            skill1->runAction(Sequence::createWithTwoActions(animate2, RemoveSelf::create()));
            skill2->runAction(Sequence::createWithTwoActions(animate3, RemoveSelf::create()));
            break;
        }
        // Jump
        case (EventKeyboard::KeyCode::KEY_0): {
            character->runAction(JumpBy::create(1.0f, Point(+50.0f,0),50.f,1));
            break;
        }
        // move character by pisition(200.0f, 0) in 2 second
        case (EventKeyboard::KeyCode::KEY_1): {
            character->runAction(MoveBy::create(2.0f, Point(-200.0f, 0)));
            break;
        } case
        (EventKeyboard::KeyCode::KEY_2): {
            character->runAction(RotateBy::create(2.0f, 0, 180.0f));
            break;
        }
        case (EventKeyboard::KeyCode::KEY_3): {
            character->runAction(MoveBy::create(2.0f, Point(200.0f, 0)));
            break;
        }
        case (EventKeyboard::KeyCode::KEY_4): {
            character->runAction(SkewBy::create(2.0f, 90.f,90.0f));
            break;
        }
        case (EventKeyboard::KeyCode::KEY_5): {
            character->runAction(RotateBy::create(2.0f, 0, -180.0f));
            break;
        }
                                            //face to 
        case (EventKeyboard::KeyCode::KEY_6): {
            character->runAction(FadeTo::create(2.0f,80));
            break;
        }
                                            //face in
        case (EventKeyboard::KeyCode::KEY_7): {
            character->runAction(FadeIn::create(0));
            break;
        } //face out
        case (EventKeyboard::KeyCode::KEY_8): {
            character->runAction(FadeOut::create(0));
            break;
        }
                                            //BezierTo
        case (EventKeyboard::KeyCode::KEY_9): {
            ccBezierConfig bezier;
            bezier.controlPoint_1 = Point(0, visibleSize.height / 2);
            bezier.controlPoint_1 = Point(300, -visibleSize.height / 2);
            bezier.endPosition = Point(200, 100);

            character->runAction(BezierTo::create(3, bezier));
            break;  
        }
                                            //TinyBy
        case (EventKeyboard::KeyCode::KEY_KP_PLUS): {
            character->runAction(TintBy::create(2.0f,255,0,255));
            break;
        }  
                                                  //Tinito
        case (EventKeyboard::KeyCode::KEY_KP_MINUS): {
            character->runAction(TintTo::create(2.0f, 0, 0, 255));
          
            break;
        }
        //bezierBy
        case (EventKeyboard::KeyCode::KEY_KP_MULTIPLY): {
            ccBezierConfig bezier;
            bezier.controlPoint_1 = Point(0, visibleSize.height / 2);
            bezier.controlPoint_1 = Point(300, -visibleSize.height / 2);
            bezier.endPosition = Point(200, 100);

            character->runAction(BezierBy::create(3,bezier));
        }
        case (EventKeyboard::KeyCode::KEY_M): {
            character->runAction(Place::create(Point(98.f,280.f)));
           
        }
                                            //Repeat
        case (EventKeyboard::KeyCode::KEY_N): {
            character->runAction(RepeatForever::create(RotateBy::create(2.f,45)));

        }
        case (EventKeyboard::KeyCode::KEY_B): {
            character->runAction(Sequence::create(RotateBy::create(2.f, 45), MoveBy::create(2.0f, Point(-200.0f, 0)),NULL));

        }

                                    //EX1:
        case (EventKeyboard::KeyCode::KEY_P): {
            auto movoToCenter = MoveTo::create(2.0f, Point(visibleSize.width/2, visibleSize.height/  2));
           //CallFunc::create(CC_CALLBACK_0(HelloWorld::endMove, this));
            auto printf = CallFunc::create(CC_CALLBACK_0(HelloWorld::printIntoScreen,this));
            
            auto jump = JumpTo::create(1.0f, Point(visibleSize.width, character->getPosition().y), 50, 1);

            auto back = CallFunc::create([=] {
                backToTheBeginPosition(character);
                });
            auto delay = DelayTime::create(5);

          //  void HelloWorld::backToTheBeginPosition(cocos2d::Sprite* a) {
            character->runAction(Sequence::create(movoToCenter, printf, jump,delay,back , NULL));
            break;
        }
        case (EventKeyboard::KeyCode::KEY_O): {
            auto movoToCenter = MoveTo::create(2.0f, Point(visibleSize.width / 2, visibleSize.height / 2));
            auto scaleCharacter = ScaleTo::create(1.f, 2);
            auto callbackJump = CallFunc::create([]() {
                log("Jumped!");
                });
            //auto mySpawn = Spawn::create(movoToCenter, scaleCharacter,callbackJump,NULL);
            character->runAction(Spawn::create(movoToCenter, scaleCharacter, callbackJump, NULL));

        }
        default:
            break;
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    
    //onclick
    auto touchListenner = EventListenerTouchOneByOne::create();

    touchListenner->onTouchBegan = [](Touch* touch, Event* event) {
        return true;
    };
    touchListenner->onTouchMoved = [](Touch* touch, Event* event) {

    };

    touchListenner->onTouchEnded = [=](Touch* touch, Event* event) {
        auto skill = Sprite::create("skill/attack1.png");
        skill->setPosition(touch->getLocation());
        this->addChild(skill);

        Animate* animate = Animate::create(AnimationCache::getInstance()->getAnimation("skillAnimation"));

        skill->runAction(Sequence::createWithTwoActions(animate, RemoveSelf::create()));

    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListenner, this);

  


    return true;
}
void HelloWorld::printIntoScreen() {
    std::string s="Quyen Cong Hello moi nguoi";

    auto label = Label::createWithTTF(s, "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
    // position the label on the center of the screen
        label->setPosition(Vec2(1024 /2, 768/2));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
}
void HelloWorld::backToTheBeginPosition(cocos2d::Sprite* a) {
    a->setPosition({ 250.0f,400.f });
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
