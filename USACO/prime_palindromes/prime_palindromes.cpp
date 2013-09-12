
/*
  ID: lshain.1
  PROG: pprime
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

void print1( int a, int b )
{
	for( int i = 1; i < 10; i++ )
	{
		if( i >= a && i <= b && mark[i] )
		{
			printf("%d\n", i);
		}
	}
}

void print2( int a, int b )
{
	int x = 0;
	for( int i = 1; i < 10; i++ )
	{
		x = i*10 + i;
		if( x >= a && x <= b && mark[x] )
		{
			printf("%d\n", x);
		}
	}
}

void print3( int a, int b )
{
	int x = 0;
	for( int j = 1; j < 10; j += 2 )
	{
		for( int i = 0; i < 10; i++ )
		{
			x = j*100 + i*10 + j;
			if( x >= a && x <= b && mark[x] )
			{
				printf("%d\n", x);
			}
		}
	}
}

void print4( int a, int b )
{
	int x = 0;

	for( int j = 1; j < 10; j += 2 )
	{
		for( int i = 0; i < 10; i++ )
		{
			x = j*1000 + i*100 + i*10 + j;
			if( x >= a && x <= b && isPrim(x) )
			{
				printf("%d\n", x);
			}
		}
	}
}

void print5( int a, int b )
{
	int x = 0;
	for( int k = 1; k < 10; k += 2 )
	{
		for( int j = 0; j < 10; j++ )
		{
			for( int i = 0; i < 10; i++ )
			{
				x = k*10000 + j*1000 + i*100 + j*10 + k;
				if( x >= a && x <= b && isPrim(x) )
				{
					printf("%d\n", x);
				}
			}
		}
	}
}

void print6( int a, int b )
{
	int x = 0;

	for( int k = 1; k < 10; k += 2 )
	{
		for( int j = 0; j < 10; j++ )
		{
			for( int i = 0; i < 10; i++ )
			{
				x = k*100000 + j*10000 + i*1000 + i*100 + j*10 + k;
				if( x >= a && x <= b && isPrim(x) )
				{
					printf("%d\n", x);
				}
			}
		}
	}
}

void print7( int a, int b )
{
	int x = 0;

	for( int l = 1; l < 10; l += 2 )
	{
		for( int k = 0; k < 10; k++ )
		{
			for( int j = 0; j < 10; j++ )
			{
				for( int i = 0; i < 10; i++ )
				{
					x = l*1000000 + k*100000 + j*10000 + i*1000 + j*100 + k*10 + l;
					if( x >= a && x <= b && isPrim(x) )
					{
						printf("%d\n", x);
					}
				}
			}
		}
	}
}

void print8( int a, int b )
{
	int x = 0;

	for( int l = 1; l < 10; l += 2 )
	{
		for( int k = 0; k < 10; k++ )
		{
			for( int j = 0; j < 10; j++ )
			{
				for( int i = 0; i < 10; i++ )
				{
					x = l*10000000 + k*1000000 + j*100000 + i*10000 + i*1000 + j*100 + k*10 + l;
					if( x >= a && x <= b && isPrim(x) )
					{
						printf("%d\n", x);
					}
				}
			}
		}
	}
}

int a, b;

void work( )
{
	initPrim( );
	print1( a, b );
	print2( a, b );
	print3( a, b );
	print4( a, b );
	print5( a, b );
	print6( a, b );
	print7( a, b );
	print8( a, b );
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "pprime.in", "r", stdin );
    freopen( "pprime.out", "w", stdout );

	scanf("%d%d", &a, &b);
	work( );

    return 0;
}
