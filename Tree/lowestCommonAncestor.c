/*
 * Leetcode: 236. 二叉树的最近公共祖先
 * tag: DFS
 * language: C
 * data: 2020/5/10
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *ret;

bool dfs(struct TreeNode* node, struct TreeNode* p, struct TreeNode* q) {
    if (node == NULL) {
        return false;
    }
    // left & right reprents node p and q are the children of the node or equals to one of them
    bool left = dfs(node->left, p, q);
    bool right = dfs(node->right, p, q);
    if ((left && right) || ((node == p || node == q) && (left || right))) {
        ret = node;
    }
    return left || right || node == p || node == q;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (p == root || q == root) {
        return root;
    }
    ret = root;
    dfs(root, p, q);
    return ret;
}

//Using hash table to save parent node
//First start from node p, search its parent and set visited until the root
//Then search the parent of node q until the visited node