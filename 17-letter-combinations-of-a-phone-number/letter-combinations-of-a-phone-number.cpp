class Solution {
private:
    const vector<string> keys = {
        "", "", "abc", "def", "ghi", "jkl", 
        "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(int idx, const string& digits, string& curr, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int d = digits[idx] - '0';
        for (char c : keys[d]) {
            curr.push_back(c);            // choose
            dfs(idx + 1, digits, curr, ans);
            curr.pop_back();              // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;
        string curr;
        dfs(0, digits, curr, ans);
        return ans;
    }
};
