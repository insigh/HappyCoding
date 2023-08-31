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
#include <vector>
#include <queue>

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

   struct Status {
      int val;
      ListNode *ptr;
      bool operator < (const Status &rhs) const {
         return val > rhs.val;
      }
   };

   ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue <Status> q;
      for (auto node: lists) {
         if (node) q.push({node->val, node});
      }
      ListNode head, *tail = &head;
      while (!q.empty()) {
         auto f = q.top(); q.pop();
         tail->next = f.ptr;
         tail = tail->next;
         if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
      }
      return head.next;
    }
};
