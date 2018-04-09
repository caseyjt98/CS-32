//
//  City.h
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//


#ifndef City_h
#define City_h

#include <stdio.h>
#include "globals.h"
#include "History.h"
// #include "Flatulan.h"
// #include "Player.h"
// the above is insufficient because it limits what can be done with Player, Flatulan objects within City class

class Player;
class Flatulan; // Needed for City class to access definitions within Player and Flatulan classes


class City
{
public:
    // Constructor/destructor
    City(int nRows, int nCols);
    ~City();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     flatulanCount() const;
    int     nFlatulansAt(int r, int c) const;
    bool    isPlayerAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;
    History& history();
    
    
    // Mutators
    bool  addFlatulan(int r, int c);
    bool  addPlayer(int r, int c);
    void  preachToFlatulansAroundPlayer();
    void  moveFlatulans();
    
private:
    int       m_rows;
    int       m_cols;
    Player*   m_player;
    Flatulan* m_flatulans[MAXFLATULANS];
    int       m_nFlatulans;
    History   m_history;
    
    // Helper functions
    bool isInBounds(int r, int c) const;
};



#endif /* City_h */
