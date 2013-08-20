/*
  ID: lshain.1
  PROG: namenum
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

char g_dict[5001][13];
int ndict;
void initDict( )
{
	FILE* fp = fopen( "dict.txt", "r" );
	if( fp != NULL )
	{
		ndict = 0;
		for( int i = 0; i < 4617; i++ )
		{
			fscanf(fp, "%s", g_dict[ndict++] );
		}

		fclose( fp );
	}
}

char g_dight[13];
char g_ans[13];
int ndight;

char g_s[10][3] =
{
	{   0,   0,   0 }, {   0,   0,   0 }, { 'A', 'B', 'C' },
	{ 'D', 'E', 'F' }, { 'G', 'H', 'I' }, { 'J', 'K', 'L' },
	{ 'M', 'N', 'O' }, { 'P', 'R', 'S' }, {	'T', 'U', 'V' },
	{ 'W', 'X', 'Y' }
};

bool g_ok;

void comp( )
{
	int min = 0;
	int max = ndict - 1;
	int mid = 0;
	int t = 0;
	while( min <= max )
	{
		mid = (min + max)>>1;
		t = strcmp( g_ans, g_dict[mid] );
		if( 0 == t )
		{
			printf("%s\n", g_ans);
			g_ok = true;
			break;
		}
		else if( t < 0 )
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}
}

void dfs( int n )
{
	if( n >= ndight )
	{
		g_ans[n] = 0;
		comp( );
		return;
	}

	int number = g_dight[n] - 48;
	for( int i = 0; i < 3; i++ )
	{
		g_ans[n] = g_s[number][i];
		dfs( n + 1 );
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	initDict( );
	scanf("%s", g_dight);
	ndight = strlen(g_dight);
	g_ok = false;
	dfs( 0 );
	if( !g_ok )
	{
		printf("NONE\n");
	}
    return 0;
}
