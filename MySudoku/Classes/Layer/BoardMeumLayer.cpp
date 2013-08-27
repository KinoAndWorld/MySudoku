//
//  BoardMeumLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "BoardMeumLayer.h"
#include "MSceneManager.h"

bool BoardMeumLayer::init(){
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    int fontSize = 60;
    CCString* fontName = CCString::create("Thonburi");
    CCLabelTTF *label1 = CCLabelTTF::create("返回菜单", fontName->getCString(), fontSize);
    label1->setColor(ccc3(20, 20, 85));
    
    CCLabelTTF *label2 = CCLabelTTF::create("重置游戏", fontName->getCString(), fontSize);
    label2->setColor(ccc3(200, 10, 10));
    
    CCLabelTTF *label3 = CCLabelTTF::create("关于", fontName->getCString(), fontSize);
    label3->setColor(ccc3(20, 100, 10));
    
    CCMenuItemLabel* backMenu = CCMenuItemLabel::create(label1, this, menu_selector(BoardMeumLayer::BackGame));
    CCMenuItemLabel* reSetMenu = CCMenuItemLabel::create(label2, this, menu_selector(BoardMeumLayer::ResetGame));
    //CCMenuItemLabel* aboutMenu = CCMenuItemLabel::create(label3, this, menu_selector(BoardMeumLayer::settingGame));
    
    _menu = CCMenu::create( backMenu, reSetMenu, NULL);
    _menu->alignItemsHorizontallyWithPadding(50);
    _menu->setPosition(ccp(winSize.width * 0.45, winSize.height * 0.9));
    this->addChild(_menu);
    
    return true;
}

void BoardMeumLayer::BackGame(){
    SceneManager::entrySecne(kSceneTagStart);
}

void BoardMeumLayer::ResetGame(){
    
}