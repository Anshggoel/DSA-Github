#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t || s->val != t->val) return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (isSame(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);
    
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);
    
    cout << isSubtree(s, t);
}
