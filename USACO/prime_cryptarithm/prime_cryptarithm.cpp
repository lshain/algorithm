/*
  ID: lshain.1
  PROG: crypt1
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

int nd;
int dight[10];
int sel[10];
int ans = 0;
bool checka[1000];
bool checkb[100];
bool checkd[10];

bool checknum( int x )
{
	int t;
	bool ok = true;

	do
	{
		t = x % 10;
		x /= 10;
		ok = checkd[t];
	} while ( x > 0 && ok );

	return ok;
}

void calc( int n )
{
	if( 5 == n )
	{
		int a = sel[0]*100 + sel[1]*10 + sel[2];
		int b = sel[3]*10 + sel[4];
		if( a > 99 && b > 9 )
		{
			if( checka[a] || checkb[b] )
			{
				return;
			}

			int c = a * sel[4];
			if( c > 99 && c < 1000 && checknum(c) )
			{
				int d = a * sel[3];
				if( d > 99 && d < 1000 && checknum(d) )
				{
					int e = c + d*10;
					if( e > 999 && e < 10000 && checknum(e) )
					{
						ans++;
					}
				}
			}
		}
	}
	else
	{
		for( int i = 0; i < nd; i++ )
		{
			sel[n] = dight[i];
			calc( n + 1 );
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	for( int i = 0; i < 1000; i++ )
	{
		checka[i] = false;
	}

	for( int i = 0; i < 100; i++ )
	{
		checkb[i] = false;
	}

	for( int i = 0; i < 10; i++ )
	{
		checkd[i] = false;
	}

	scanf("%d", &nd);
	for( int i = 0; i < nd; i++ )
	{
		scanf("%d", &dight[i] );
		checkd[dight[i]]=true;
	}

	ans = 0;
	calc( 0 );
	printf("%d\n", ans);

    return 0;
}
