class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.second;
            string currString = it.first;
            if(currString == endWord) return steps;
            for(int i  = 0; i < currString.size(); i++) {
                string orinalWord = currString;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    currString[i] = ch;
                    if(st.find(currString)!=st.end()) {
                        st.erase(currString);
                        q.push({currString, steps+1});
                    }
                    currString = orinalWord;
                }
            }
        }
        return 0;
    }
};
