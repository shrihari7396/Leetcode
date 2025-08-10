class Solution {
private:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n > 0) {
            if(n&1) cnt ++;
            n = n >> 1;
        }
        return cnt == 1;
    }

    string vecToS(vector<char>& ch) {
        string s = "";
        for(char& c : ch) {
            s += c;
        }
        return s;
    }

public:
    bool reorderedPowerOf2(int n) {
        vector<char> ch;
        string s = to_string(n);
        for(char& c : s) {
            ch.emplace_back(c);
        }

        sort(ch.begin(), ch.end());
        do {
            if(ch[0] == '0') continue;
            int num = stoi(vecToS(ch));
            if(isPowerOfTwo(num)) return true;
        } while(next_permutation(ch.begin(), ch.end()));
        return false;
    }
};