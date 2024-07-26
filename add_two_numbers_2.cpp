/*
Link: https://leetcode.com/problems/add-two-numbers-ii/description/

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* head = nullptr;
        ListNode* t = head;
        ListNode* t1 = l1, *t2 = l2;
        int carry = 0;
        while(t1 && t2){
            int sum = t1->val + t2->val + carry;
            if(sum >= 10){
                carry = 1;
            } else {
                carry = 0;
            }
            sum %= 10;
            ListNode* n = new ListNode(sum);
            if(t == nullptr){
                head = n;
                t = head;
            } else {
                t->next = n;
                t = t->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            int sum = t1->val + carry;
            if(sum >= 10){
                carry = 1;
            } else {
                carry = 0;
            }
            sum %= 10;
            ListNode* n = new ListNode(sum);
            if(t == nullptr){
                head = n;
                t = head;
            } else {
                t->next = n;
                t = t->next;
            }
            t1 = t1->next;
        }
        while(t2){
            int sum = t2->val + carry;
            if(sum >= 10){
                carry = 1;
            } else {
                carry = 0;
            }
            sum %= 10;
            ListNode* n = new ListNode(sum);
            if(t == nullptr){
                head = n;
                t = head;
            } else {
                t->next = n;
                t = t->next;
            }
            t2 = t2->next;
        }
        if(carry == 1){
            ListNode* n = new ListNode(carry);
            if(t == nullptr){
                head = n;
                t = head;
            } else {
                t->next = n;
                t = t->next;
            }
        }
        return reverseList(head);
    }
};