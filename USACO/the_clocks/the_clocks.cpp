/*
  ID: lshain.1
  PROG: clocks
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

#define MAX_SIZE    (1<<18)
int queue[MAX_SIZE + 2];
int pre[MAX_SIZE + 2];
int oper[MAX_SIZE + 2];
unsigned int pos[10] =
{
	0x00000000,
	0x00030000,
	0x0000C000,
	0x00003000,
	0x00000C00,
	0x00000300,
	0x000000C0,
	0x00000030,
	0x0000000C,
	0x00000003
};

unsigned int add[10] =
{
	0x00000000,
	0x00010000,
	0x00004000,
	0x00001000,
	0x00000400,
	0x00000100,
	0x00000040,
	0x00000010,
	0x00000004,
	0x00000001
};

int nq;
const unsigned int end = 0x0003FFFF;
unsigned int start = 0;

unsigned int turn( unsigned int x, int o )
{
	unsigned int r = 0;

	switch( o )
	{
	case 1://ABDE
		r = ( ( x & pos[1] ) + add[1] ) & pos[1];
		r += ( ( x & pos[2] ) + add[2] ) & pos[2];
		r += ( ( x & pos[4] ) + add[4] ) & pos[4];
		r += ( ( x & pos[5] ) + add[5] ) & pos[5];

		r += x & ( ~( pos[1] | pos[2] | pos[4] | pos[5] ) );
		break;

	case 2://ABC
		r = ( ( x & pos[1] ) + add[1] ) & pos[1];
		r += ( ( x & pos[2] ) + add[2] ) & pos[2];
		r += ( ( x & pos[3] ) + add[3] ) & pos[3];

		r += x & ( ~( pos[1] | pos[2] | pos[3] ) );
		break;

	case 3://BCEF
		r = ( ( x & pos[2] ) + add[2] ) & pos[2];
		r += ( ( x & pos[3] ) + add[3] ) & pos[3];
		r += ( ( x & pos[5] ) + add[5] ) & pos[5];
		r += ( ( x & pos[6] ) + add[6] ) & pos[6];

		r += x & ( ~( pos[2] | pos[3] | pos[5] | pos[6] ) );
		break;

	case 4://ADG
		r = ( ( x & pos[1] ) + add[1] ) & pos[1];
		r += ( ( x & pos[4] ) + add[4] ) & pos[4];
		r += ( ( x & pos[7] ) + add[7] ) & pos[7];

		r += x & ( ~( pos[1] | pos[4] | pos[7] ) );
		break;

	case 5://BDEFH
		r = ( ( x & pos[2] ) + add[2] ) & pos[2];
		r += ( ( x & pos[4] ) + add[4] ) & pos[4];
		r += ( ( x & pos[5] ) + add[5] ) & pos[5];
		r += ( ( x & pos[6] ) + add[6] ) & pos[6];
		r += ( ( x & pos[8] ) + add[8] ) & pos[8];

		r += x & ( ~( pos[2] | pos[4] | pos[5] | pos[6] | pos[8]) );
		break;

	case 6://CFI
		r = ( ( x & pos[3] ) + add[3] ) & pos[3];
		r += ( ( x & pos[6] ) + add[6] ) & pos[6];
		r += ( ( x & pos[9] ) + add[9] ) & pos[9];

		r += x & ( ~( pos[3] | pos[6] | pos[9] ) );
		break;

	case 7://DEGH
		r = ( ( x & pos[4] ) + add[4] ) & pos[4];
		r += ( ( x & pos[5] ) + add[5] ) & pos[5];
		r += ( ( x & pos[7] ) + add[7] ) & pos[7];
		r += ( ( x & pos[8] ) + add[8] ) & pos[8];

		r += x & ( ~( pos[4] | pos[5] | pos[7] | pos[8] ) );
		break;

	case 8://GHI
		r = ( ( x & pos[7] ) + add[7] ) & pos[7];
		r += ( ( x & pos[8] ) + add[8] ) & pos[8];
		r += ( ( x & pos[9] ) + add[9] ) & pos[9];

		r += x & ( ~( pos[7] | pos[8] | pos[9] ) );
		break;

	case 9://EFHI
		r = ( ( x & pos[5] ) + add[5] ) & pos[5];
		r += ( ( x & pos[6] ) + add[6] ) & pos[6];
		r += ( ( x & pos[8] ) + add[8] ) & pos[8];
		r += ( ( x & pos[9] ) + add[9] ) & pos[9];

		r += x & ( ~( pos[5] | pos[6] | pos[8] | pos[9] ) );
		break;
	}

	return r;
}

inline unsigned int make( unsigned int a, unsigned int b )
{
	return ( a/3 - 1 )<<b;
}

int tt = 0;
void printAns( unsigned int x )
{
	tt = pre[x];
	if( tt != -2 )
	{
		printAns( queue[tt] );
		printf("%d", oper[x] );
		if( x != end )
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "clocks.in", "r", stdin );
    freopen( "clocks.out", "w", stdout );

	int a = 0;
	int b = 0;
	int c = 0;

	start = 0;
	scanf("%d%d%d",&a,&b,&c);
	start += make(a, 16) + make(b, 14) + make(c, 12);
	scanf("%d%d%d",&a,&b,&c);
	start += make(a, 10) + make(b, 8) + make(c, 6);
	scanf("%d%d%d",&a,&b,&c);
	start += make(a, 4) + make(b, 2) + make(c, 0);

	nq = 0;
	int t = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int np = 0;

	for( i = 0; i < MAX_SIZE; i++ )
	{
		pre[i] = -1;
	}

	queue[nq++] = start;
	pre[start] = -2;
	while( t < nq )
	{
		np = nq;
		for( i = t; i < np; i++ )
		{
			start = queue[i];
			if( start == end )
			{
				break;
			}

			for( j = 1; j < 10; j++ )
			{
				x = turn( start, j );
				if( -1 == pre[x] )
				{
					pre[x] = i;
					oper[x] = j;
					queue[nq++] = x;
				}
			}
		}

		t = np;
	}

	printAns( end );

    return 0;
}
