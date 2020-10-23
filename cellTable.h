//Precompiler Directives//

#ifndef CELLTABLE_H
#define CELLTABLE_H

//Header Files//
#include <ostream>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include "cellType.h"
#include <fstream>
#include <cstdlib>

using namespace std;

struct cellTable{
	int width;
	int height;
	cellType contents[9][9];
	
	cellTable();

	bool checkRow( int y , int attempt );
	bool checkCol( int x , int attempt );
	bool checkBlock( int x , int y , int attempt );
	bool isFull();
	void showTable();
	void inputVal();
	bool fileRead( char * fileName );

	};

//Terminating precomp directs//
#endif
