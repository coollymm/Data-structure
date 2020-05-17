/*
 * Leetcode: 102. 二叉树的层序遍历
 * tag: BFS
 * language: CPP
 * data: 2020/5/13
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            vector <int> cur = {};
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(cur);
        }
        
        return ret;
    }
};