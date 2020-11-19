//https://www.luogu.com.cn/problem/P1162

#include <iostream>
#include <queue>
using namespace std;

inline int** init(int row) {
    int** target;
    target = new int*[row];
    for (int i = 0; i < row; i++)
        target[i] = new int[row];
    return target;
}

inline void input(int**& target, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            int num;
            cin >> num;
            target[i][j] = num;
        }
    }
}

inline void show(int** target, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++)
            cout << target[i][j] << ' ';
        cout << '\n';
    }
}

void getOne(int** target, int row, int& x, int& y) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (target[i][j] == 1) {
                x = i + 1;
                y = j + 1;
                return;
            }
        }
    }
}

//dfs
// void function(int**& target, int x, int y) {
//     if(target[x][y] == 1)
//         return;
//     if(target[x][y] == 2)
//         return;
//     target[x][y] = 2;
//     function(target, x + 1, y);
//     function(target, x, y + 1);
//     function(target, x, y - 1);
//     function(target, x - 1, y);
//     return;
// }

//bfs
typedef struct point {
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
} point;
void function(int**& target, int x, int y) {
    queue<point*> buf;
    buf.push(new point(x, y));
    target[x][y] = 2;
    do {
        point* now = buf.front();
        buf.pop();
        if (target[now->x + 1][now->y] == 0){
            buf.push(new point(now->x + 1, now->y));
            target[now->x + 1][now->y] = 2;
        }
        if (target[now->x - 1][now->y] == 0){
            buf.push(new point(now->x - 1, now->y));
            target[now->x - 1][now->y] = 2;

        }
        if(target[now->x][now->y + 1] == 0){
            buf.push(new point(now->x, now->y + 1));
            target[now->x][now->y + 1] = 2;
        }
        if(target[now->x][now->y - 1] == 0){
            buf.push(new point(now->x, now->y - 1));
            target[now->x][now->y - 1] = 2;
        }
        delete (now);
    } while (buf.size() != 0);
}

int main() {
    int row;
    cin >> row;
    int** target = init(row);
    input(target, row);
    int x, y;
    getOne(target, row, x, y);
    function(target, x, y);
    show(target, row);
    return 0;
}
