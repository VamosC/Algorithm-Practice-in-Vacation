/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        decltype(res) tmp;
        if (root == nullptr)
            return res;
        deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty())
        {
            vector<int> row;
            for (auto i = queue.size(); i > 0; i--)
            {
                auto p = queue.front();
                if (p->left)
                    queue.push_back(p->left);
                if (p->right)
                    queue.push_back(p->right);
                row.push_back(p->val);
                queue.pop_front();
            }
            tmp.push_back(move(row));
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
            res.push_back(move(tmp[i]));
        return res;
    }
};
