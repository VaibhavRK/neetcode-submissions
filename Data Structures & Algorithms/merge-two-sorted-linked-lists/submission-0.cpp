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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy; // 'tail' will build the new list

    // 3. Traverse both lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;   // Link the smaller node
            list1 = list1->next;  // Move list1 forward
        } else {
            tail->next = list2;   // Link the smaller node
            list2 = list2->next;  // Move list2 forward
        }
        tail = tail->next;        // Move our merged list's tail forward
    }

    // 4. One list will likely finish before the other. 
    // Simply attach the remaining nodes from the other list.
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // 5. The actual merged list starts AFTER the dummy node
    ListNode* mergedHead = dummy->next;
    delete dummy; // Clean up the memory we allocated
    
    return mergedHead;
    }
};
