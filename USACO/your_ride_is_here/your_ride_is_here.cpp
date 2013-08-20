/*
  ID: lshain.1
  PROG: ride
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

int getNumber( char* p )
{
	int len = strlen( p );
	int i = 0;
	int x = 1;
	for( i = 0; i < len; i++ )
	{
		x *= ( p[i] - 64 );
	}

	return x;
}

bool check( char* p1, char* p2 )
{
	return getNumber( p1 ) % 47 == getNumber( p2 ) % 47;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

	char comet[10];
	char group[10];
	scanf("%s", comet);
	scanf("%s", group);
	printf("%s\n", check(comet, group) ? "GO" : "STAY" );

    return 0;
}
