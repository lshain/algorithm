

/*
  ID: lshain.1
  PROG: checker
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

int n;
int na;
int ans[14];
unsigned int bits[33];
unsigned int lt_rb[33];
unsigned int tb[33];
unsigned int rt_lb[33];

inline bool ok( int I, int J )
{
	if( ( tb[J] | bits[I] ) != bits[I] )
	{
		return false;
	}

    if( I >= J )
	{
		if( ( rt_lb[n + I - J] | bits[J] ) != bits[J] )
		{
			return false;
		}
	}
	else
	{
		if( ( rt_lb[n + I - J] | bits[I] ) != bits[I] )
		{
			return false;
		}
	}

	if( I <= n - J + 1 )
	{
		if( ( lt_rb[I + J - 1] | bits[I] ) != bits[I] )
		{
			return false;
		}
	}
	else
	{
		if( ( lt_rb[I + J - 1] | bits[n - J + 1] ) != bits[n - J + 1] )
		{
			return false;
		}
	}

	return true;
}

inline void setbits( int I, int J )
{
	tb[J] |= bits[I];

	if( I >= J )
	{
		rt_lb[n + I - J] |= bits[J];
	}
	else
	{
		rt_lb[n + I - J] |= bits[I];
	}

	if( I <= n - J + 1 )
	{
		lt_rb[I + J - 1] |= bits[I];
	}
	else
	{
		lt_rb[I + J - 1] |= bits[n - J + 1];
	}
}

inline void unsetbits( int I, int J )
{
	tb[J] &= ~bits[I];

	if( I >= J )
	{
		rt_lb[n + I - J] &= ~bits[J];
	}
	else
	{
		rt_lb[n + I - J] &= ~bits[I];
	}

	if( I <= n - J + 1 )
	{
		lt_rb[I + J - 1] &= ~bits[I];
	}
	else
	{
		lt_rb[I + J - 1] &= ~bits[n - J + 1];
	}
}

void dfs( int t )
{
	if( t == n + 1 )
	{
		if( na < 3 )
		{
			for( int i = 1; i <= n; i++ )
			{
				if( i != 1 )
				{
					printf(" ");
				}

				printf("%d", ans[i]);
			}

			printf("\n");
		}

		na++;
	}
	else
	{
		for( int i = 1; i <= n; i++ )
		{
			if( ok( t, i ) )
			{
				ans[t] = i;

				setbits( t, i );
				dfs( t + 1 );
				unsetbits( t, i );
			}
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "checker.in", "r", stdin );
    freopen( "checker.out", "w", stdout );

	scanf("%d",&n);

	int i = 0;
	unsigned int c = 0x80000000;

	for( i = 1; i < 32; i++ )
	{
		bits[i] = c>>(i - 1);
		lt_rb[i] = 0;
		tb[i] = 0;
		rt_lb[i] = 0;
	}

	na = 0;
	dfs(1);
	printf("%d\n", na);
    return 0;
}
