class Solution {
public:
    int solve(vector<int> days, vector<int> costs, int i) {
        if (i >= days.size()) {
            return 0;
        }

        int cost1 = costs[0] + solve(days, costs, i + 1);

        int j = i;
        while (j < days.size() && days[j] <= days[i] + 7 - 1) {
            j++;
        }
        int cost7 = costs[1] + solve(days, costs, j);

        j = i;
        while (j < days.size() && days[j] <= days[i] + 30 - 1) {
            j++;
        }
        int cost30 = costs[2] + solve(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int solveusingMemo(vector<int> days, vector<int> costs, int i,
                       vector<int>& dp) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int cost1 = costs[0] + solveusingMemo(days, costs, i + 1, dp);

        int j = i;
        while (j < days.size() && days[j] <= days[i] + 7 - 1) {
            j++;
        }
        int cost7 = costs[1] + solveusingMemo(days, costs, j, dp);

        j = i;
        while (j < days.size() && days[j] <= days[i] + 30 - 1) {
            j++;
        }
        int cost30 = costs[2] + solveusingMemo(days, costs, j, dp);

        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int solveusingTabulation(vector<int> days, vector<int> costs, int i) {
        vector<int> dp(days.size() + 1, -1);
        dp[days.size()] = 0;

        for (int i = days.size() - 1; i >= 0; i--) {
            int cost1 = costs[0] + dp[i + 1];

            int j = i;
            while (j < days.size() && days[j] <= days[i] + 7 - 1) {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            j = i;
            while (j < days.size() && days[j] <= days[i] + 30 - 1) {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return solveusingTabulation(days, costs, 0);
    }
};