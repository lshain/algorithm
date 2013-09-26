/*
  ID: lshain.1
  PROG: zerosum
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
int oper[10];
int num[10];
char oo[3]={ ' ', '+','-' };
int nm;

void dfs( int x )
{
	if( x == n - 1 )
	{
		int i = 0;
		int j = 0;

		nm = 2;
		num[1] = 1;
		for( i = 2; i <= n; i++ )
		{
			if( 0 == oper[i - 2] )
			{
				num[nm - 1] = num[nm - 1]*10 + i;
			}
			else
			{
				num[nm++] = i;
			}
		}

		for( i = 2, j = 0; i < nm; i++ )
		{
			while( 0 == oper[j] )j++;
			if( 1 == oper[j] )// +
			{
				num[1] += num[i];
			}
			else if( 2 == oper[j] )// -
			{
				num[1] -= num[i];
			}

			j++;
		}

		if( 0 == num[1] )
		{
			printf("1");
			for( i = 2; i <= n; i++ )
			{
				printf("%c%d", oo[oper[i - 2]], i);
			}

			printf("\n");
		}
	}
	else
	{
		for( int i = 0; i < 3; i++ )// 0 ' ', 1-, 2 +
		{
			oper[x] = i;
			dfs( x + 1 );
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "zerosum.in", "r", stdin );
    freopen( "zerosum.out", "w", stdout );

	scanf("%d", &n);
	dfs( 0 );

    return 0;
}
