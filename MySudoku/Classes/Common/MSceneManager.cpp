#include "MSceneManager.h"

#include "StartScene.h"
#include "GameScene.h"


void SceneManager::entrySecne(int sceneid)
{
    CCScene* scene;
    switch (sceneid) {
        case kSceneTagStart:
            scene = StartScene::create();
            break;
        case kSceneTagMainGame:
            scene = GameScene::create();
            break;
        default:
            break;
    }
    SceneManager::go(scene);
}

void SceneManager::go(cocos2d::CCScene* scene)
{
    CCDirector* director = CCDirector::sharedDirector();
    
    if (director->getRunningScene()){
        director->replaceScene(CCTransitionFadeDown::create(0.5, scene));
    }else{
        director->runWithScene(scene);
    }
}

