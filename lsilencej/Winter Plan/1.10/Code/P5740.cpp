#include<bits/stdc++.h>
using namespace std;
struct Stu{
	string name;
	int x, y, z;
	int grade;
} p[5000];
int cmp(Stu a, Stu b) {
	return a.grade > b.grade;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[i].name = s;
		p[i].x = a;
		p[i].y = b;
		p[i].z = c;
		p[i].grade = a + b + c;
	}
	sort(p + 1, p + 1 + n, cmp);
	cout << p[1].name << " " << p[1].x << " " << p[1].y << " " << p[1].z;
	return 0;
}
