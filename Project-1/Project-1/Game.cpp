//
//  Game.cpp
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//

#include "Game.h"
#include "globals.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int decodeDirection(char dir); // utility function


Game::Game(int rows, int cols, int nFlatulans)
{
    if (nFlatulans < 0)
    {
        cout << "***** Cannot create Game with negative number of Flatulans!" << endl;
        exit(1);
    }
    if (nFlatulans > MAXFLATULANS)
    {
        cout << "***** Trying to create Game with " << nFlatulans
        << " Flatulans; only " << MAXFLATULANS << " are allowed!" << endl;
        exit(1);
    }
    if (rows == 1  &&  cols == 1  &&  nFlatulans > 0)
    {
        cout << "***** Cannot create Game with nowhere to place the Flatulans!" << endl;
        exit(1);
    }
    
    // Create city
    m_city = new City(rows, cols);
    
    // Add player
    int rPlayer = randInt(1, rows);
    int cPlayer = randInt(1, cols);
    m_city->addPlayer(rPlayer, cPlayer);
    
    // Populate with Flatulans
    while (nFlatulans > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
        // Don't put a Flatulan where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_city->addFlatulan(r, c);
        nFlatulans--;
    }
}

Game::~Game()
{
    delete m_city;
}

void Game::play()
{
    m_city->display();
    Player* p = m_city->player();
    if (p == nullptr)
        return;
    
    while ( ! p->isPassedOut()  &&  m_city->flatulanCount() > 0)
    {
        cout << "Move (u/d/l/r//h/q): ";
        string action;
        getline(cin,action);
        
        if (action[0] == 'h')
        {
            m_city->history().display();  // m_city is a pointer to city
            // history() returns ref to history object
            // call display on history object
            
            cout << "Press enter to continue.";
            getline(cin,action);
            
            ///////////////////////////////////////////////////////////////////////////
            // CLEAR SCREEN HERE???? ask about formatting in reference program
            ///////////////////////////////////////////////////////////////////////////
            
        }
        
        else {
            
            if (action.size() == 0)  // player preaches
                p->preach();
            
            else
            {
                switch (action[0])
                {
                    default:   // if bad move, nobody moves
                        cout << '\a' << endl;  // beep
                        continue;
                    case 'q':
                        return;
                    case 'u':
                    case 'd':
                    case 'l':
                    case 'r':
                        p->move(decodeDirection(action[0]));
                        break;
                }
            }
            m_city->moveFlatulans();
            m_city->display();
            
        }
    }
    if (p->isPassedOut())
        cout << "You lose." << endl;
    else
        cout << "You win." << endl;
}



int decodeDirection(char dir) // utility function
{
    switch (dir)
    {
        case 'u':  return UP;
        case 'd':  return DOWN;
        case 'l':  return LEFT;
        case 'r':  return RIGHT;
    }
    return -1;  // bad argument passed in!
}
