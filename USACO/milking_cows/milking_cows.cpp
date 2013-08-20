/*
  ID: lshain.1
  PROG: milk2
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
	int s;
	int e;
}eg[5001];

int n;

bool comp( struct node a, struct node b )
{
	if( a.s < b.s )
	{
		return true;
	}
	else if( a.s == b.s )
	{
		if( a.e < b.e )
		{
			return true;
		}
		else if( a.e == b.e )
		{
			return false;
		}

		return false;
	}

	return false;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	int ansA = 0;
	int ansB = 0;
	int s = 0;
	int e = 0;
	int i = 0;
	scanf("%d", &n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d%d", &eg[i].s, &eg[i].e);
	}

	sort( eg, eg + n, comp );

	s = eg[0].s;
	e = eg[0].e;
	ansA = e - s;
	ansB = 0;
	for( i = 1; i < n; i++ )
	{
		if( eg[i].s >= s && eg[i].s <= e )
		{
			if( eg[i].e > e )
			{
				e = eg[i].e;
				if( e - s > ansA )
				{
					ansA = e - s;
				}
			}
		}
		else
		{
			if( eg[i].s - e > ansB )
			{
				ansB = eg[i].s - e;
			}

			s = eg[i].s;
			e = eg[i].e;
		}
	}

	printf("%d %d\n", ansA, ansB);

    return 0;
}
