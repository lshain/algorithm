/*
  ID: lshain.1
  PROG: gift1
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

struct persion
{
	char name[20];
	int money;
	int m;
	int lastmoney;
}per[20];

int getIndex( char* name, int n )
{
	int i = 0;
	for( i = 0; i < n; i++ )
	{
		if( strcmp(name,per[i].name) == 0 )
		{
			break;
		}
	}

	return i;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);

	int n = 0;
	int i = 0;
	char name[20];
	int I;
	int J;
	int j;
	scanf("%d", &n);
	for( i = 0; i < n; i++ )
	{
		scanf("%s", per[i].name);
		per[i].lastmoney = 0;
	}

	for( i = 0; i < n; i++ )
	{
		scanf("%s", name);
		I = getIndex(name, n);
		scanf("%d%d",&per[I].money, &per[I].m);
		for( j = 0; j < per[I].m; j++ )
		{
			scanf("%s", name);
			J = getIndex(name, n);
			per[J].lastmoney += per[I].money / per[I].m;
		}

		if(per[I].m != 0)
		{
			per[I].lastmoney += per[I].money % per[I].m;
		}
	}

	for( i = 0; i < n; i++ )
	{
		printf("%s %d\n", per[i].name, per[i].lastmoney - per[i].money );
	}

    return 0;
}
