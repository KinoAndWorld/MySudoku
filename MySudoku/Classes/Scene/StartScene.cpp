//
//  StartScene.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "StartScene.h"
#include "MSceneManager.h"
#include "SimpleAudioEngine.h"
#include "StaticData.h"

bool StartScene::init(){
    if (CCScene::init()) {
        _menuLayer = MenuLayer::create();
        this->addChild(_menuLayer);
        this->schedule(schedule_selector(StartScene::playBackgroundMusic), 2.0);
        return true;
    }
    return false;
}

void StartScene::playBackgroundMusic(){
    if (!CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(M_START);
    }
}

StartScene::~StartScene(){
    
}

void StartScene::startGame(){
    SceneManager::entrySecne(kSceneTagMainGame);
}

void StartScene::settingGame(){
    
}
void StartScene::aboutGame(){
    
}