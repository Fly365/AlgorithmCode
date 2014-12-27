/*********************************
*   日期：2014-12-27
*   作者：SJF0115
*   题目: 98.Validate Binary Search Tree
*   来源：https://oj.leetcode.com/problems/validate-binary-search-tree/
*   结果：AC
*   来源：LeetCode
*   总结：
**********************************/
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
            return true;
        }//if
        return isValidBST(root,INT_MIN,INT_MAX,false,false);
    }
private:
    bool isValidBST(TreeNode* node,long min,long max,bool validMin,bool validMax){
        if(node == NULL){
            return true;
        }
        // min max第一次不要使用
        // 根节点大于左子树所有节点 小于右子树所有节点
        if((validMax && node->val >= max) || (validMin && node->val <= min)){
            return false;
        }
        // 左子树是否满足
        bool left = isValidBST(node->left,min,node->val,validMin,true);
        // 右子树是否满足
        bool right = isValidBST(node->right,node->val,max,true,validMax);
        return left && right;
    }//
};

//按先序序列创建二叉树
int CreateBTree(TreeNode*& T){
    int data;
    //按先序次序输入二叉树中结点的值,-1表示空树
    cin>>data;
    if(data == -1){
        T = NULL;
    }
    else{
        T = new TreeNode(data);
        //构造左子树
        CreateBTree(T->left);
        //构造右子树
        CreateBTree(T->right);
    }
    return 0;
}

int main() {
    Solution solution;
    TreeNode* root = NULL;
    CreateBTree(root);
    cout<<solution.isValidBST(root)<<endl;
}
