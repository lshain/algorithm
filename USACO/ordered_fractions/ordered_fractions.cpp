/*
  ID: lshain.1
  PROG: frac1
  LANG: C++
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n;

void make_farey( int x1, int y1, int x2, int y2 )
{
	if( x1 + x2 > n || y1 + y2 > n )
	{
		return;
	}

	make_farey( x1, y1, x1 + x2, y1 + y2 );
	printf("%d/%d\n", x1+x2, y1+y2);
	make_farey( x1 + x2, y1 + y2, x2, y2 );
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "frac1.in", "r", stdin );
    freopen( "frac1.out", "w", stdout );

	scanf("%d",&n);
	printf("0/1\n");
	if( n > 1 )
	{
		make_farey( 0, 1 ,1, 1 );
	}

	printf("1/1\n");
    return 0;
}
