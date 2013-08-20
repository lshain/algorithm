
/*
  ID: lshain.1
  PROG: transform
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

char g_ori[10][10];
char g_tar[10][10];
char g_mid[10][10];
int n;

bool isEqu( )
{
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if( g_mid[i][j] != g_tar[i][j] )
			{
				return false;
			}
		}
	}

	return true;
}

char g_tmp[10][10];

void t1( char p[10][10] )
{
	memcpy( g_tmp, p, sizeof(g_tmp) );
	for( int j = 0; j < n; j++ )
	{
		for( int i = n - 1; i >= 0; i-- )
		{
			p[j][n - 1 - i] = g_tmp[i][j];
		}
	}
}

void reflection( char p[10][10] )
{
	memcpy( g_tmp, p, sizeof(g_tmp) );
	for( int i = 0; i < n; i++ )
	{
		for( int j = n - 1; j >= 0; j-- )
		{
			p[i][n - 1 - j] = g_tmp[i][j];
		}
	}
}

void initMid( )
{
	memcpy( g_mid, g_ori, sizeof(g_ori) );
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	scanf("%d", &n );
	int i = 0;
	for( i = 0; i < n; i++ )
	{
		scanf("%s", g_ori[i] );
	}

	for( i = 0; i < n; i++ )
	{
		scanf("%s", g_tar[i] );
	}

	int ans = 1;

	do
	{
		initMid( );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 1;
			break;
		}

		initMid( );
		t1( g_mid );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 2;
			break;
		}

		initMid( );
		t1( g_mid );
		t1( g_mid );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 3;
			break;
		}

		initMid( );
		reflection( g_mid );
		if( isEqu( ) )
		{
			ans = 4;
			break;
		}

		initMid( );
		reflection( g_mid );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 5;
			break;
		}

		initMid( );
		reflection( g_mid );
		t1( g_mid );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 5;
			break;
		}

		initMid( );
		reflection( g_mid );
		t1( g_mid );
		t1( g_mid );
		t1( g_mid );
		if( isEqu( ) )
		{
			ans = 5;
			break;
		}

		initMid( );
		if( isEqu( ) )
		{
			ans = 6;
			break;
		}

		ans = 7;
	}
	while( 0 );

	printf("%d\n", ans);

    return 0;
}
