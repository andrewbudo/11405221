#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    N /= 2;
    std::vector<std::vector<int>> dp(N+1, std::vector<int>(N*9+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= 9*N; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (j >= k)
                    dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    int total = 0;
    for (int i = 0; i <= 9*N; ++i)
        total += dp[N][i] * dp[N][i];
    std::cout << total << std::endl;
    return 0;
}
