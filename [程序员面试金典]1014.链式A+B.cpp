/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1014.链式A+B
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/ed85a09f0df047119e94fb3e5569855a?rp=1&ru=/ta/cracking-the-coding-interview
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

class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // 头结点
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        ListNode *node = nullptr;
        int c = 0,sum,val1,val2;
        ListNode *pa = a,*pb = b;
        //加法
        while(pa != nullptr || pb != nullptr || c != 0){
            val1 = (pa == nullptr ? 0 : pa->val);
            val2 = (pb == nullptr ? 0 : pb->val);
            sum = val1 + val2 + c;
            // 进位
            c = sum / 10;
            node = new ListNode(sum % 10);

            //尾插法
            p->next = node;
            p = node;
            pa = (pa == nullptr ? nullptr : pa->next);
            pb = (pb == nullptr ? nullptr : pb->next);
        }//while
        return head->next;
    }
};

int main() {
    Plus s;
    int A[] = {2,4,7,9};
    int B[] = {5,6,4};
    ListNode *head = NULL;
    ListNode *head1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head1->next = NULL;
    head2->next = NULL;
    ListNode *node;
    ListNode *pre = head1;
    for(int i = 0;i < 4;i++){
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val = A[i];
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    pre = head2;
    for(int i = 0;i < 3;i++){
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val = B[i];
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    head = s.plusAB(head1->next,head2->next);
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}
