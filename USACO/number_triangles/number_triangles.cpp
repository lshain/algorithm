
/*
  ID: lshain.1
  PROG: numtri
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

#define     N     1001
int num[N][N];
int ans[N][N];
int n;

int main( int argc, char* argv[], char* env[] )
{
    freopen( "numtri.in", "r", stdin );
    freopen( "numtri.out", "w", stdout );

    int i = 0;
    int j = 0;
    int max = 0;

    scanf( "%d", &n );
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j <= i; j++ )
		{
            scanf("%d", &num[i][j] );
            ans[i][j] = num[i][j];
        }

        if( i > 0 )
		{
            for( j = 0; j <= i - 1; j++ )
			{
                 if( ans[i - 1][j] + num[i][j] > ans[i][j] )
				 {
ans[i][j] = ans[i - 1][j] + num[i][j];
                 }

                 if( ans[i - 1][j] + num[i][j+1] > ans[i][j+1] )
				 {
ans[i][j+1] = ans[i - 1][j] + num[i][j+1];
                 }
            }
        }
    }

	for( i = 0; i < n; i++ )
	{
		if( ans[n - 1][i] > max )
		{
			max = ans[n - 1][i];
		}
	}

	printf("%d\n", max);

    return 0;
}
