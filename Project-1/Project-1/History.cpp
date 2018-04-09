//
//  History.cpp
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//

#include "History.h"
#include <cstdlib>
#include <iostream>

using namespace std;

History::History(int nRows, int nCols)
: m_rows(nRows), m_cols(nCols)
{
    // assume valid nRows, nCols arguments
    
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            m_arr[r][c] = 0; // initialize number of converted Flatulans to zero for each grid space
        }
    }
    
    
}

void History:: display() const
{
    // clears the screen and displays history grid
    // clear screen (clearScreen()), display grid, write empty line after grid
    // does NOT print "Press Enter to continue"
    
    clearScreen();
    
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            
            // special case if it's zero
            
            if (m_arr[r][c] == 0)
            {
                cout << ".";
            }
            
            else if (m_arr[r][c] >= 26)
            {
                cout << "Z";
            }
            
            else
            {
                
                // 'A' has ascii value of 65
                int ascii_val= m_arr[r][c] + 64;
                // get letter associated with ascii vals
                cout << (char)ascii_val;
            }
        }
        
        cout << endl; // new line before next row
    }
    
    cout << endl;
    
}




bool History::record(int r, int c)
{
    // notify History object that a Flatulan at indicated location was converted
    // params expressed in same coord system as City
    
    if (r < 0  ||  r > m_rows  ||  c < 0  ||  c > m_cols)
    {
        return false;
    }
    
    else
    {
        // record and return true
        
        m_arr[r][c] += 1; // increment count
        return true;
    }
    
}
