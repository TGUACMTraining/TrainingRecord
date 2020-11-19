//http://acm.hdu.edu.cn/showproblem.php?pid=1159

#include <iostream>
using namespace std;

int** createPartialSum(int row, int col) {
    int** ans = new int*[row];
    for (int i = 0; i < row; i++) {
        ans[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> ans[i][j];
            if (i - 1 >= 0 && j - 1 >= 0)
                ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            else if (j - 1 < 0 && i - 1 < 0)
                ;
            else if (i - 1 < 0)
                ans[i][j] += ans[i][j - 1];
            else if (j - 1 < 0)
                ans[i][j] += ans[i - 1][j];
        }
    }
    return ans;
}

int getPartialSum(int** array, int x1, int y1, int x2, int y2) {
    if (x1 - 1 >= 0 && y1 - 1 >= 0)
        return array[x2][y2] - array[x1 - 1][y2] - array[x2][y1 - 1] + array[x1 - 1][y1 - 1];
    else if (x1 - 1 >= 0 && y1 - 1 < 0)
        return array[x2][y2] - array[x1 - 1][y2];
    else if (x1 - 1 < 0 && y1 - 1 >= 0)
        return array[x2][y2] - array[x2][y1 - 1];
    else
        return array[x2][y2];
}

int getMaxPartialSum(int** array, int row, int col, int targetRow, int targetCol) {
    int max = getPartialSum(array, 0, 0, targetRow - 1, targetCol - 1);
    for (int i = 0; i <= row - targetRow; i++) {
        for (int j = 0; j <= col - targetCol; j++) {
            int num = getPartialSum(array, i, j, i + targetRow - 1, j + targetCol - 1);
            if (max < num)
                max = num;
        }
    }
    return max;
}


int main() {
    int cnt = 0;
    cin >> cnt;
    while (cnt--) {
        int row, col, targetRow, targetCol;
        cin >> row >> col >> targetRow >> targetCol;
        cout << getMaxPartialSum(createPartialSum(row, col), row, col, targetRow, targetCol) << '\n';
    }
    return 0;
}
