#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main() {


	int n,m;
	while(scanf("%d%d", &n, &m) != EOF) {
		int a[1000];
		for(int i = 0; i < n; i ++) {
			a[i] = i + 1;
		}







		for(int i = 1; i < m; i ++) {
			next_permutation(a,a + n);
		}
		int g = 0;
		for(; g < n; g++) {
			cout << a[g];
			if(g != n-1) cout << ' ';
			else printf("\n");

		}

	}




}
