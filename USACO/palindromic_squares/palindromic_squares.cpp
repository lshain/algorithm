/*
  ID: lshain.1
  PROG: palsquare
  LANG: C++
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int base;

void print( int number )
{
	int dight[32];
	int nd = 0;

	while( number > 0 )
	{
		dight[nd++] = number%base;
		number/=base;
	}

	int i = 0;
	int j = nd - 1;
	int t = 0;
	int d = 0;
	while( i < j )
	{
		t = dight[i];
		dight[i] = dight[j];
		dight[j] = t;

		i++;
		j--;
	}

	for( i = 0; i < nd; i++ )
	{
		if( dight[i] < 10 )
		{
			d = 48;
		}
		else
		{
			d = 55;
		}

		printf("%c", dight[i] + d);
	}

	printf(" ");
}

void check( int number )
{
	int squ = number * number;
	int dight[32];
	int nd = 0;

	while( squ > 0 )
	{
		dight[nd++] = squ%base;
		squ/=base;
	}

	bool ok = true;
	int i = 0;
	int j = nd - 1;
	while( i < j )
	{
		if( dight[i] != dight[j] )
		{
			ok = false;
			break;
		}

		i++;
		j--;
	}

	if( ok )
	{
		int d = 0;

		print( number );

		for( i = 0; i < nd; i++ )
		{
			if( dight[i] < 10 )
			{
				d = 48;
			}
			else
			{
				d = 55;
			}

			printf("%c", dight[i] + d);
		}

		printf("\n");
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	scanf("%d", &base);
	for( int i = 1; i <= 300; i++ )
	{
		check( i );
	}

    return 0;
}
