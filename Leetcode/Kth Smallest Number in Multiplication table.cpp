
class Solution {
public:
    int can(int rows, int cols, int value) {
        int cnt = 0;
        for (int i = 1; i <= rows; i++) {
            cnt += min(value / i, cols);
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        int start = 1, end = m * n, kth = -1;
        while (start <= end) {
            int value = start + (end - start) / 2;
            if (can(m, n, value) < k) {
                start = value + 1;
            } else {
                kth = value;
                end = value - 1;
            }
        }
        return kth;
    }
};
