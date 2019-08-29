/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
auto speed = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = make_shared<Node>();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto node = root;
        for (auto c : word)
        {
            if (node->nodes.count(c) == 0)
            {
                node->nodes[c] = make_shared<Node>();
            }
            node = node->nodes[c];
        }
        node->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto node = root;
        for (auto c : word)
        {
            if (node->nodes.count(c) == 0)
            {
                return false;
            }
            node = node->nodes[c];
        }
        return node->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto node = root;
        for (auto c : prefix)
        {
            if (node->nodes.count(c) == 0)
            {
                return false;
            }
            node = node->nodes[c];
        }
        return true;
    }

private:
    class Node
    {
    public:
        unordered_map<char, shared_ptr<Node>> nodes;
        bool is_word;
        Node() : is_word(false) {}
    };
    shared_ptr<Node> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
