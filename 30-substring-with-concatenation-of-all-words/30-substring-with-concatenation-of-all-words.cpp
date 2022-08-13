class TrieNode {
    public:
    int endWord;
    TrieNode* child[26];
    TrieNode(){
        endWord = 0;
        for(int i=0;i<26;i++) child[i] = NULL;
    }
};
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insertWord(string& word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(node->child[word[i]-'a'] == NULL) node->child[word[i]-'a'] = new TrieNode();
            node = node->child[word[i]-'a'];
        }
        node->endWord++;
    }
    
    bool searchWord(string& word, int times){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(node->child[word[i]-'a'] == NULL) return false;
            node = node->child[word[i]-'a'];
        }
        return node->endWord > times; 
    }
};
class Solution {
public:
    Trie* trie = new Trie();
    bool check(string& sen,int k,int totalWord){
        unordered_map<string,int> mp;
        int countWord = 0;
        for(int i=0;i<sen.size();i+=k){
            string temp = sen.substr(i,k);
            if(trie->searchWord(temp, mp[temp])){
                mp[temp]++;
                countWord++;
            }else return false;
        }
        return totalWord == countWord;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n = s.size(), m = words.size();
        for(int i=0;i<m;i++){
            trie->insertWord(words[i]);
        }
        
        int len = words[0].size()*m;
        vector<int> res;
        for(int i=0;i+len<=n;i++){
            string temp = s.substr(i,len);
            if(check(temp,words[0].size(),m)) res.push_back(i);
        }
        
        return res;
    }
};