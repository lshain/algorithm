
/*
  ID: lshain.1
  PROG: milk3
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

#define     N  21
bool mark[N][N][N];
bool ok[N];
int a, b, c;

void work( int ar, int br, int cr )
{
	mark[ar][br][cr] = true;

	int t = 0;

	if( 0 == ar )
	{
		ok[cr] = true;
	}

	if( ar > 0 )
	{
		if( br < b )
		{
			t = ar < b - br ? ar : b - br;
			if( !mark[ar - t][br + t][cr] )
			{
				work(ar - t, br + t, cr);
			}
		}

		if( cr < c )
		{
			t = ar < c - cr ? ar : c - cr;
			if( !mark[ar - t][br][cr + t] )
			{
				work(ar - t, br, cr + t);
			}
		}
	}

	if( br > 0 )
	{
		if( ar < a )
		{
			t = br < a - ar ? br : a - ar;
			if( !mark[ar + t][br - t][cr] )
			{
				work(ar + t, br - t, cr);
			}
		}

		if( cr < c )
		{
			t = br < c - cr ? br : c - cr;
			if( !mark[ar][br - t][cr + t] )
			{
				work(ar, br - t, cr + t);
			}
		}
	}

	if( cr > 0 )
	{
		if( ar < a )
		{
			t = cr < a - ar ? cr : a - ar;
			if( !mark[ar + t][br][cr - t] )
			{
				work(ar + t, br, cr - t);
			}
		}

		if( br < b )
		{
			t = cr < b - br ? cr : b - br;
			if( !mark[ar][br + t][cr - t] )
			{
				work(ar, br + t, cr - t);
			}
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "milk3.in", "r", stdin );
    freopen( "milk3.out", "w", stdout );

	scanf("%d%d%d", &a, &b, &c);

	for( int i = 0; i < N; i++ )
	{
		ok[i] = false;
		for( int j = 0; j < N; j++ )
		{
			for( int k = 0; k < N; k++ )
			{
				mark[i][j][k] = false;
			}
		}
	}

	work( 0, 0, c );

	bool f = true;
	for( int i = 0; i < N; i++ )
	{
		if( ok[i] )
		{
			if( !f )
			{
				printf(" ");
			}

			if( f )
			{
				f = false;
			}

			printf("%d", i);
		}
	}

	printf("\n");

    return 0;
}
