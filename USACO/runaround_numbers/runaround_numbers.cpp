/*
  ID: lshain.1
  PROG: runround
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

int main( int argc, char* argv[], char* env[] )
{
    freopen( "runround.in", "r", stdin );
	freopen( "runround.out", "w", stdout );

	int n;
	scanf("%d", &n);

	int dig[20] = {0};
	int num[20] = {0};
	int mark[10];
	int check[20];
	int nd = 0;
	int temp = 0;
	int i = 0;
	bool finish = false;
	int start = 0;
	do
	{
		dig[nd++] = n%10;
		n /= 10;
	} while ( n > 0 );

	while( !finish )
	{
		temp = 1;
		i = 0;
		while( temp > 0 && i < nd )
		{
			dig[i] = dig[i] + temp;
			if( dig[i] > 9 )
			{
				temp = 1;
				dig[i] -= 10;
				if( !dig[i] )
				{
					dig[i] = 1;
				}
			}
			else
			{
				temp = 0;
				break;
			}

			i++;
		}

		if( temp > 0 )
		{
			dig[i] = temp;
			nd = i + 1;
		}

		for( i = 0; i < 10; i++ )
		{
			mark[i] = 0;
		}

		finish = true;

		for( i = 0; i < nd; i++ )
		{
			if( mark[dig[i]] )
			{
				finish = false;
				break;
			}

			mark[dig[i]] = 1;

			check[i] = 0;
			num[i] = dig[nd - 1 - i];
		}

		check[0] = 1;
		start = 0;
		for( i = 0; i < nd && finish; i++ )
		{
			start = ( start + 1 + num[start] ) % nd;
			if( !start )
			{
				start = nd - 1;
			}
			else
			{
				start--;
			}

			if( !check[start] )
			{
				check[start] = 1;
			}
			else
			{
				if( i == nd - 1 && start == 0 )
				{
					break;
				}

				finish = false;
				break;
			}
		}
	}

	for( i = nd - 1; i >= 0; i-- )
	{
		printf("%d", dig[i]);
	}
	printf("\n");

    return 0;
}
