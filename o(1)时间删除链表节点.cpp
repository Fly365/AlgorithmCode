/*********************************
*   ���ڣ�2014-10-29
*   ���ߣ�SJF0115
*   ��Ŀ: ���������ͷָ���һ�����ָ�룬��O(1)ʱ��ɾ���ý��
*   ��Դ������������
*   �ܽ᣺
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
//O(1)ʱ�� ɾ�������еĽڵ�
void DeleteNode(ListNode** head,ListNode* node){
    if(head == NULL || node == NULL){
        return;
    }
    ListNode* p = node->next;
    // ɾ���Ĳ���ĩβ�ڵ� O(1)
    if(p != NULL){
        //ɾ��p�ڵ�
        node->next = p->next;
        // �ڵ�p���Ƶ�node�ڵ�
        node->next = p->next;
        node->val = p->val;
        delete p;
        p = NULL;
    }
    // ɾ������ĩβ�ڵ� O(n)
    else{
        ListNode* pre = *head;
        // ĩβ�ڵ�
        while(pre->next != node){
            pre = pre->next;
        }
        //ɾ��node�ڵ�
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

    //��ͷ�������
    DeleteNode(&node1,node2);

    while(node1 != NULL){
        printf("%d ",node1->val);
        node1 = node1->next;
    }
    return 0;
}
