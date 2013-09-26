/*
  ID: lshain.1
  PROG: nocows
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

#define MODE 9901
int nn;
int kk;

unsigned long long ff[210][110];

int main( int argc, char* argv[], char* env[] )
{
    freopen( "nocows.in", "r", stdin );
    freopen( "nocows.out", "w", stdout );

	scanf("%d%d", &nn, &kk);
	int i = 0;
	int j = 0;
	int ii = 0;
	int jj = 0;
	for( i = 0; i <= nn; i++ )
	{
		for( j = 0; j<= kk; j++ )
		{
			ff[i][j] = 0;
		}
	}

	ff[1][1] = 1;

	unsigned long long t = 0;
	for( i = 2; i <= nn; i++ )
	{
		for( j = 1; j <= kk; j++ )
		{
			for( ii = 1; ii <= i - 2; ii++ )
			{
				t = 0;
				if( ff[ii][j - 1] != 0 )// 优化一下， 不然超时。
				{
					for( jj = 1; jj < j - 1; jj++ )
					{
						t += ( (ff[ii][j - 1]*ff[i - 1 - ii][jj])<<1 )%MODE;
					}

					ff[i][j] = ( ff[i][j] + ( t + ff[ii][j - 1]*ff[i - 1 - ii][j - 1] ) )%MODE;
				}
			}
		}
	}

/*	for( i = 1; i <= nn; i++ )
	{
		for( j = 1; j <= kk; j++ )
		{
			printf("%lld ", ff[i][j]);
		}

		printf("\n");
		}*/

	printf("%lld\n", ff[nn][kk]);

    return 0;
}
