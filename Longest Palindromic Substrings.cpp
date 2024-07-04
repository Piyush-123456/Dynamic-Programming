class Solution {
public:
    int maxi = 1, start = 0;
    bool solve(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        bool flag = false;
        if (s[i] == s[j]) {
            flag = solve(s, i + 1, j - 1);
        }
        if (flag) {
            int currlen = j - i + 1;
            if (currlen > maxi) {
                maxi = currlen;
                start = i;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool ans = solve(s, i, j);
            }
        }
        return s.substr(start, maxi);
    }
};
