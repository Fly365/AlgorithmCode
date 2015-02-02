/*
思路一：
如果当前结点t 大于结点u、v，说明u、v都在t 的左侧，所以它们的共同祖先必定在t 的左子树中，故从t 的左子树中继续查找；
如果当前结点t 小于结点u、v，说明u、v都在t 的右侧，所以它们的共同祖先必定在t 的右子树中，故从t 的右子树中继续查找；
如果当前结点t 满足 u <t < v，说明u和v分居在t 的两侧，故当前结点t 即为最近公共祖先；
而如果u是v的祖先，那么返回u的父结点，同理，如果v是u的祖先，那么返回v的父结点。
*/
// 最近公共祖先
TreeNode *LCA(TreeNode *root,TreeNode *u,TreeNode *v){
    // 空树
    if(root == nullptr || u == nullptr || v == nullptr){
        return nullptr;
    }//if
    // u < t < v  or v < t < u
    if((u->val < root->val && root->val < v->val) ||
       (v->val < root->val && root->val < u->val)){
        return root;
    }//if
    // u < root and v < root  left sub tree
    if(u->val < root->val && v->val < root->val){
        // u是v祖先 or v是u的祖先
        if(root->left == u || root->left == v){
            return root;
        }//if
        return LCA(root->left,u,v);
    }//if
    // u > root and v > root  right sub tree
    if(u->val > root->val && v->val > root->val){
        // u是v祖先 or v是u的祖先
        if(root->right == u || root->right == v){
            return root;
        }//if
        return LCA(root->right,u,v);
    }//if
    return nullptr;
}


/*
思路二：
迭代版
*/
/**--------------------------------
*   日期：2015-02-02
*   作者：SJF0115
*   题目: 最近公共祖先(LCA)迭代版
*   博客：
------------------------------------**/
TreeNode *LCA(TreeNode *root,TreeNode *u,TreeNode *v){
    // 空树
    if (root == nullptr || u == nullptr || v == nullptr) {
        return nullptr;
    }//if
    TreeNode *leftNode = u;
    TreeNode *rightNode = v;
    TreeNode *parentNode = nullptr;
    //二叉查找树内，如果左结点大于右结点，不对，交换
    if (leftNode->val > rightNode->val) {
        TreeNode *tmp = leftNode;
        leftNode = rightNode;
        rightNode = tmp;
    }//if
    while(root){
         // u < t < v  or v < t < u   在root两侧
        if(leftNode->val < root->val && root->val < rightNode->val){
            return root;
        }//if
        // u < root v < root left sub tree
        if(rightNode->val < root->val){
            parentNode = root;
            root = root->left;
        }//if
        // u > root v > root right sub tree
        else if(leftNode->val > root->val){
            parentNode = root;
            root = root->right;
        }
        // u是v祖先 or v是u的祖先
        else if(root == leftNode || root == rightNode){
            return parentNode;
        }
    }//while
    return nullptr;
}
