#include <iostream>
using namespace std;
int kl[4][2] = {{1,1},{-1,1},{-1,-1},{1,-1}} ;
int dep[100000][2]  ;
int N2[400000], N2s[200000] ;
int pla[100000] ;
int num ,total , flag  ;
void print()
{
	int i ;
	for( i = 0 ; i< total ; i++ )
	{
		if ( dep[i][0] > 0 ) cout << '+' ;
		cout << dep[i][0] << ' ' ;
        if ( dep[i][1] > 0 ) cout << '+' ;
		cout << dep[i][1] << endl ;
	}
}

void search( int m, int n , int layer )
{
	int i ,j ;
	if ( flag == 1 ) return ;
	if ( layer == total ) 
	{
		print() ;
		flag = 1 ;
		return ;
	}
	for( i = 0 ; i < num ; i++ )
    {
		if ( (m + N2[i]) * kl[pla[layer]][0] > 0 && 	N2s[ i % (total*2) ] == 0 )
		{
			N2s[ i % (total*2) ] = 1 ;
			for( j = 0 ; j < num ; j++ )
			{
				if ( (n + N2[j]) * kl[pla[layer]][1] > 0  && 	N2s[ j % (total*2) ] == 0)
				{
					dep[layer][0] = N2[i] ;
					dep[layer][1] = N2[j] ;
					N2s[ j % (total*2) ] = 1 ;
					search( m + N2[i] , n + N2[j] ,layer+1 ) ;
                    N2s[ j % (total*2) ] = 0 ;
				}
			}
            N2s[ i % (total*2) ] = 0 ;
		}
	}
}

int main()
{
	int  i;
    flag = 0 ;
	cin >> total ;
	i = 0 ;
   
	for( i = 0 ; i < total*2 ; i++ )
	{
		cin >> N2[ i ] ;
		N2s[i] = 0 ;
	}
	for( i = 0 ; i < total ; i++ )
	{
		cin >> pla[i] ;
		pla[i] -- ;
	}
	for( i = 0 ; i < total*2 ; i++ )
		N2[ i + total*2 ] = -N2[ i ] ;
    num = total * 4  ;
    search( 0 , 0 , 0 );
	if ( flag == 0 ) cout << 0  ;
	return 0;
}
