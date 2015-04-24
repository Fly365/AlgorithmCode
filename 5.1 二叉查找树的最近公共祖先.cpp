/*-------------------------------------
*   日期：2015-04-24
*   作者：SJF0115
*   题目: 最小公共祖先
*   博客：
------------------------------------*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
// 二叉查找树的LCA
TreeNode* LCA(TreeNode* root,TreeNode* u,TreeNode* v){
    if(root == nullptr || u == nullptr || v == nullptr){
        return nullptr;
    }//if
    // 最近公共祖先在左子树
    if(root->val > u->val && root->val > v->val){
        return LCA(root->left,u,v);
    }//if
    // 最近公共祖先在左子树
    if(root->val < u->val && root->val < v->val){
        return LCA(root->right,u,v);
    }//if
    // 最近公共祖先为根节点
    return root;
}

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(7);
    TreeNode* node5 = new TreeNode(9);

    root->left = node1;
    root->right = node4;
    node1->left = node3;
    node1->right = node2;
    node4->right = node5;

    TreeNode* node = LCA(root,node2,node1);
    cout<<node2->val<<"和"<<node1->val<<"最近公共祖先->"<<node->val<<endl;
    return 0;
}
