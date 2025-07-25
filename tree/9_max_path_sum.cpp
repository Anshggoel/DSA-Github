#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int maxSum(TreeNode* root, int &res) {
    if (!root) return 0;
    int l = max(0, maxSum(root->left, res));
    int r = max(0, maxSum(root->right, res));
    res = max(res, l + r + root->val);
    return root->val + max(l, r);
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    maxSum(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxPathSum(root);
}
