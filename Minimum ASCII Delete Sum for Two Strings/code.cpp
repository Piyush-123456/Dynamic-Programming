class Solution
{
public:
    int solve(string &s1, string &s2, int i, int j)
    {
        int cost = 0;
        if (i == s1.size() || j == s2.size())
        {
            for (int x = j; x < s2.size(); x++)
                cost += s2[x];
            for (int x = i; x < s1.size(); x++)
                cost += s1[x];
        }
        else if (s1[i] == s2[j])
        {
            cost = solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            int cost1 = s1[i] + solve(s1, s2, i + 1, j);
            int cost2 = s2[j] + solve(s1, s2, i, j + 1);
            cost = min(cost1, cost2);
        }
        return cost;
    }

    int solveusingMemo(string &s1, string &s2, int i, int j,
                       vector<vector<int>> &dp)
    {
        int cost = 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == s1.size() || j == s2.size())
        {
            for (int x = j; x < s2.size(); x++)
                cost += s2[x];
            for (int x = i; x < s1.size(); x++)
                cost += s1[x];
        }
        else if (s1[i] == s2[j])
        {
            cost = solveusingMemo(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            int cost1 = s1[i] + solveusingMemo(s1, s2, i + 1, j, dp);
            int cost2 = s2[j] + solveusingMemo(s1, s2, i, j + 1, dp);
            cost = min(cost1, cost2);
        }

        dp[i][j] = cost;
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solveusingMemo(s1, s2, 0, 0, dp);
    }
};