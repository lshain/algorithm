/*
  ID: lshain.1
  PROG: prefix
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

struct node
{
	char name[20];
}str[210];

int ns;
char seq[200010];
int seqlen;
int Q[200010];
int mark[200010];
int nq;

bool comp( struct node a, struct node b )
{
	return strcmp( a.name, b.name ) < 0;
}

bool ok( int I, int J )
{
	int min = 0;
	int max = ns;
	int mid = 0;
	int t = 0;
	char temp[10] = { 0 };

	for( int i = I; i <= J; i++ )
	{
		temp[i - I] = seq[i];
	}

	while( min <= max )
	{
		mid = (min + max)>>1;
		t = strcmp( str[mid].name, temp );
		if( t < 0 )
		{
			min = mid + 1;
		}
		else if( t == 0 )
		{
			return true;
		}
		else
		{
			max = mid - 1;
		}
	}

	return false;
}

int main( int argc, char* argv[], char* env[] )
{
    freopen( "prefix.in", "r", stdin );
    freopen( "prefix.out", "w", stdout );

	int maxLen = 0;
	int len = 0;
	ns = 0;
	while( scanf("%s", str[ns].name) && str[ns].name[0] != '.' )
	{
		len = strlen( str[ns].name );
		if( len > maxLen )
		{
			maxLen = len;
		}

		ns++;
	}

	sort( str, str + ns, comp );

	getchar( );

	seqlen = 0;
	char temp[80] = {0};
	int tlen = 0;
	while( scanf("%s", temp) != EOF )
	{
		tlen = strlen(temp);
		memcpy(&seq[seqlen], temp, tlen);
		seqlen += tlen;
	}

	seq[seqlen] = 0;

	int ans = 0;
	int np = 0;
	int nt = 0;
	int i = 0;
	int j = 0;
	int I = 0;
	nq = 0;
	Q[nq++] = 0;

	for( i = 0; i < seqlen; i++ )
	{
		mark[i] = false;
	}

	while( nt < nq )
	{
		np = nq;
		for( i = nt; i < np; i++ )
		{
			I = Q[i];
			for( j = I; j < I + maxLen && j < seqlen; j++ )
			{
				if( !mark[j + 1] && ok( I, j ) )
				{
					mark[j + 1] = true;
					Q[nq++] = j + 1;
					ans = j + 1;
				}
			}
		}

		nt = np;
	}

	printf("%d\n", ans);

    return 0;
}
