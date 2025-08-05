class Solution {

public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> hash1(26, 0), hash2(26, 0);
        for(int i = 0; i < m; i++) {
            hash1[s1[i] - 'a']++;
        }

        for(int i = 0; i < n; i++) {
            hash2[s2[i] - 'a'] ++;

            if(i >= m) {
                hash2[s2[i-m] - 'a'] --;
            }

            if(hash1 == hash2) return true;
        }
        return false;
    }
};