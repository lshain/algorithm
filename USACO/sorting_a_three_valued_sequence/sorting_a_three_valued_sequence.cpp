/*
  ID: lshain.1
  PROG: sort3
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

int num[1001];
int sorted[1001];
int di[4];

int main( int argc, char* argv[], char* env[] )
{
    freopen( "sort3.in", "r", stdin );
    freopen( "sort3.out", "w", stdout );

	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int ans = 0;
	for( i = di[1] = di[2] = di[3] = 0; i < n; i++ )
	{
		scanf("%d", &num[i]);
		di[num[i]]++;
	}

	for( i = 0; i < di[1]; i++ )
	{
		sorted[i] = 1;
	}

	for( i = di[1]; i < di[1] + di[2]; i++ )
	{
		sorted[i] = 2;
	}

	for( i = di[1] + di[2]; i < di[1] + di[2] + di[3]; i++ )
	{
		sorted[i] = 3;
	}

	ans = 0;
	int j = 0;
	int un = 0;
	bool ok = false;
	for( i = 0; i < n; i++ )
	{
		if( num[i] != sorted[i] )
		{
			ok = false;
			for( j = i + 1; j < n; j++ )
			{
				if( num[j] == sorted[i] && sorted[j] == num[i] )
				{
					ans++;
					num[i] = sorted[i];
					num[j] = sorted[j];
					ok = true;
					break;
				}
			}

			if( !ok )
			{
				un++;
			}
		}
	}

	printf("%d\n", ans + ( un != 0 ? (un/3)*2 : 0 ) );

    return 0;
}
