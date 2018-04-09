//
//  Player.cpp
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Player::Player(City* cp, int r, int c)
: m_city(cp), m_row(r), m_col(c), m_health(INITIAL_PLAYER_HEALTH), m_age(0)
{
    if (cp == nullptr)
    {
        cout << "***** The player must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
        << "," << c << ")!" << endl;
        exit(1);
    }
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

int Player::age() const
{
    return m_age;
}

int Player::health() const
{
    return m_health;
}

bool Player::isPassedOut() const // returns true if health has reached 0
{
    return m_health <= 0;
}

void Player::preach()
{
    m_age++; // counts as a move
    m_city->preachToFlatulansAroundPlayer(); // recall m_city is a pointer to current city, calls function for that city object
}

void Player::move(int dir)
{
    m_age++; // counts as a move
    int r = m_row;
    int c = m_col;
    if (m_city->determineNewPosition(r, c, dir))
    {
        // If there are no Flatulans at the new position
        if (m_city->nFlatulansAt(r, c) == 0)
        {
            m_row = r; // update member variables
            m_col = c;
        }
    }
}

void Player::getGassed()
{
    m_health--;
}
