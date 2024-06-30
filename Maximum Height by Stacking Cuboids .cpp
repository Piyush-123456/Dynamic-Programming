class Solution {
public:
    bool check(vector<int> curr, vector<int> prev) {
        if (curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]) {
            return true;
        } else {
            return false;
        }
    }
    int solveusingSO(vector<vector<int>>& cuboids) {
        vector<int> curr_row(cuboids.size() + 1, 0);
        vector<int> next_row(cuboids.size() + 1, 0);
        for (int curr = cuboids.size() - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || check(cuboids[curr] ,cuboids[prev])) {
                    int height = cuboids[curr][2];
                    include = height + next_row[curr + 1];
                }
                int exclude = next_row[prev + 1];
                curr_row[prev + 1] = max(include, exclude);
            }
            next_row = curr_row;
        }
        return next_row[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solveusingSO(cuboids);
    }
};
