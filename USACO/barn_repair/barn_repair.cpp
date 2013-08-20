/*
  ID: lshain.1
  PROG: barn1
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
}cow[201];

int nc = 0;

int main( int argc, char* argv[], char* env[] )
{
    freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	int n, m, c;
	int t = 0;
	int num[201];
	scanf("%d%d%d", &n, &m, &c);
	int i = 0;

	for( i = 0; i < c; i++ )
	{
		scanf("%d", &num[i]);
	}

	sort( num, num + c );

	cow[nc].s = num[0];
	cow[nc].e = num[0];
	nc++;
	for( i = 1; i < c; i++ )
	{
		if( num[i] == cow[nc - 1].e - 1 )
		{
			cow[nc - 1].e = num[i];
		}
		else
		{
			cow[nc].s = num[i];
			cow[nc].e = num[i];
			nc++;
		}
	}

	int min = 0;
	int I = 0;
	while( nc > n )
	{
		min = cow[1].s - cow[0].e;
		I = 1;
		for( i = 2; i < nc; i++ )
		{
			t = cow[i].s - cow[i - 1].e;
			if( t < min )
			{
				min = t;
				I = i;
			}
		}

		cow[I - 1].e = cow[I].e;
		for( i = I; i < nc; i++ )
		{
			cow[i].s = cow[i + 1].s;
			cow[i].e = cow[i + 1].e;
		}

		nc--;
	}

	int ans = 0;
	for( i = 0; i < nc; i++ )
	{
		ans += cow[i].e - cow[i].s + 1;
	}

	printf("%d\n", ans);

    return 0;
}
