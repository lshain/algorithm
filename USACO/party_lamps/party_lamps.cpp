/*
  ID: lshain.1
  PROG: lamps
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
int c;
int on[101];
int nn;
int off[101];
int no;
#define SIZE  64
int A[SIZE];
int B[SIZE];
int mark[7] =
{
	0x00,
	0x20,
	0x10,
	0x08,
	0x04,
	0x02,
	0x01
};

int main( int argc, char* argv[], char* env[] )
{
    freopen( "lamps.in", "r", stdin );
    freopen( "lamps.out", "w", stdout );

	scanf("%d%d",&n,&c);
	int t = -1;
	nn = 0;
	while( scanf("%d",&t) && t != -1 )
	{
		on[nn++] = t;
	}

	no = 0;
	while( scanf("%d",&t) && t != -1 )
	{
		off[no++] = t;
	}

	int i = 0;
	int j = 0;
	for( i = 0; i < SIZE; i++ )
	{
		B[i] = 0;
	}

	B[0x3f] = 1;
	while( c-- > 0 )
	{
		for( i = 0; i < SIZE; i++ )
		{
			A[i] = B[i];
			B[i] = 0;
		}

		for( i = 0; i < SIZE; i++ )
		{
			if( A[i] )
			{
				B[(~i) & 0x3f] = 1;
				B[( (i & 0x2a) | ( ( ~(i & 0x15) ) & 0x15 ) ) & 0x3f] = 1;
				B[( (i & 0x15) | ( ( ~(i & 0x2a) ) & 0x2a ) ) & 0x3f] = 1;
				B[( (i & 0x1b) | ( ( ~(i & 0x24) ) & 0x24 ) ) & 0x3f] = 1;
			}
		}
	}

	int ok = 0;
	int f = 0;
	for( i = 0; i < SIZE; i++ )
	{
		if( B[i] )
		{
			f = 1;
			for( j = 0; j < nn; j++ )
			{
				t = on[j] % 6;
				t = 0 == t ? 6 : t;
				if( !(i&mark[t]) )
				{
					f = 0;
					break;
				}
			}

			for( j = 0; j < no; j++ )
			{
				t = off[j] % 6;
				t = 0 == t ? 6 : t;
				if( i&mark[t] )
				{
					f = 0;
					break;
				}
			}

			if( f )
			{
				ok = 1;
				for( j = 1; j <= n; j++ )
				{
					t = j%6;
					t = 0 == t ? 6 : t;
					printf("%d", ( i&mark[t] ) ? 1 : 0 );
				}
				printf("\n");
			}
		}
	}

	if( !ok )
	{
		printf("IMPOSSIBLE\n");
	}

    return 0;
}
