/*
  ID: lshain.1
  PROG: calfflac
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

char g_ori[20001];
int no;

struct node
{
	int p;
	char ch;
}g_text[20001], g_tt, g_ttt, *g_m[40004];

int nt;
int nm;
int l[40004];

void initText( )
{
	no = 0;
	while( ( g_ori[no] = getchar( ) ) != EOF )
	{
		no++;
	}

	g_ori[no] = 0;

	nt = 0;
	for( int i = 0; i < no; i++ )
	{
		if( ( g_ori[i] >= 'A' && g_ori[i] <= 'Z' ) || ( g_ori[i] >= 'a' && g_ori[i] <= 'z' ) )
		{
			g_text[nt].ch = g_ori[i] >= 'a' ? g_ori[i] : g_ori[i] + 32;
			g_text[nt].p = i;
			nt++;
		}
	}

	g_tt.ch = '#';
	g_tt.p = -1;

	g_ttt.ch = '$';
	g_ttt.p = -1;

	g_m[0] = &g_ttt;
	nm = 1;
	for( int i = 0; i < nt; i++ )
	{
		g_m[nm++] = &g_tt;
		g_m[nm++] = &g_text[i];
	}

	g_m[nm++] = &g_tt;
}

void calc( )
{
	int maxRight = 0;
	int ind = 0;
	int max = 0;
	int I = 0;
	int s = 0;
	int e = 0;

	// Manacher算法 求回文
	for( int i = 1; i < nm; i++ )
	{
		if( maxRight > i )
		{
			l[i] = l[(ind<<1) - i] < ( maxRight - i ) ? l[(ind<<1) - i] : ( maxRight - i );
		}
		else
		{
			l[i] = 1;
		}

		while( i + l[i] < nm && g_m[i - l[i]]->ch == g_m[i + l[i]]->ch )l[i]++;

		if( l[i] > max )
		{
			max = l[i];
			I = i;
		}

		if( i + l[i] > maxRight )
		{
			maxRight = i + l[i];
			ind = i;
		}
	}

	printf("%d\n", max - 1);

	s = I - max + 1;
	e = I + max - 1;
	if( s&1 )s++;
	if( e&1 )e--;
	for( int i = g_m[s]->p; i <= g_m[e]->p; i++ )
	{
		printf("%c", g_ori[i]);
	}

	if( max > 0 )
	{
		printf("\n");
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);

	initText( );
	calc( );

    return 0;
}
