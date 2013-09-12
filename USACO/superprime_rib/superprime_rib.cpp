
/*
  ID: lshain.1
  PROG: sprime
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

#define N 10001
bool mark[N];
int prim[N];
int np;

int initPrim( )
{
	int i = 0;
	int j = 0;

	for( i = 0; i < N; i++ )
	{
		mark[i] = true;
	}

	for( i = 0; i < N; i+= 2 )
	{
		mark[i] = false;
	}

	mark[2] = true;
	for( i = 3; i < N; i++ )
	{
		j = i;
		while( i + j < N )
		{
			mark[i + j] = false;
			j += i;
		}
	}

	np = 0;
	prim[np++] = 2;
	for( i = 3; i < N; i += 2 )
	{
		if( mark[i] )
		{
			prim[np++] = i;
		}
	}
}

bool isPrim( int x )
{
	if( x < N )
	{
		return mark[x];
	}

	for( int i = 0; i < np; i++ )
	{
		if( 0 == x%prim[i] )
		{
			return false;
		}
	}

	return true;
}

int n;
void dfs( int num, int t )
{
	if( t == n )
	{
		if( isPrim(num) )
		{
			printf( "%d\n", num );
		}
	}
	else
	{
		if( isPrim(num) )
		{
			for( int i = 1; i < 10; i += 2 )
			{
				dfs( num*10 + i, t + 1 );
			}
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "sprime.in", "r", stdin );
    freopen( "sprime.out", "w", stdout );

	scanf("%d", &n);
	initPrim( );

	for( int i = 2; i < 10; i++ )
	{
		dfs( i, 1 );
	}

    return 0;
}
