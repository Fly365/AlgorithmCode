/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1015.输出单层结点
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/cb6c883b123b44399377d0c71e6ba3ea?rp=1&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root == nullptr || dep <= 0){
            return nullptr;
        }//if
        // 头结点
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        // 队列 层次遍历
        queue<TreeNode*> curQueue;
        curQueue.push(root);
        queue<TreeNode*> nextQueue;
        int level = 1;
        while(!curQueue.empty()){
            while(!curQueue.empty()){
                TreeNode *node = curQueue.front();
                curQueue.pop();
                // 某一深度上所有结点的链表
                if(level == dep){
                    p->next = new ListNode(node->val);
                    p = p->next;
                }//if
                if(node->left){
                    nextQueue.push(node->left);
                }//if
                if(node->right){
                    nextQueue.push(node->right);
                }//if
            }//while
            swap(curQueue,nextQueue);
            if(level == dep){
                return head->next;
            }//if
            ++level;
        }//while
        return nullptr;
    }
};

int main() {
    TreeLevel s;

    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(4);
    node1->left = node3;

    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    node2->left = node4;
    node2->right = node5;

    int dep = 5;
    ListNode *head = s.getTreeLevel(root,dep);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }//while
    cout<<endl;
    return 0;
}
