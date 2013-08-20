/*
  ID: lshain.1
  PROG: dualpal
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

int n;
int s;

bool ok( int num, int base )
{
	bool isOk = true;

	int dight[12];
	int nd = 0;

	while( num > 0 )
	{
		dight[nd++] = num%base;
		num /= base;
	}

	int i = 0;
	int j = nd - 1;
	while( i < j )
	{
		if( dight[i] != dight[j] )
		{
			isOk = false;
			break;
		}

		i++;
		j--;
	}

	return isOk;
}

bool check( int num )
{
	int c = 0;
	int i = 0;
	for( i = 2; i < 11; i++ )
	{
		if( ok( num, i ) )
		{
			c++;
		}
	}

	return c > 1;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	scanf("%d%d", &n, &s);

	int c = 0;
	for( int i = s + 1; c < n; i++ )
	{
		if( check( i ) )
		{
			printf("%d\n", i);
			c++;
		}
	}

    return 0;
}
