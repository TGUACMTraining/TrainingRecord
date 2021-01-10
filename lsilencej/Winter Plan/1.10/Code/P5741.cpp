#include<bits/stdc++.h>
using namespace std;
struct Stu{
	string name;
	int x, y, z;
	int grade;
} p[5000];
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
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(p[i].x - p[j].x) <= 5 && abs(p[i].y - p[j].y) <= 5 && abs(p[i].z - p[j].z) <= 5 && abs(p[i].grade - p[j].grade) <= 10) {
				cout << p[i].name << " " << p[j].name << endl;
			}
		}
	}
	return 0;
}
