//
//  BackGroundLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__BackGroundLayer__
#define __MySudoku__BackGroundLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BackGroundLayer : public CCLayer {
public:
    CREATE_FUNC(BackGroundLayer);
    bool init();
};

#endif /* defined(__MySudoku__BackGroundLayer__) */
