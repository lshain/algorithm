/*
  ID: lshain.1
  PROG: hamming
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

int ni;
int bi;
int di;
int ans[65];

int getBitDiff( unsigned char a, unsigned char b )
{
	unsigned char ch = 0x80;
	int count = 0;
	for( int i = 0; i < 8; i++ )
	{
		count += ( (ch&a) != (ch&b) );
		ch>>=1;
	}

	return count;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "hamming.in", "r", stdin );
    freopen( "hamming.out", "w", stdout );

	scanf("%d%d%d", &ni, &bi, &di);
	int na = 1;
	int i = 0;
	int j = 0;
	int nn = 1<<( bi + 1 );
	bool ok = false;
	for( i = 0; i < nn; i++ )
	{
		ok = true;
		for( j = 1; j < na; j++ )
		{
			if( getBitDiff( i, ans[j] ) < di )
			{
				ok = false;
				break;
			}
		}

		if( ok && na <= ni )
		{
			ans[na++] = i;
		}
	}

	for( i = 1; i <= ni; i++ )
	{
		printf("%d", ans[i]);
		if( i%10 && i != ni )
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

    return 0;
}
