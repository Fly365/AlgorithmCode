/*********************************
*   日期：2014-12-30
*   作者：SJF0115
*   题目: 二叉树创建
*   来源：
*   博客：http://blog.csdn.net/sunnyyoona/article/details/42263865
**********************************/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层次创建二叉树
TreeNode* CreateTreeByLevel(vector<char> num){
    int len = num.size();
    if(len == 0){
        return NULL;
    }//if
    queue<TreeNode*> queue;
    int index = 0;
    // 创建根节点
    TreeNode *root = new TreeNode(num[index++]);
    // 入队列
    queue.push(root);
    TreeNode *p = NULL;
    while(!queue.empty() && index < len){
        // 出队列
        p = queue.front();
        queue.pop();
        // 左节点
        if(index < len && num[index] != -1){
            // 如果不空创建一个节点
            TreeNode *leftNode = new TreeNode(num[index]);
            p->left = leftNode;
            queue.push(leftNode);
        }
        index++;
        // 右节点
        if(index < len && num[index] != -1){
            // 如果不空创建一个节点
            TreeNode *rightNode = new TreeNode(num[index]);
            p->right = rightNode;
            queue.push(rightNode);
        }
        index++;
    }//while
    return root;
}

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
