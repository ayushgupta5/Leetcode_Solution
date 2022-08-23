/*234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/
class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *curr=head, *next=NULL, *prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return head=prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *curr=head, *slow=head, *fast=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow){
            if(slow->val != curr->val) return 0;
            slow=slow->next;
            curr=curr->next;
        }
        return 1;
    }
};