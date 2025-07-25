#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int preIndex = 0;

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp) {
    if (inStart > inEnd) return NULL;
    int val = preorder[preIndex++];
    TreeNode* root = new TreeNode(val);
    int index = mp[val];
    root->left = build(preorder, inorder, inStart, index - 1, mp);
    root->right = build(preorder, inorder, index + 1, inEnd, mp);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
    return build(preorder, inorder, 0, inorder.size() - 1, mp);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    cout << root->val;
}
    