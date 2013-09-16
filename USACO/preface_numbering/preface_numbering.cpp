/*
  ID: lshain.1
  PROG: preface
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
char sig[10] = "IVXLCDM";
int cc[7];
char dstr[4][9][10] =
{
	{ "I","II","III","IV","V","VI","VII","VIII","IX" },
	{ "X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
	{ "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
	{ "M","MM","MMM","","","","","",""}
};

void roman( int x )
{
	int tt = x;
	int di[10];
	int nd;
	nd = 0;
	do
	{
		di[nd++] = x%10;
		x/=10;
	}
	while( x > 0 );

	int i = 0;
	int j = 0;
	int t = 1;
	int ns = 0;
	char* pstr = NULL;

	// printf("x = %d\n", tt);
	// for( i = nd - 1; i >= 0; i-- )
	// {
	// 	printf("%s", dstr[i][di[i] - 1]);
	// }printf("\n");

	for( i = 0; i < nd; i++ )
	{
		if( di[i] <= 0 )
		{
			continue;
		}

		if( i < 3 )
		{
			pstr = dstr[i][di[i] - 1];
			ns = strlen(pstr);
			//printf("x = %d i = %d %s\n", x, i, pstr);
			for( j = 0; j < ns; j++ )
			{
				switch( pstr[j] )
				{
				case 'I':
				{
					cc[0]++;
					break;
				}

				case 'V':
				{
					cc[1]++;
					break;
				}

				case 'X':
				{
					cc[2]++;
					break;
				}

				case 'L':
				{
					cc[3]++;
					break;
				}

				case 'C':
				{
					cc[4]++;
					break;
				}

				case 'D':
				{
					cc[5]++;
					break;
				}

				case 'M':
				{
					cc[6]++;
					break;
				}
				}
			}
		}
		else
		{
			cc[6] += di[i]*t;
			t *= 10;
		}
	}
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "preface.in", "r", stdin );
    freopen( "preface.out", "w", stdout );

	scanf("%d", &n);

	int i = 0;

	for( i = 0; i < 7; i++ )
	{
		cc[i] = 0;
	}

	for( i = 1; i <= n; i++ )
	{
		roman( i );
	}

	for( i = 0; i < 7; i++ )
	{
		if( cc[i] != 0 )
		{
			printf("%c %d\n", sig[i], cc[i]);
		}
	}

    return 0;
}
