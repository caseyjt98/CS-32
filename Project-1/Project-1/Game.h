//
//  Game.h
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//


#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "City.h"


class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();
    
    // Mutators
    void play();
    
private:
    City* m_city;
};



#endif /* Game_h */
