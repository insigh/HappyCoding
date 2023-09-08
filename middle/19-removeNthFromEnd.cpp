/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *pre=head;
        int cnt = 0;
        while (fast != nullptr && cnt++ < n+1){
            fast = fast->next;
        }

        if(cnt < n+1){
            return head->next;
        }

        while(fast != nullptr) {
            fast = fast->next;
            pre = pre->next;
        }

        if (pre == nullptr || pre->next == nullptr){
            return nullptr;
        }


        pre->next = pre->next->next;


        return head;
    }

    // double pointer with dummy node
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head, *second = dummy;
        int cnt = 0;
        while (cnt++ < n){
            fast = fast->next;
        }

        while(fast != nullptr){
            fast = fast->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    // stack solution
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        std::stack<ListNode*> stk;
        ListNode *dummy = new ListNode(0, head);
        ListNode *node = dummy;
        while (node != nullptr)
        {
            stk.push(node);
        }

        for (int i = 0; i < n; i++){
            stk.pop();
        }
        ListNode *pre = stk.top();
        pre->next = pre->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};