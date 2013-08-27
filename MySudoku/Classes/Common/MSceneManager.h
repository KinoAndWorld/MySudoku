#ifndef __ShakeForFood2__MSceneManager__
#define __ShakeForFood2__MSceneManager__

#include "cocos2d.h"

using namespace cocos2d;

enum sceneTag
{
    kSceneTagStart = 0,
    //kSceneTagPlayerSelect,
    kSceneTagMainGame,
    //kSceneTagCoinGame,
    kSceneTagGameover
};

class SceneManager
{
public:
    static void entrySecne(int sceneid = kSceneTagStart);
private:
    static void go(cocos2d::CCScene* layer);
    //static CCScene* wrap(CCLayer* layer);
};

#endif
