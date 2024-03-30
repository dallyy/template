class Trie 

{

public:

    unordered_map<char, Trie *> child;

    bool isword;



    /** Initialize your data structure here. */

    Trie() 

    {

        isword = false;

    }

    

    /** Inserts a word into the trie. */

    void insert(string word) 

    {

        Trie * rt = this;       /////////从根开始，相当于python3中的self

        for (char w: word)

        {

            if (rt->child.count(w) == 0)    //path断了

                rt->child[w] = new Trie();  //新建

            rt = rt->child[w];

        }

        rt->isword = true; 

    }

    

    /** Returns if the word is in the trie. */

    bool search(string word) 

    {

        Trie * rt = this;

        for (char w: word)

        {

            if (rt->child.count(w) == 0)

                return false;

            rt = rt->child[w];

        }

        return rt->isword == true;

    }

    

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startsWith(string prefix) 

    {

        Trie * rt = this;

        for (char p: prefix)

        {

            if (rt->child.count(p) == 0)

                return false;

            rt = rt->child[p];

        }

        return true;

    }

};



/**

 * Your Trie object will be instantiated and called as such:

 * Trie* obj = new Trie();

 * obj->insert(word);

 * bool param_2 = obj->search(word);

 * bool param_3 = obj->startsWith(prefix);

 */

//https://leetcode.cn/problems/count-prefix-and-suffix-pairs-ii/description/?envType=list&envId=188q2gjJ
class TrieNode {
public:
    unordered_map<string, TrieNode*> nxt;
    size_t cnt;

    TrieNode() : cnt(0) {}
};

class Solution {
private:
    TrieNode* root;

public:
    Solution() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {        
        TrieNode* p = root;
        p->cnt++;
        for (int j = 0; j < word.size(); j++) {
            string ch = {word[j], word[word.size() - j - 1]};
            if (p->nxt.count(ch) == 0) {
                p->nxt[ch] = new TrieNode();
            }
            p = p->nxt[ch];
            p->cnt++;
        }
    }
    
    size_t query(const string& word) const {
        TrieNode* p = root;
        for (int j = 0; j < word.size(); j++) {
            string ch = {word[j], word[word.size() - j - 1]};
            if (p->nxt.count(ch) == 0) {
                return 0;
            }
            p = p->nxt[ch];
        }
        return p->cnt;
    }

    size_t countPrefixSuffixPairs(const vector<string>& words) {
        size_t ans = 0;
        for (int j = words.size() - 1; j >= 0; j--) {
            ans += query(words[j]);
            insert(words[j]);
        }
        return ans;
    }
};
//https://leetcode.cn/problems/longest-common-suffix-queries/
class Trie {
private:
    unordered_map<char, Trie*> sons;
    int val;

public:
    Trie() {
        val = 1000000000;
    }

    void insert(const string& word, int value) {
        Trie* tmp = this;
        for (char c : word) {
            if (value < tmp->val) {
                tmp->val = value;
            }
            if (tmp->sons.find(c) == tmp->sons.end()) {
                tmp->sons[c] = new Trie();
            }
            tmp = tmp->sons[c];
        }
        if (value < tmp->val) {
            tmp->val = value;
        }
    }

    int search(const string& word) {
        Trie* tmp = this;
        for (char c : word) {
            if (tmp->sons.find(c) != tmp->sons.end()) {
                tmp = tmp->sons[c];
            } else {
                break;
            }
        }
        return tmp->val % 100000;
    }
};

class Solution {
public:
    vector<int> stringIndices(const vector<string>& wordsContainer, const vector<string>& wordsQuery) {
        Trie* t = new Trie();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            string reversedWord = wordsContainer[i];
            reverse(reversedWord.begin(), reversedWord.end());
            t->insert(reversedWord, reversedWord.size() * 100000 + i);
        }
        vector<int> indices;
        for (const string& word : wordsQuery) {
            string reversedQuery = word;
            reverse(reversedQuery.begin(), reversedQuery.end());
            indices.push_back(t->search(reversedQuery));
        }
        return indices;
    }
};
