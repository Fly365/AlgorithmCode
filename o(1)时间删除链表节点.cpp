/*********************************
*   日期：2014-10-29
*   作者：SJF0115
*   题目: 给定链表的头指针和一个结点指针，在O(1)时间删除该结点
*   来源：经典面试题
*   总结：
**********************************/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//O(1)时间 删除链表中的节点
void DeleteNode(ListNode** head,ListNode* node){
    if(head == NULL || node == NULL){
        return;
    }
    ListNode* p = node->next;
    // 删除的不是末尾节点 O(1)
    if(p != NULL){
        //删除p节点
        node->next = p->next;
        // 节点p复制到node节点
        node->next = p->next;
        node->val = p->val;
        delete p;
        p = NULL;
    }
    // 删除的是末尾节点 O(n)
    else{
        ListNode* pre = *head;
        // 末尾节点
        while(pre->next != node){
            pre = pre->next;
        }
        //删除node节点
        pre->next = NULL;
        delete node;
        node = NULL;
    }
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    //无头结点链表
    DeleteNode(&node1,node2);

    while(node1 != NULL){
        printf("%d ",node1->val);
        node1 = node1->next;
    }
    return 0;
}
