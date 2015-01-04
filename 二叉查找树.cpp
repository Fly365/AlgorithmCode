/*********************************
*   日期：2015-01-02
*   作者：SJF0115
*   题目: 二叉查找树
*   博客：http://blog.csdn.net/sunnyyoona/article/details/40625277
**********************************/
/*
二叉查找树的性质：
设x为二叉查找树上的一个节点。
如果y是x的左子树中的一个节点，则y->val 小于等于 x->val。
如果y是x的右子树中的一个节点，则y->val 大于等于 x->val。
*/
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

/*
输出：
根据二叉查找树的性质，我们可以用中序递归遍历算法按排列顺序输出树中的所有关键字。
*/

// 中序遍历输出二叉查找树
void InOrder(TreeNode* root){
    if(root == NULL){
        return;
    }//if
    InOrder(root->left);
    cout<<root->val<<endl;
    InOrder(root->right);
}

/*
插入：
TreeInsert从根节点开始，并沿树下降。
指针p跟踪了这条路径，而pre始终指向p的父节点。初始化后while循环是这两个指针沿树下降，根据val和p->val的比较结果，可以决定向左还是向右转。
直到p成为NULL为止。这个NULL所占的位置就是我们像插入的位置。
其特点是：树的结构通常不是一次生成的，而是在查找过程中，当树中不存在关键字等于给定值的节点时再进行插入。
新插入的结点一定是一个新添加的叶子节点，并且是查找不成功时查找路径上访问的最后一个结点的左孩子或右孩子结点。
*/

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

/*
递归查找：
如果root是一棵空树，搜索失败，直接返回NULL。
如果root不是空树：
对碰到的每一个节点p，都要进行比较val和p->val，如果两个关键字相同，则查找结束。
如果val小于p->val，则继续查找p的左子树，如果val大于等于p->val，则继续查找p的右子树。
*/

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

/*
要查找二叉树中具有最大关键字的元素，只要从根节点开始，沿着各节点的right指针查找下去，直到遇到NULL为止。
*/

// 最小元素
TreeNode* TreeMinNum(TreeNode *root){
    TreeNode *p = root;
    while(p->left){
        p = p->left;
    }//while
    return p;
}

/*
要查找二叉树中具有最小关键字的元素，只要从根节点开始，沿着各节点的left指针查找下去，直到遇到NULL为止。
*/

// 最大元素
TreeNode* TreeMaxNum(TreeNode *root){
    TreeNode *p = root;
    while(p->right){
        p = p->right;
    }//while
    return p;
}

/*
给你一个二叉查找树中的节点，让你求出在中序遍历顺序下它的后继。如果所有的关键词都不同，则某一节点x的后继
即具有大于x->val中的关键字中的最小的那个节点。
根据二叉查找树的性质得知，不用任何的比较，就可以找到某个节点的后继。对于二叉查找树的某个节点x，下面的代码返回其后继（如果存在的话）
，或者返回NULL（如果x具有树中最大关键字的某个节点）

求某个节点的后继，需要考虑两种情况：
（1）如果节点的右子树非空，则x的后继即右子树中的最左节点。可以通过调用TreeMinNum获取。
（2）如果节点的右子树为空，则x有一个后继y，则y是x的最低祖先节点，且y的左儿子也是x的祖先。
对于高度为h的一棵二叉查找树，时间运行为O（h）。

*/

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

/*
在删除node的过程中需要考虑三种情况：
（1）如果node没有子女，则直接删除node节点，使NULL成为node父节点的子女。
（2）如果节点node只有一个子女，则可以通过在其子节点与父节点之间建立一条链来删除node。
（3）如果节点node有两个子女，先删除node节点的后继y（它没有左子女），再用y的内容来代替node的内容。

第一步先确定要删除的节点deleteNode。该节点或者是输入节点node（如果node至多有只有一个子女），或者是node节点的后继（如果node有两个子女）。
第二步找到删除节点deleteNode的子女。删除节点只有一个子女，或者是左子女或者是右子女或者是NULL。
第三步删除节点deleteNode。先修改一下删除节点子女的父指针。如果删除节点是根节点，root = childNode。
如果删除节点不是根节点，稍微有点复杂。
第四步判断删除节点是否是后继节点，如果是后继节点，还需要将deleteNode内容复制到node中，从而覆盖先前内容。
*/

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

