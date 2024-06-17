#include <stdio.h>

// 辅助递归函数，用于计算从当前索引开始的最长递增子序列的长度
int findlargest(int a[], int n, int prevIndex) {
    if (n == 0) {
        return 0;
    }

    int exclude = findlargest(a, n - 1, prevIndex);

    int include = 0;
    if (prevIndex == -1 || a[n - 1] > a[prevIndex]) {
        include = 1 + findlargest(a, n - 1, n - 1);
    }

    int result = (include > exclude) ? include : exclude;
    printf("n: %d, prevIndex: %d, a[n-1]: %d, include: %d, exclude: %d, result: %d\n",
           n, prevIndex, a[n-1], include, exclude, result);
    return result;
}

// 主函数，用于找到最长递增子序列的长度
int findLIS(int a[], int n) {
    return findlargest(a, n, -1);
}

int main() {
    int a[] = {10, 10, 9, 8, 9, 2, 10};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Length of LIS is %d\n", findLIS(a, n));
    return 0;
}
