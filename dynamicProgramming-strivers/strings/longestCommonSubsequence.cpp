#include <string>
#include <vector>

int lcs(int i, int j, const std::string& s, const std::string& t, std::vector<std::vector<int>>& dp) {
    if (s[i] == '\0' || t[j] == '\0') {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s[i] == t[j]) {
        dp[i][j] = 1 + lcs(i + 1, j + 1, s, t, dp);
    } else {
        dp[i][j] = std::max(lcs(i + 1, j, s, t, dp), lcs(i, j + 1, s, t, dp));
    }
    return dp[i][j];
}

int longestCommonSubsequence(std::string s, std::string t) {
    int m = s.size();
    int n = t.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
    return lcs(0, 0, s, t, dp);
}
