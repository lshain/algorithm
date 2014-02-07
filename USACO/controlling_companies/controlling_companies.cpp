/*
  ID: lshain.1
  PROG: concom
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

int com[101][101];
bool control[101];
int sum[101];
int n;

int main( int argc, char* argv[], char* env[] )
{
    freopen( "concom.in", "r", stdin );
    freopen( "concom.out", "w", stdout );

	int m = 0;

	scanf( "%d", &m );

	int i = 0;
	int j = 0;
	int k = 0;
	int I = 0;
	int J = 0;
	int p = 0;
	int nc = 0;
	int t = 0;

	for( i = 0; i < 101; i++ )
	{
		for( j = 0; j < 101; j++ )
		{
			com[i][j] = 0;
		}
	}

	for( i = 0; i < m; i++ )
	{
		scanf( "%d%d%d", &I, &J, &p );
		n = n > I ? n : I;
		n = n > J ? n : J;
		com[I][J] = p;
	}

	for( i = 1; i <= n; i++ )
	{
		nc = 0;
		for( j = 1; j <= n; j++ )
		{
			control[j] = false;
			if( com[i][j] > 50 )// 直接控制
			{
				control[j] = true;
				nc++;
			}
		}

		if( nc > 0 )
		{
			t = 0;
			while( t < nc )// 循环计算间接控制
			{
				t = nc;

				for( j = 1; j <= n; j++ )
				{
					sum[j] = com[i][j];// 初始化为当前公司拥有各公司股份数量
				}

				for( j = 1; j <= n; j++ )
				{
					if( control[j] )
					{
						for( k = 1; k <= n; k++ )
						{
							sum[k] += com[j][k];
						}
					}
				}

				for( j = 1; j <= n; j++ )
				{
					if( sum[j] > 50 && !control[j] )
					{
						control[j] = true;
						nc++;
					}
				}
			}

			for( j = 1; j <= n; j++ )
			{
				if( i != j && control[j] )
				{
					printf( "%d %d\n", i, j );
				}
			}
		}
	}

    return 0;
}
