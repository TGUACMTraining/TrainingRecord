#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define rgt register
#define mod 998244353

int N, a[MAXN], fac, c[MAXN], ans;
char *p;

inline void read( rgt int &x ){
	x = 0; while( !isdigit(*p) ) ++p;
	while( isdigit(*p) ) x = x * 10 + ( *p & 15 ), ++p;
}

int main(){
	scanf( "%d", &N ), fac = 1;
	p = new char[N * 8 + 100],
	fread( p, 1, N * 8 + 100, stdin );
	for ( rgt int i = N; i; --i ) read(a[i]);//反向读取
	
	for ( rgt int i = 1, s, j; i <= N; ++i ){
		for ( s = 0, j = a[i]; j; j -= j & -j ) s += c[j];
		ans = ( ans + 1ll * fac * s ) % mod, fac = 1ll * fac * i % mod;
		for ( j = a[i]; j <= N; j += j & -j ) ++c[j];
	} printf( "%d\n", ans + 1 );
	return 0;
}