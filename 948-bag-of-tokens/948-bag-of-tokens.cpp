class Solution {
public:
    // int dp[1002];
    int bagOfTokensScore(vector<int>& tokens, int p) {
        sort(tokens.begin(), tokens.end());
        int ans = 0, points = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (p >= tokens[i]) {
                p -= tokens[i++];
                ans = max(ans, ++points);
            } else if (points > 0) {
                points--;
                p += tokens[j--];
            } else {
                break;
            }
        }
        return ans;
    }
};