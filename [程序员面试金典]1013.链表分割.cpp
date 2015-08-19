/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1013.链表分割
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?rp=1&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return nullptr;
        }//if
        ListNode *smallList = new ListNode(-1);
        ListNode *bigList = new ListNode(-1);
        ListNode *ps = smallList,*pb = bigList,*cur = head;
        while(cur){
            if(cur->val < x){
                ps->next = cur;
                ps = cur;
            }//if
            else{
                pb->next = cur;
                pb = cur;
            }//else
            cur = cur->next;
        }//while
        pb->next = nullptr;
        ps->next = bigList->next;
        return smallList->next;
    }
};

int main() {

    return 0;
}
