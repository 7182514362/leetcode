#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "util.h"
using namespace std;

// my ans bfs
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode *> treeNodeStk1;
        stack<TreeNode *> treeNodeStk2;
        treeNodeStk1.push(root);
        int i = 0;
        while (!treeNodeStk1.empty() || !treeNodeStk2.empty()) {
            vector<int> vals;
            if (i % 2 == 0) {
                while (!treeNodeStk1.empty()) {
                    TreeNode *node = treeNodeStk1.top();
                    treeNodeStk1.pop();
                    vals.push_back(node->val);
                    if (node->left) treeNodeStk2.push(node->left);
                    if (node->right) treeNodeStk2.push(node->right);
                }
            } else {
                while (!treeNodeStk2.empty()) {
                    TreeNode *node = treeNodeStk2.top();
                    treeNodeStk2.pop();
                    vals.push_back(node->val);
                    if (node->right) treeNodeStk1.push(node->right);
                    if (node->left) treeNodeStk1.push(node->left);
                }
            }
            ans.emplace_back(vals);
            ++i;
        }
        return ans;
    }
};

// 官方-BFS
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

int main() {
    vector<int> treeNodeValues = {3, 9, 20, -1, 10, 15, 7, -1, -1, 9, 4};
    Tree tree(treeNodeValues);
    BFS(tree.root);
    Solution sol;
    printMatrix(sol.zigzagLevelOrder(tree.root));
    return 0;
}