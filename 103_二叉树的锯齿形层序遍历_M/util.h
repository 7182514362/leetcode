#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Tree {
    TreeNode *root;
    Tree(vector<int> &treeValues) {
        root = new TreeNode(treeValues[0]);
        createTree(root, treeValues, 0);
    }

    void createTree(TreeNode *root, vector<int> &treeValues, int idx) {
        int l = 2 * (idx + 1) - 1;
        int r = 2 * (idx + 1);
        if (l < treeValues.size() && treeValues[l] >= 0) {
            TreeNode *node = new TreeNode(treeValues[l]);
            root->left = node;
            createTree(root->left, treeValues, l);
        }
        if (r < treeValues.size() && treeValues[r] >= 0) {
            TreeNode *node = new TreeNode(treeValues[r]);
            root->right = node;
            createTree(root->right, treeValues, r);
        }
    }
};

void BFS(TreeNode *root) {
    queue<TreeNode *> treeNodeQ;
    vector<int> values;
    treeNodeQ.push(root);
    while (!treeNodeQ.empty()) {
        TreeNode *node = treeNodeQ.front();
        treeNodeQ.pop();
        values.push_back(node->val);
        if (node->left) treeNodeQ.push(node->left);
        if (node->right) treeNodeQ.push(node->right);
    }

    cout << "[ ";
    for (int i : values) {
        cout << i << ' ';
    }
    cout << "]" << endl;
}

void printMatrix(vector<vector<int>> &&mtx) {
    for (auto &v : mtx) {
        cout << "[ ";
        for (int i : v) {
            cout << i << ' ';
        }
        cout << "]" << endl;
    }
}
