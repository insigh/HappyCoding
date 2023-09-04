/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getLength(ListNode *head) {
        int len = 1;
        while(head->next != nullptr) {
            head = head->next;
            ++len;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = getLength(headA);
        int len_b = getLength(headB);
        ListNode *longer = len_a >= len_b? headA : headB;
        ListNode *shorter = len_a >= len_b? headB : headA;
        int dis = len_a >= len_b? (len_a - len_b):(len_b - len_a);
        while(dis > 0) {
            longer = longer->next;
            --dis;
        }

        while(longer != shorter && longer != nullptr){
            longer = longer->next;
            shorter = shorter->next;
        }

        return longer;
    }
};