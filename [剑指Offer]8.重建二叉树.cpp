/*---------------------------------------
*   日期：2015-07-20
*   作者：SJF0115
*   题目: 8.重建二叉树
*   结果：AC
*   网址：http://www.nowcoder.com/books/coding-interviews/8a19cbe657394eeaac2f6ea9b0f6fcf6?rp=1
*   来源：剑指Offer
*   博客：http://blog.csdn.net/SunnyYoona/article/details/46966143
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int size = pre.size();
        if(size == 0){
            return nullptr;
        }//if
        return PreInBuildTree(pre,in,0,0,size);
    }
private:
    TreeNode* PreInBuildTree(vector<int> preorder,vector<int> inorder,int preIndex,int inIndex,int size){
        if(size == 0){
            return nullptr;
        }//if
        // 根节点
        TreeNode* root = new TreeNode(preorder[preIndex]);
        // 寻找根节点在中序遍历数组的下标
        int index = 0;
        for(int i = 0;i < size;++i){
            // 注意：inorder[inIndex+i]
            if(preorder[preIndex] == inorder[inIndex+i]){
                index = inIndex+i;
                break;
            }//if
        }//for
        // 左子树个数
        int leftSize = index - inIndex;
        // 右子树个数
        int rightSize = size - leftSize - 1;
        // 左子树
        root->left = PreInBuildTree(preorder,inorder,preIndex+1,inIndex,leftSize);
        // 右子树
        root->right = PreInBuildTree(preorder,inorder,preIndex+1+leftSize,index+1,rightSize);
        return root;
    }
};

void PostOrder(TreeNode* root){
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->val<<endl;
    }//if
}

int main(){
    Solution s;
    vector<int> preOrder = {1,2,4,7,3,5,6,8};
    vector<int> inOrder = {4,7,2,1,5,3,8,6};
    TreeNode* root = s.reConstructBinaryTree(preOrder,inOrder);
    PostOrder(root);
    return 0;
}
