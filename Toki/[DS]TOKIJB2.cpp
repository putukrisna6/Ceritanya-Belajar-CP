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

int traverse_board(int board[][25], bool flag[][25], int m, int n) {
    int max_score = 0, curr_score = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(isSafe(flag, i, j, m, n)) {
                travel(board, flag, i, j, i, j, &curr_score, m, n);
                if(curr_score > max_score)
                    max_score = curr_score;
                curr_score = 0;
            }
        }
    }

    return max_score;
}

int main() {
    int m, n, score = 0, board[25][25];
    bool flag[25][25];

    cin >> m >> n;

    resetFlag(flag, m, n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    score = traverse_board(board, flag, m, n);

    score *= score - 1;

    cout << score << endl;
}
