#include<bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 1; i <= 7; i++) {
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	while (n--) {
		int sum = 0;
		for (int i = 1; i <= 7; i++) {
			int t;
			scanf("%d", &t);
			vector<int>::iterator it;
			it = find(v.begin(), v.end(), t);
			if (it != v.end()) sum++;
		}
		a[sum]++;
	}
	for (int i = 7; i >= 1; i--) printf("%d ", a[i]);
	return 0;
}
