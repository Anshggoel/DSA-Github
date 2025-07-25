#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int &diameter) {
    if (!root) return 0;
    int l = height(root->left, diameter);
    int r = height(root->right, diameter);
    diameter = max(diameter, l + r);
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    cout << diameterOfBinaryTree(root);
}
