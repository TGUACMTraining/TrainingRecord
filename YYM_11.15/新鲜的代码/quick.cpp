#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
	int questions;
	scanf("%d", &questions);
	while (questions--) {
		int q;
		char way[5];
		scanf("%d", &q);
		scanf(" %s", way);
		if ('F' == way[2]) {
			queue<int> que;
			while (q--) {
				char cache[4];
				scanf("%s", cache);
				if ('I' == cache[0]) {
					int t;
					scanf("%d", &t);
					que.push(t);
				} else {
					if (que.size() == 0) {
						printf("None\n");
						continue;
					}
					printf("%d\n", que.front());
					que.pop();
				}
			}
		} else {
			stack<int> s;
			while (q--) {
				char cache[4];
				scanf("%s", cache);
				if ('I' == cache[0]) {
					int t;
					scanf("%d", &t);
					s.push(t);
				} else {
					if (s.size() == 0) {
						printf("None\n");
						continue;
					}
					printf("%d\n", s.top());
					s.pop();
				}
			}
		}
	}
	return 0;
}