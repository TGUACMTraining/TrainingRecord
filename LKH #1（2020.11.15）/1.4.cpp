//https://www.luogu.com.cn/problem/P1605
#include <iostream>
#include <vector>
using namespace std;
class Maze {
   private:
    int row = 0, col = 0;
    int enterX = 0;
    int enterY = 0;
    int allRoadNum = 0;
    int** mazeMap;
    int** visited;

   public:
    Maze(const int r, const int c) : row(r), col(c) {
        init(mazeMap, r, c);
        init(visited, r, c);
    }

    int getAllRoad() {
        getRoad(--enterX, --enterY);
        return allRoadNum;
    }

   private:
    void init(int**& BinaryArray, int r, int c) {
        BinaryArray = new int*[r];
        for (int i = 0; i < r; i++) {
            BinaryArray[i] = new int[c];
            for (int j = 0; j < c; j++)
                BinaryArray[i][j] = 0;
        }
    }

    void getRoad(int x, int y) {
        if (x < 0 || y < 0 || x >= row || y >= col)
            return;
        if (visited[x][y] == 1)
            return;
        if (mazeMap[x][y] == 1)
            return;
        if (mazeMap[x][y] == 3) {
            allRoadNum++;
            return;
        }
        visited[x][y] = 1;
        getRoad(x - 1, y);
        getRoad(x, y - 1);
        getRoad(x + 1, y);
        getRoad(x, y + 1);
        visited[x][y] = 0;
    }

   public:
    void setEnter(int x, int y) {
        enterX = x;
        enterY = y;
        mazeMap[--x][--y] = 2;
    }

    void setOut(int x, int y) {
        mazeMap[--x][--y] = 3;
    }

    void setWall(int** point, int total) {
        for (int i = 0; i < total; i++) {
            mazeMap[--point[i][0]][--point[i][1]] = 1;
        }
    }

    void show() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << mazeMap[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

int** inputPoint(int total) {
    int** point;
    point = new int*[total];
    for (int j = 0; total > j; j++) {
        point[j] = new int[2];
        int x, y;
        cin >> x >> y;
        point[j][0] = x;
        point[j][1] = y;
    }
    return point;
}

void inputEO(Maze& maze) {
    int x, y;
    cin >> x >> y;
    maze.setEnter(x, y);
    cin >> x >> y;
    maze.setOut(x, y);
}

int main() {
    int row;
    int col;
    int total;
    cin >> row >> col >> total;

    Maze maze(row, col);
    inputEO(maze);
    maze.setWall(inputPoint(total), total);
    // maze.show();
    cout << maze.getAllRoad();

    return 0;
}
