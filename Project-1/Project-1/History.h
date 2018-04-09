//
//  History.h
//  Project-1
//
//  Created by Casey Taylor on 4/8/18.
//  Copyright © 2018 Casey Taylor. All rights reserved.
//

#ifndef History_h
#define History_h

#include <stdio.h>
#include "globals.h"

class History
{
    
public:
    History(int nRows, int nCols); // assume valid rol, col inputs
    bool record(int r, int c);
    void display() const;
private:
    int m_rows;
    int m_cols;
    int m_arr[MAXROWS][MAXCOLS];
};





#endif /* History_h */
