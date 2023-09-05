/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0xF0000000;
    int oneSideMaxSum(TreeNode *root){
        if (root == nullptr) return 0;
        int left = max(0, oneSideMaxSum(root->left));
        int right = max(0, oneSideMaxSum(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        oneSideMaxSum(root);
        return res;
    }
};