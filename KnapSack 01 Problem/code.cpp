#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &wt, vector<int> &val, int cap, int index)
{
    if (index <= 0)
    {
        if (wt[0] <= cap)
        {
            return val[0];
        }
        return 0;
    }
    int takenot = 0 + solve(wt, val, cap, index - 1);
    int take = INT_MIN;
    if (wt[index] <= cap)
    {
        take = val[index] + solve(wt, val, cap - wt[index], index - 1);
    }
    return max(take, takenot);
}

// SOLVE USING MEMOIZATION
int solveusingMemo(vector<int> wt, vector<int> val, int cap, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[index] <= cap)
        {
            return val[index];
        }
        return 0;
    }
    if (dp[cap][index] != -1)
    {
        return dp[cap][index];
    }
    int takenot = 0 + solve(wt, val, cap, index - 1);
    int take = INT_MIN;
    if (wt[index] <= cap)
    {
        take = val[index] + solve(wt, val, cap - wt[index], index - 1);
    }
    dp[cap][index] = max(take, takenot);
    return dp[cap][index];
}

// SOLVE USING TABULATION METHOD
int solveusingTabulation(vector<int> wt, vector<int> val, int cap)
{
    // Step - 1 Make the dp array
    vector<vector<int>> dp(cap + 1, vector<int>(wt.size() + 1, -1));

    // Step - 2
    for (int i = 0; i <= cap; i++)
    {
        dp[i][wt.size()-1] = 0;
    }
    for (int i = 0; i <= cap; i++)
    {
        for (int j = wt.size() - 1; j >= 0; j--)
        {
            int takenot = dp[i][j + 1];
            int take = INT_MIN;
            if (wt[j] <= i)
            {
                take = val[j] + dp[i - wt[j]][j - 1];
            }
            dp[i][j] = max(take, takenot);
        }
    }
    return dp[cap][wt.size()-1];
}

int main()
{
    vector<int> wt = {4, 5, 1};
    vector<int> val = {1, 2, 3};
    int cap = 4;
    cout << solveusingTabulation(wt, val, cap);
    return 0;
}