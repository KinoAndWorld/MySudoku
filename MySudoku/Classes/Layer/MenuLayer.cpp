//
//  MenuLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "MenuLayer.h"
#include "StartScene.h"
#include "StaticData.h"

bool MenuLayer::init(){
    if (CCLayer::init()) {
        this->createMenu();
        this->createBackground();
        return true;
    }
    return false;
}

//调用场景的相关方法
void MenuLayer::startGame(){
    StartScene* gameScene = (StartScene*)this->getParent();
    gameScene->startGame();
}
void MenuLayer::settingGame(){
    StartScene* gameScene = (StartScene*)this->getParent();
    gameScene->settingGame();
}
void MenuLayer::aboutGame(){
    StartScene* gameScene = (StartScene*)this->getParent();
    gameScene->aboutGame();
}


void MenuLayer::createMenu(){
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite *sprBg = CCSprite::create(S_MainMenu);
    sprBg->setPosition(ccp(winSize.width*0.5, winSize.height*0.5));
    this->addChild(sprBg);
    
    //CCLayerColor *bgLayer = CCLayerColor::create(ccc4(60, 20, 75, 255));
    //this->addChild(bgLayer);
    
    int fontSize = 80;
    CCString* fontName = CCString::create("Thonburi");
    
    CCLabelTTF *label1 = CCLabelTTF::create("Start Game", fontName->getCString(), fontSize);
    label1->setColor(ccc3(20, 20, 85));
    
    CCLabelTTF *label2 = CCLabelTTF::create("设置", fontName->getCString(), fontSize);
    label2->setColor(ccc3(200, 10, 10));
    
    CCLabelTTF *label3 = CCLabelTTF::create("关于", fontName->getCString(), fontSize);
    label3->setColor(ccc3(20, 100, 10));
    
    CCMenuItemLabel* startMenu = CCMenuItemLabel::create(label1, this, menu_selector(MenuLayer::startGame));
    CCMenuItemLabel* setMenu = CCMenuItemLabel::create(label2, this, menu_selector(MenuLayer::settingGame));
    CCMenuItemLabel* aboutMenu = CCMenuItemLabel::create(label3, this, menu_selector(MenuLayer::settingGame));
    
    CCMenu* menu = CCMenu::create( startMenu, setMenu, aboutMenu, NULL);
    menu->alignItemsVerticallyWithPadding(110);
    this->addChild(menu);
}

void MenuLayer::createBackground(){
    //CCLayerColor* colorBackground = CCLayerColor::create(ccc4(0, 0, 0, 128));
    //this->addChild(colorBackground);
}