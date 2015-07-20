/*---------------------------------------
*   日期：2015-07-20
*   作者：SJF0115
*   题目: 7.从尾到头打印链表
*   结果：AC
*   网址：http://www.nowcoder.com/books/coding-interviews/d0267f7f55b3412ba93bd35cfa8e8035?rp=1
*   来源：剑指Offer
*   博客：
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        ListNode* p = head;
        while(p){
            result.insert(result.begin(),p->val);
            p = p->next;
        }//while
        return result;
    }
};

int main(){
    Solution s;
    ListNode* root = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    root->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    vector<int> result = s.printListFromTailToHead(root);
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<endl;
    }//for
    return 0;
}

// 递归实现
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        // 递归实现
        helper(head,result);
        return result;
    }
private:
    void helper(ListNode* head,vector<int> &result){
        if(head){
            if(head->next){
                helper(head->next,result);
            }//if
            result.push_back(head->val);
        }//if
    }
};

