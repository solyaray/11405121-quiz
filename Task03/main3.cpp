#include <iostream>
#include <vector>

int main() {
    int Z;
    std::cin >> Z;
    Z /= 2;
    std::vector<std::vector<int>> dp(Z+1, std::vector<int>(Z*9+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= Z; ++i) {
        for (int j = 0; j <= 9*Z; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (j >= k)
                    dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    int total = 0;
    for (int i = 0; i <= 9*Z; ++i)
        total += dp[Z][i] * dp[Z][i];
    std::cout << total << std::endl;
    return 0;
}
