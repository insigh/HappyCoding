/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        int l = 0;
        while(l++ < k) {
            fast = fast->next;
        }

        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};