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
int na;
int ans[15];
int tp[15];
int sum[25];
int minans;

void dfs( int x )// 枚举 每项 选还是不选
{
	if( x > n )
	{
		return;
	}

	int i = 0;
	int j = 0;
	if( x > 0 && na < minans )
	{
		bool ok = true;
		for( i = 0; i < m; i++ )
		{
			if( sum[i] < re[i] )
			{
				ok = false;
				break;
			}
		}

		if( ok )
		{
			//	printf("na = %d\n", na);
			minans = na;
			for( i = 0; i < na; i++ )
			{
				tp[i] = ans[i];
			}
		}
	}

	for( i = 1; i >= 0; i-- )
	{
		if( i != 0 )
		{
			ans[na++] = x;
			for( j = 0; j < m; j++ )
			{
				sum[j] += val[x][j];
			}
		}

		dfs( x + 1 );

		if( i != 0 )
		{
			for( j = 0; j < m; j++ )
			{
				sum[j] -= val[x][j];
			}
			na--;
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

	na = 0;
	minans = n + 1;
	dfs( 0 );

	printf("%d", minans);
	for( i = 0; i < minans; i++ )
	{
		printf(" %d", tp[i] + 1);
	}

	printf("\n");

    return 0;
}
