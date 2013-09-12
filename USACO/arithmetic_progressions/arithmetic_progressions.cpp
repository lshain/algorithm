
/*
  ID: lshain.1
  PROG: ariprog
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

struct arith
{
	int s;
	int d;
}ans[10001];

int ns;
int N;
int M;
bool mark[2*251*251];
int number[2*251*251];
int nn;

bool comp( struct arith a, struct arith b )
{
	return a.d < b.d ? true : ( a.d == b.d && a.s < b.s ? true : false );
}

void work( )
{
	int size = M*M + M*M;
	int i = 0;
	int j = 0;
	int k = 0;
	int x = 0;
	int d = 0;

	for( i = 0; i < size; i++ )
	{
		mark[i] = false;
	}

	for( i = 0; i <= M; i++ )
	{
		for( j = i; j <= M; j++ )
		{
			x = i*i + j*j;
			mark[x] = true;
		}
	}

	nn = 0;
	for( i = 0; i < size; i++ )
	{
		if( mark[i] )
		{
			number[nn++] = i;
		}
	}

	ns = 0;
	for( i = 0; i < nn; i++ )
	{
		for( j = i + 1; j < nn; j++ )
		{
			x = number[j];
			d = number[j] - number[i];
			for( k = 2; k < N; k++ )
			{
				x += d;
				if( x > size || !mark[x] )
				{
					break;
				}
			}

			if( k >= N )
			{
				ans[ns].s = number[i];
				ans[ns].d = d;
				ns++;
			}
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "ariprog.in", "r", stdin );
    freopen( "ariprog.out", "w", stdout );

	scanf("%d%d", &N, &M);

	work( );

	if( 0 == ns )
	{
		printf("NONE\n");
	}
	else
	{
		sort( ans, ans + ns, comp );
		for( int i = 0; i < ns; i++ )
		{
			printf("%d %d\n", ans[i].s, ans[i].d );
		}
	}

    return 0;
}
