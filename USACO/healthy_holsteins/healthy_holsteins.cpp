/*
  ID: lshain.1
  PROG: holstein
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

int n, m;
int re[25];
int val[15][25];
bool finish;
int ans[15];
int tp[15];
int sum[15];

void dfs( int ii, int x, int nn )
{
	if( !finish )
	{
		int i = 0;
		int j = 0;
		if( x == nn )
		{
			for( i = 0; i < nn; i++ )
			{
				printf(" %d", ans[i]);
			}
			printf("\n");

			for( i = 0; i < m; i++ )
			{
				if( sum[i] < re[i] )
				{
					return;
				}
			}

			finish = true;
		}
		else
		{
			for( i = ii; i < n && !finish; i++ )
			{
				ans[x] = i;

				for( j = 0; j < m; j++ )
				{
					sum[j] += val[i][j];
				}

				dfs( ii + 1, x + 1, nn );

				for( j = 0; j < m; j++ )
				{
					sum[j] -= val[i][j];
				}
			}
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "holstein.in", "r", stdin );
    freopen( "holstein.out", "w", stdout );

	scanf("%d", &m);
	int i = 0;
	for( i = 0; i < m; i++ )
	{
		scanf("%d", &re[i]);
	}

	scanf("%d", &n);
	int j = 0;
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < m; j++ )
		{
			scanf("%d", &val[i][j]);
		}
	}

	int min = 1;
	int max = n;
	int minans = 0;
	bool isok = false;
	while( min < max )
	{
		i = ( min + max )>>1;

		finish = false;
		dfs( 0, 0, i );

		if( finish )
		{
			minans = i;
			for( j = 0; j < i; j++ )
			{
				tp[j] = ans[j];
			}

			max = i - 1;
		}
		else
		{
			min = i + 1;
		}

		printf("i = %d\n", i);
	}

	printf("%d", minans);
	for( j = 0; j < minans; j++ )
	{
		printf(" %d", tp[j] + 1);
	}

	printf("\n");

    return 0;
}
