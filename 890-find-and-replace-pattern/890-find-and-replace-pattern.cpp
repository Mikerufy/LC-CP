class Solution {
private:
    bool match(string &word, string &pattern) {
        map<char, char> x;
        map<char, char> y;

        for (int i = 0; i < word.size(); i++) {
            if (x.find(word[i]) == x.end())    x[word[i]] = pattern[i];
            if (y.find(pattern[i]) == y.end())    y[pattern[i]] = word[i];
            if (x[word[i]] != pattern[i] || y[pattern[i]] != word[i])  return false;
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string word : words)
            if (match(word, pattern))
                ans.push_back(word);

        return ans;
    }
};