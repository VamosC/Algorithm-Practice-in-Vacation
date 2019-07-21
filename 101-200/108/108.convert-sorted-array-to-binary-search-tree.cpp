/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return binaryInsert(0, nums.size() - 1, nums);
    }
    TreeNode *binaryInsert(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return nullptr;
        auto mid = (i + j) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = binaryInsert(i, mid - 1, nums);
        root->right = binaryInsert(mid + 1, j, nums);
        return root;
    }
};
