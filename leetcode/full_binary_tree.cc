/*
 * @Author: gengyou.lu 1770591868@qq.com
 * @Date: 2024-10-18 23:03:17
 * @FilePath: /leetcode/full_binary_tree.cc
 * @LastEditTime: 2024-11-01 16:50:01
 * @Description: 输入一个满二叉树层序遍历的结果数组，构建满二叉树，并使用层序遍历输出结果
 */
/*
输入
10
0 1 2 3 4 5 6 7 8 9
输出
0 1 2 3 4 5 6 7 8 9
*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildFullBT(vector<int>& inputs) {
    int n = inputs.size();
    if (n == 0) {
        return nullptr;
    }

    int i = 0;
    queue<TreeNode*> q;

    TreeNode* root = new TreeNode(inputs[i++]);        
    q.push(root);

    while (!q.empty() && i < n) {
        TreeNode* cur_node = q.front();        
        q.pop();

        if (i < n) {
            TreeNode* tmp = new TreeNode(inputs[i++]);
            cur_node->left = tmp;
            q.push(tmp); // 将新建结点加入队列
        }

        if (i < n) {
            TreeNode* tmp = new TreeNode(inputs[i++]);
            cur_node->right = tmp;
            q.push(tmp); // 将新建结点加入队列
        }
    }

    return root;
}

// 层序遍历
void layerIter(TreeNode* root, vector<int>& nums) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int layer_nodes = q.size();

        for (int i = 0; i < layer_nodes; ++i) {
            TreeNode* cur_node = q.front();
            q.pop();
            nums.push_back(cur_node->val);

            if (cur_node->left != nullptr) {
                q.push(cur_node->left);
            }
            
            if (cur_node->right != nullptr) {
                q.push(cur_node->right);
            }
        }
    }
}

void preIter(TreeNode* root, vector<int>& nums) {
    if (root == nullptr) {
        return;
    }
    
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* cur_node = stk.top();
        stk.pop();

        nums.push_back(cur_node->val);

        // 先加有节点
        if (cur_node->right) {
            stk.push(cur_node->right);
        }
        // 再加左节点
        if (cur_node->left) {
            stk.push(cur_node->left);
        }
    }
}

void preIterFull(const vector<int>& nums, int i, int n, vector<int>& res) {
    if (i >= n) {
        return;
    }
    //前序遍历完全二叉树
    res.push_back(nums[i]); // 中
    preIterFull(nums, 2 * i + 1, n, res); // 左
    preIterFull(nums, 2 * i + 2, n, res); // 右
}

int main() {
    int n;
    cin >> n;

    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }

    TreeNode* root = buildFullBT(inputs);

    cout << "层序遍历：" << endl;
    vector<int> layer_result;
    layerIter(root, layer_result);    
    for (auto& i : layer_result) {
        cout << i << " ";
    }
    cout << endl;

    cout << "前序遍历：" << endl;
    vector<int> pre_result;
    preIter(root, pre_result);    
    for (auto& i : pre_result) {
        cout << i << " ";
    }
    cout << endl;

    cout << "前序遍历2：" << endl;
    vector<int> res;    
    preIterFull(inputs, 0, inputs.size(), res);    
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
