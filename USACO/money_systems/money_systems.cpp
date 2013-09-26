/*
  ID: lshain.1
  PROG: money
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

unsigned long long ans[10001];
unsigned long long vv[26];
int v, n;

int main( int argc, char* argv[], char* env[] )
{
    freopen( "money.in", "r", stdin );
    freopen( "money.out", "w", stdout );

	scanf("%d%d", &v, &n);
	int i = 0;
	int j = 0;
	int k = 0;
	for( i = 0; i < v; i++ )
	{
		scanf("%lld",&vv[i]);
	}

	for( i = 0; i < n; i++ )
	{
		ans[i] = 0;
	}

	ans[0] = 1;
	for( i = 0; i < v; i++ )
	{
		for( j = n; j >= 0; j-- )
		{
			for( k = j - vv[i]; k >= 0; k -= vv[i] )
			{
				ans[j] += ans[k];
			}
		}
	}

	printf("%lld\n", ans[n]);

    return 0;
}
