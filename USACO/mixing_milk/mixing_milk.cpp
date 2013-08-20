/*
  ID: lshain.1
  PROG: milk
  LANG: C++
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct node
{
	int p;
	int c;
}fa[5001];

bool comp( struct node a, struct node b )
{
	return a.p < b.p;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	int n;
	int m;

	scanf("%d%d", &n, &m);

	int i = 0;
	for( i = 0; i < m; i++ )
	{
		scanf("%d%d", &fa[i].p, &fa[i].c);
	}

	sort( fa, fa + m, comp );

	int ans = 0;
	int c = 0;
	int re = 0;
	for( i = 0; i < m; i++ )
	{
		re = n - c;
		if( 0 == re )
		{
			break;
		}

		re = re < fa[i].c ? re : fa[i].c;

		c += re;
		ans += re*fa[i].p;
	}

	printf("%d\n", ans);

    return 0;
}
