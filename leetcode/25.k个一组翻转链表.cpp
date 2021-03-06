/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] k个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (48.76%)
 * Total Accepted:    7.9K
 * Total Submissions: 15.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* c = head;
        int length = 0;
        while (c != nullptr) {
            length++;
            c = c->next;
        }
        if (length < k) return head;
        
        int partition = length / k;
        c = head;
        ListNode* segment_head = nullptr;
        ListNode* segment_tail = nullptr;
        for (int i = 0; i < partition; i++) {
            segment_tail = c;
            ListNode* prev = nullptr;
            for (int j = 0; j < k; j++) {
                ListNode* next = c->next;
                c->next = prev;
                prev = c;
                c = next;
            }
            if (segment_head == nullptr) {
                head = prev;
            } else {
                segment_head->next = prev;
            }
            segment_head = segment_tail;
        }
        if (c != nullptr) {
            segment_head->next = c;
        }
        return head;
    }
};