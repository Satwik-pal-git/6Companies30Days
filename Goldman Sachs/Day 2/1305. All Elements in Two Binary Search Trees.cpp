#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root1)
        {
            q.push(root1);
        }
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            ans.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        if (root2)
            q.push(root2);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            ans.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};