#include<bits/stdc++.h>
using namespace std;
struct Stu {
	string name;
	int age, grade;
} a[20000];
void pei(Stu &s) {
	s.age++;
	s.grade /= 5;
	s.grade *= 6;
	if (s.grade > 600) s.grade = 600;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int agee, gra;
		scanf("%d%d", &agee, &gra);
		a[i].name = s;
		a[i].age = agee;
		a[i].grade = gra;
		pei(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i].name << " " << a[i].age << " " << a[i].grade << endl;
	}
	return 0;
}
