#include<bits/stdc++.h>
using namespace std;

bool isSafe(bool flag[][25], int x, int y, int m, int n) {
    if(x >= 0 && x < m && y >= 0 && y < n && !flag[x][y])
        return true;
    return false;
}

void resetFlag(bool flag[][25], int m, int n) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            flag[i][j] = false;
}

void travel(int board[][25], bool flag[][25], int x, int y, int b, int k, int *score, int m, int n) {
    if(isSafe(flag, x, y, m, n) && board[x][y] == board[b][k]) {
        flag[x][y] = true;
        *score += 1;
        travel(board, flag, x + 1, y, b, k, score, m, n);
        travel(board, flag, x, y + 1, b, k, score, m, n);
        travel(board, flag, x - 1, y, b, k, score, m, n);
        travel(board, flag, x, y - 1, b, k, score, m, n);
    }
}

void erase_balls(int board[][25], bool flag[][25], int x, int y, int target_ball, int m, int n) {
    if(isSafe(flag, x, y, m, n) && board[x][y] == target_ball) {
        flag[x][y] = true;
        board[x][y] = 0;
        erase_balls(board, flag, x + 1, y, target_ball, m, n);
        erase_balls(board, flag, x, y + 1, target_ball, m, n);
        erase_balls(board, flag, x - 1, y, target_ball, m, n);
        erase_balls(board, flag, x, y - 1, target_ball, m, n);
    }
}

void collapse_balls(int board[][25], int m, int n) {
    for(int i = m - 2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            int k = i;
            while(k + 1 <= m - 1 && board[k + 1][j] == 0) {
                board[k + 1][j] = board[k][j];
                board[k][j] = 0;
                k++;
            }
        }
    }
}

void rearrange_board(int board[][25], bool flag[][25], int m, int n) {
    int x_max = 0, y_max = 0, max_score = 0, curr_score = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(isSafe(flag, i, j, m, n)) {
                travel(board, flag, i, j, i, j, &curr_score, m, n);
                if(curr_score > max_score) {
                    max_score = curr_score;
                    x_max = i;
                    y_max = j;
                }
                curr_score = 0;
            }
        }
    }

    resetFlag(flag, m, n);

    erase_balls(board, flag, x_max, y_max, board[x_max][y_max], m, n);

    collapse_balls(board, m, n);
}

void printBoard(int board[][25], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] != 0)
                cout << board[i][j];
            else
                cout << ".";
            if(j < n - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, board[25][25];
    bool flag[25][25];

    cin >> m >> n;

    resetFlag(flag, m, n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    rearrange_board(board, flag, m, n);

    printBoard(board, m, n);
}
