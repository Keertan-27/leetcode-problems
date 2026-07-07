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
    ListNode* reverseNode(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr && head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseNode(slow->next);
        ListNode* left = head;
        ListNode* right = newHead;
        while (right != nullptr) {
            if (left->val != right->val) {
                slow->next = reverseNode(newHead);
                return false;
            }
            left = left->next;
            right = right->next;
        }
        slow->next = reverseNode(newHead);
        return true;
    }
};