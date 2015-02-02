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


/*
思路三：
所谓共同的父结点，就是两个结点都出现在这个结点的子树中。因此我们可以定义一函数，来判断一个结点的子树中是不是包含了另外一个结点。
这不是件很难的事，我们可以用递归的方法来实现：
*/
// root树中是否包含节点node
bool Exits(TreeNode *root,TreeNode *node){
    // find the node
    if(root == node){
        return true;
    }//if
    // left sub tree
    bool isExits = false;
    if(root->left){
        isExits = Exits(root->left,node);
    }//if
    // right sub tree
    if(!isExits && root->right){
        isExits = Exits(root->right,node);
    }//if
    return isExits;
}
/*
我们可以从根结点开始，判断以当前结点为根的树中左右子树是不是包含我们要找的两个结点。
如果两个结点都出现在它的左子树中，那最低的共同父结点也出现在它的左子树中。
如果两个结点都出现在它的右子树中，那最低的共同父结点也出现在它的右子树中。
如果两个结点一个出现在左子树中，一个出现在右子树中，那当前的结点就是最低的共同父结点。
*/
// 最近公共祖先
TreeNode *LCA(TreeNode *root,TreeNode *u,TreeNode *v){
    // 空树
    if(root == nullptr || u == nullptr || v == nullptr){
        return nullptr;
    }//if
    // check whether left child has u and v
    bool leftHasNode1 = false;
    bool leftHasNode2 = false;
    if(root->left){
        leftHasNode1 = Exits(root->left,u);
        leftHasNode2 = Exits(root->left,v);
    }//if
    if(leftHasNode1 && leftHasNode2){
        if(root->left == u || root->left == v){
            return root;
        }//if
        return LCA(root->left,u,v);
    }//if
    // check whether right child has u and v
    bool rightHasNode1 = false;
    bool rightHasNode2 = false;
    if(root->right){
        if(!leftHasNode1){
            rightHasNode1 = Exits(root->right,u);
        }//if
        if(!leftHasNode2){
            rightHasNode2 = Exits(root->right,v);
        }//if
    }//if
    if(rightHasNode1 && rightHasNode2){
        if(root->right == u || root->right == v){
            return root;
        }//if
        return LCA(root->right,u,v);
    }//if
    // both left and right child has
    if((leftHasNode1 && rightHasNode2) || (leftHasNode2 && rightHasNode1)){
        return root;
    }//if
    return nullptr;
}

/*
思路四：
前面我们提过如果结点中有一个指向父结点的指针，我们可以把问题转化为求两个链表的共同结点。
现在我们可以想办法得到这个链表。我们在本面试题系列的第4题中分析过如何得到一条中根结点开始的路径。
我们在这里稍作变化即可：
*/
/**--------------------------------
*   日期：2015-02-02
*   作者：SJF0115
*   题目: 从根节点到目标节点的路径
------------------------------------**/
bool NodePath (TreeNode* root,TreeNode* node,vector<TreeNode*> &path) {
    if(root == node) {
        return true;
    }//if
    path.push_back(root);
    bool isExits = false;
    // left sub tree
    if(root->left) {
        isExits = NodePath(root->left,node,path);
    }//if
    if(!isExits && root->right) {
        isExits = NodePath(root->right,node,path);
    }//if
    if(!isExits) {
        path.pop_back();
    }//if
    return isExits;
}
//由于这个路径是从跟结点开始的。最低的共同父结点就是路径中的最后一个共同结点：
/**--------------------------------
*   日期：2015-02-02
*   作者：SJF0115
*   题目: 最近公共祖先(LCA)链表法
*   博客：
------------------------------------**/
TreeNode *LCA(TreeNode *root,TreeNode *u,TreeNode *v){
    vector<TreeNode*> path1,path2;
    // 根节点到u的路径
    bool isFound1 = NodePath(root,u,path1);
    // 根节点到v的路径
    bool isFound2 = NodePath(root,v,path2);
    if(!isFound1 || !isFound2){
        return nullptr;
    }//if
    int size1 = path1.size();
    int size2 = path2.size();
    TreeNode *node = nullptr;
    for(int i = 0,j = 0;i < size1 && j < size2;++i,++j){
        if(path1[i] == path2[j]){
            node = path1[i];
        }//if
    }//for
    return node;
}

//这种思路的时间复杂度是O(n)，时间效率要比第一种方法好很多。但同时我们也要注意到，这种思路需要两个链表来保存路径，空间效率比不上第一个方法。


