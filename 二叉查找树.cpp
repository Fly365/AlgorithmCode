/*********************************
*   日期：2015-01-02
*   作者：SJF0115
*   题目: 二叉查找树
*   博客：http://blog.csdn.net/sunnyyoona/article/details/40625277
**********************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 二叉查找树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL) {}
};
// 中序遍历输出二叉查找树
void InOrder(TreeNode* root){
    if(root == NULL){
        return;
    }//if
    InOrder(root->left);
    cout<<root->val<<endl;
    InOrder(root->right);
}
// 插入
void TreeInsert(TreeNode*& root,int val){
    // 创建新节点
    TreeNode* node = new TreeNode(val);
    // 空树
    if(root == NULL){
        root = node;
        return;
    }//if
    TreeNode *pre = NULL;
    TreeNode *p = root;
    // 寻找插入位置
    while(p){
        // 父节点
        pre = p;
        // 沿左子树方向下降
        if(val < p->val){
            p = p->left;
        }//if
        // 沿右子树方向下降
        else{
            p = p->right;
        }//else
    }//while
    // 父节点
    node->parent = pre;
    // 左子结点处插入
    if(val < pre->val){
        pre->left = node;
    }//if
    // 右子结点处插入
    else{
        pre->right = node;
    }//else
}
// 创建二叉查找树
TreeNode* TreeCreate(vector<int> num){
    TreeNode *root = NULL;
    int len = num.size();
    if(len == 0){
        return root;
    }//if
    for(int i = 0;i < len;i++){
        TreeInsert(root,num[i]);
    }//for
    return root;
}
// 查找
TreeNode* TreeSearch(TreeNode* root,int val){
    if(root == NULL || root->val == val){
        return root;
    }//if
    // 左子树查找
    if(val < root->val){
        return TreeSearch(root->left,val);
    }//if
    // 右子树查找
    else{
        return TreeSearch(root->right,val);
    }//else
}
// 非递归查找
TreeNode* TreeSearch2(TreeNode* root,int val){
    if(root == NULL || root->val == val){
        return root;
    }//if
    TreeNode *p = root;
    while(p && val != p->val){
        // 左子树查找
        if(val < p->val){
            p = p->left;
        }//if
        // 右子树查找
        else{
            p = p->right;
        }//else
    }//while
    return p;
}
// 最小元素
TreeNode* TreeMinNum(TreeNode *root){
    TreeNode *p = root;
    while(p->left){
        p = p->left;
    }//while
    return p;
}
// 最大元素
TreeNode* TreeMaxNum(TreeNode *root){
    TreeNode *p = root;
    while(p->right){
        p = p->right;
    }//while
    return p;
}

// 后继
TreeNode* TreeSuccessor(TreeNode* node){
    // 右子树不为空,后继为右子树中的最左节点
    if(node->right){
        return TreeMinNum(node->right);
    }//if
    // 右子树为空,后继为最低祖先节点
    TreeNode *pre = node->parent;
    TreeNode *cur = node;
    // 最低祖先节点
    while(pre != NULL && cur == pre->right){
        cur = pre;
        pre = pre->parent;
    }//while
    return pre;
}
// 删除(返回被删除的节点)
TreeNode* TreeDelete(TreeNode *root,TreeNode *node){
    TreeNode *deleteNode = NULL;
    // 1.找到删除节点
    // 至多有一个子女则删除node节点
    if(node->left == NULL || node->right == NULL){
        deleteNode = node;
    }//if
    // 有两个子女则删除node节点的后继节点
    else{
        deleteNode = TreeSuccessor(node);
    }//esle
    //2.删除节点的子女(至多有一个子女)
    TreeNode *childNode = NULL;
    if(deleteNode->left){
        childNode = deleteNode->left;
    }//if
    else{
        childNode = deleteNode->right;
    }//else
    // 3.删除
    if(childNode){
        // 修改删除节点子女的父节点指针
        childNode->parent = deleteNode->parent;
    }//if
    // 删除节点为根节点
    if(deleteNode->parent == NULL){
        root = childNode;
    }//if
    else{
        TreeNode *parent = deleteNode->parent;
        // 删除节点是父节点的左子结点
        if(parent->left == deleteNode){
            parent->left = childNode;
        }//if
        // 删除节点是父节点的右子结点
        else{
            parent->right = childNode;
        }//else
    }//else
    // 4.如果删除的是后继节点,将deleteNode内容复制给node
    if(deleteNode->val != node->val){
        int tmp = deleteNode->val;
        deleteNode->val = node->val;
        node->val = tmp;
    }//if
    return deleteNode;
}

int main() {
    vector<int> num = {15,5,3,12,10,13,6,7,16,20,18,23};
    TreeNode *root = TreeCreate(num);
    //InOrder(root);
    TreeNode *node = TreeSearch2(root,5);
    /*TreeNode *node = TreeMinNum(root);
    cout<<node->val<<endl;
    TreeNode *node2 = TreeMaxNum(root);
    cout<<node2->val<<endl;
    TreeNode *node3 = TreeSuccessor(node);
    if(node3 == NULL){
        cout<<"NULL"<<endl;
    }
    else{
        cout<<node3->val<<endl;
    }*/
    TreeNode *node2 = TreeDelete(root,node);
    cout<<"Node->"<<node2->val<<endl;
    InOrder(root);
}

