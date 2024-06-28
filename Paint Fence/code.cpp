#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }
    int ans = (k - 1) * (solve(n - 2, k) + solve(n - 1, k));
    return ans;
}

// SOLVE USING MEMOIZATION
int solveusingMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (solveusingMemo(n - 1, k, dp) + solveusingMemo(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

// SOLVE USING TABULATION METHOD
int solveusingTabulation(int n, int k)
{
    // Step-1 - Create DP Array
    vector<int> dp(n + 1, -1);

    // Step-2 - Define the Base Case
    if (n == 0)
        dp[0] = 0;
    if (n == 1)
        dp[1] = k;
    if (n == 2)
        dp[2] = k + k * (k - 1);

    dp[0] = 0;
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    // Step-3 - Logic
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

// SOLVE USING SPACE OPTIMIZATION TECHNIQUE
int solveusingSpaceOpt(int n, int k)
{
    int prev = k;
    int next = k + k * (k - 1);
    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        ans = (prev + next) * (k - 1);
        prev = next;
        next = ans;
    }
    return ans;
}

int main()
{
    cout << solveusingSpaceOpt(3, 3);
    return 0;
}