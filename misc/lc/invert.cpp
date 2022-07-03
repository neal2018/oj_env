#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode aux(0, root, nullptr);
        TreeNode* p = &aux;
        while (p) {
            if (p->left) {
                TreeNode* q = p->left;
                while (q->right && q->right != p) q = q->right;
                if (q->right == p) {
                    TreeNode* r = p;
                    while (r->left != q) {
                        r = r->left;
                        swap(r->left->left, r->left->right);
                    }
                    swap(r->left->left, r->left->right);
                    q->left = nullptr;
                    p = p->right;
                } else {
                    q->right = p;
                    p = p->left;
                }
            } else {
                p = p->right;
            }
        }
        return aux.left;
    }
};