#include <stdio.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int longest_path(int x, int y, int M[x][y]) {
    // We are given the matrix M[0...x-1][0...y-1]
    int dp[x][y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            // 初始化 dp[i][j]
            dp[i][j] = 1;
            
            // 检查上方元素
            if (i > 0 && M[i-1][j] < M[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);
            }
            
            // 检查左侧元素
            if (j > 0 && M[i][j-1] < M[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i][j-1]);
            }
        }
    }

    int final_answer = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            final_answer = max(final_answer, dp[i][j]);
        }
    }

    return final_answer;
}

int main() {
    int M[4][6] = {
        {1, 7, 3, 10, 6, 18},
        {3, 2, 5, 6, 9, 16},
        {6, 3, 2, 10, 12, 13},
        {8, 7, 5, 4, 8, 15}
    };
    printf("%d\n", longest_path(4, 6, M));
    return 0;
}
