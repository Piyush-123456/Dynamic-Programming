class Solution
{
public:
    // SOLVE USING RECURSION TECHNIQUE
    int solveusingRecursion(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int recursionans = 0;
            if (amount - coins[i] >= 0)
            {
                recursionans = solveusingRecursion(coins, amount - coins[i]);
                if (recursionans != INT_MAX)
                {
                    int ans = 1 + recursionans;
                    mini = min(ans, mini);
                }
            }
        }
        return mini;
    }
    // SOLVE USING MEMOIZATION
    int solveusingMemoization(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (dp[amount] != -1)
        {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int recursionans = 0;
            if (amount - coins[i] >= 0)
            {
                recursionans =
                    solveusingMemoization(coins, amount - coins[i], dp);
                if (recursionans != INT_MAX)
                {
                    int ans = 1 + recursionans;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    // SOLVE USING TABULATION METHOD
    int solveusingTabulationMethod(vector<int> &coins, int amount)
    {
        int n = amount;
        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        for (int value = 1; value <= amount; value++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                int recursionans = 0;
                if (value - coins[i] >= 0)
                {
                    recursionans = dp[value - coins[i]];
                    if (recursionans != INT_MAX)
                    {
                        int ans = 1 + recursionans;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int ans = solveusingTabulationMethod(coins, amount);
        if (ans != INT_MAX)
        {
            return ans;
        }
        else
            return -1;
    }
};