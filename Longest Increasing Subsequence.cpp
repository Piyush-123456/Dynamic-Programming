class Solution {
public:
    int solve(vector<int>& nums, int prev, int curr) {
        if (curr >= nums.size()) {
            return 0;
        }
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solve(nums, curr, curr + 1);
        }
        int exclude = solve(nums, prev, curr + 1);
        return max(include, exclude);
    }

    int solveusingMemo(vector<int>& nums, int prev, int curr,
                       vector<vector<int>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveusingMemo(nums, curr, curr + 1, dp);
        }
        int exclude = solveusingMemo(nums, prev, curr + 1, dp);
        dp[prev + 1][curr] = max(include, exclude);
        return dp[prev + 1][curr];
    }

    // SOLVE USING TABULATION METHOD
    int solveusingTabulation(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));
        for (int curr = nums.size() - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = dp[prev + 1][curr + 1];
                dp[prev + 1][curr] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // SOLVE USING SPACE OPTIMIZATION METHOD
    int solveusingSO(vector<int>& nums) {
        vector<int> curr_row(nums.size() + 1, 0);
        vector<int> next_row(nums.size() + 1, 0);
        for (int curr = nums.size() - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + next_row[curr + 1];
                }
                int exclude = next_row[prev + 1];
                curr_row[prev + 1] = max(include, exclude);
            }
            next_row = curr_row;
        }
        return next_row[0];
    }

    // SOLVE USING BINARY SEARCH
    int solveusingBinarySearchMethod(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int index =
                    lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, -1));
        int ans = solveusingBinarySearchMethod(nums);
        return ans;
    }
};
