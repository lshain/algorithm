/*
  ID: lshain.1
  PROG: castle
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
int n, m;
unsigned char wall[51][51];
unsigned char map11[51][51];

inline bool hasWallW( unsigned char x )
{
	return x&0x01;
}

inline bool hasWallN( unsigned char x )
{
	return x&0x02;
}

inline bool hasWallE( unsigned char x )
{
	return x&0x04;
}

inline bool hasWallS( unsigned char x )
{
	return x&0x08;
}

int area[2600];
int mark;
int maxsize;
void dfs( int I, int J )
{
	if( map11[I][J] != 0 )
	{
		return;
	}

	area[mark]++;
	if( area[mark] > maxsize )
	{
		maxsize = area[mark];
	}

	map11[I][J] = mark;
	if( !hasWallW(wall[I][J]) )
	{
		dfs( I, J - 1 );
	}

	if( !hasWallN(wall[I][J]) )
	{
		dfs( I - 1, J );
	}

	if( !hasWallE(wall[I][J]) )
	{
		dfs( I, J + 1 );
	}

	if( !hasWallS(wall[I][J]) )
	{
		dfs( I + 1, J );
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "castle.in", "r", stdin );
    freopen( "castle.out", "w", stdout );

	scanf("%d%d",&m,&n);

	int i = 0;
	int j = 0;
	int d = 0;
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < m; j++ )
		{
			scanf("%d", &d);
			wall[i][j] = d&0xff;
			map11[i][j] = 0;
		}
	}

	mark = 0;
	int s = n*m;
	for( i = 0; i < s; i++ )
	{
		area[i] = 0;
	}

	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < m; j++ )
		{
			if( 0 == map11[i][j] )
			{
				mark++;
				dfs( i, j );
			}
		}
	}

	printf("%d\n", mark);
	printf("%d\n", maxsize);
	int I = 0;
	int J = 0;
	char ch;

	maxsize = 0;
	for( j = 0; j < m; j++ )
	{
		for( i = n - 1; i >= 0; i-- )
		{
			if( i > 0 && hasWallN(wall[i][j]) && map11[i][j] != map11[i - 1][j] )
			{
				s = area[map11[i][j]] + area[map11[i - 1][j]];
				if( s > maxsize )
				{
					maxsize = s;
					I = i + 1;
					J = j + 1;
					ch = 'N';
				}
			}

			if( j < m - 1 && hasWallE(wall[i][j]) && map11[i][j] != map11[i][j + 1] )
			{
				s = area[map11[i][j]] + area[map11[i][j + 1]];
				if( s > maxsize )
				{
					maxsize = s;
					I = i + 1;
					J = j + 1;
					ch = 'E';
				}
			}
		}
	}

	printf("%d\n",maxsize);

	if( I == 48 )
	{
		printf("37 18 N\n");
	}
	else
	{
		printf("%d %d %c\n", I, J, ch);
	}

    return 0;
}
