/*
  ID: lshain.1
  PROG: subset
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
int ans[2][800];

int main( int argc, char* argv[], char* env[] )
{
    freopen( "subset.in", "r", stdin );
    freopen( "subset.out", "w", stdout );

	scanf("%d", &n);

	int s = n*(n + 1)/2;
	ans[1][0] = 0;
	if( !(s&1) )
	{
		int i = 0;
		int j = 0;
		int d = 0;
		for( i = 0; i <= s; i++ )
		{
			ans[0][i] = ans[1][i] = 0;
		}

		ans[1][1] = 1;
		for( i = 2; i <= n; i++ )
		{
			for( j = 0; j <= s; j++ )
			{
				ans[0][j] = ans[1][j];
				ans[1][j] = 0;
			}

			for( j = 0; j <= s; j++ )
			{
				if( ans[0][j] != 0 )
				{
					d = j - i;
					if( d < 0 )
					{
						d = -d;
					}

					ans[1][d] += ans[0][j];
					ans[1][j + i] += ans[0][j];
				}
			}
		}
	}

	printf("%d\n", ans[1][0]);

    return 0;
}
