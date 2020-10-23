//Precomp directs//
#ifndef CELLTABLE_CPP
#define CELLTABLE_CPP

//Header files//
#include "cellTable.h"

cellTable::cellTable()
{
	width = height = 9;

	for( int i = 0; i < width; i++ )
	{
		for( int j = 0; j < height; j++ )
		{
			contents[ i ][ j ].user = false;
			if( i == 0 or i < 3 )
			{
				if( j == 0 or j < 3 )
				{
					contents[ i ][ j ].block = 'A';
				}
			
				else if( j == 3 or j < 6 )
				{
					contents[ i ][ j ].block = 'B';
				}

				else if( j == 6 or j < 9 )
				{
					contents[ i ][ j ].block = 'C';
				}
			}
			
			else if( i == 3 or i < 6 )
			{
				if( j == 0 or j < 3 )
				{
					contents[ i ][ j ].block = 'D';
				}
			
				else if( j == 3 or j < 6 )
				{
					contents[ i ][ j ].block = 'E';
				}

				else if( j == 6 or j < 9 )
				{
					contents[ i ][ j ].block = 'F';
				}
			}

			else if( i == 6 or i < 9 )
			{
				if( j == 0 or j < 3 )
				{
					contents[ i ][ j ].block = 'G';
				}
			
				else if( j == 3 or j < 6 )
				{
					contents[ i ][ j ].block = 'H';
				}

				else if( j == 6 or j < 9 )
				{
					contents[ i ][ j ].block = 'I';
				}
			}
		} 
	}
}

bool cellTable::checkRow( int y , int attempt )
{
	for( int i = 0; i < 9; i++ )
	{
		if( contents[ y ][ i ].val == attempt )
			{
				return false;
			}
	}
	return true;
}

bool cellTable::checkCol( int x , int attempt )
{
	for( int i = 0; i < 9; i++ )
	{
		if( contents[ i ][ x ].val == attempt )
			{
				return false;
			}
	}
	return true;
}

bool cellTable::checkBlock( int x , int y , int attempt )
{
	char blockSpot = contents[ x ][ y ].block;

	for( int i = 0; i < 9; i++ )
	{
		for( int j = 0; j < 9; j++ )
		{
			if( contents[ i ][ j ].block == blockSpot and attempt == contents[ i ][ j ].val )
			{
				return false;
			}
		}
	}
	return true;
}

bool cellTable::isFull()
{
	for( int i = 0; i < width; i++ )
	{
		for( int j = 0; j < height; j++ )
		{
			if( contents[ i ][ j ].val == 0 )
				{
					return false;
				}
		}
	}
	return true;
}

void cellTable::showTable()
{
	for( int i = 0; i < width; i++ )
	{
		if( i == 3 or i == 6 )
		{
			for( int bar = 0; bar < width + 2; bar++ )
			{
				cout << "--";
			}

			cout << endl;
		}

		for( int j = 0; j < height; j++ )
		{
			cout << contents[ i ][ j ].val << ' ';

			if( j == 2 or j == 5 )
				{
					cout << "| ";
				}
		}

		cout << endl;
	}			
}

void cellTable::inputVal()
{
	int input, inputCount, input_x, input_y;
	cout << "How many values?\n";
	cin >> inputCount;
	for( int i = 0; i < inputCount; i++ )
		{
			cout << "Give x and y coordinate\n";
			cout << "For value " << i + 1 << endl;
			cout << "X: ";
			cin >> input_x;
			cout << "Y: ";
			cin >> input_y;
			cout << "Now the value\n";
			cin >> input;
			contents[ input_x ][ input_y ].val = input;
			contents[ input_x ][ input_y ].user = true;
		}

	cout << "Done." << endl;
	showTable();
	cout << endl;
}

bool cellTable::fileRead( char * fileName )
{
	char * buffer;
	int x, y;

	x = 0;
	buffer = new char[ 11 ];

	ifstream read;
	read.open( fileName );

	for( int i = 0; i < 11; i++ )
	{
		read >> buffer;
		y = 0;
		for( int j = 0; j < 11; j++ )
		{
			if( buffer[ j ] != '|' and buffer[ j ] != '-' )
			{
				contents[ x ][ y ].val = ( buffer[ j ] - 48 );
				if( buffer[ j ] > 48 )
				{
					contents[ x ][ y ].user = true;
				}
				y++;
			}
		}

		if( buffer[ 0 ] != '-' )
		{
			x++;
		}
	}
	read.close();
	return true;
}

#endif
