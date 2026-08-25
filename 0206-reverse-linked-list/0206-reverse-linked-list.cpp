const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}

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

//OPTIMAL
//ITERATIVE

//3 pointers

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;      //curr
        ListNode* prev = nullptr;   //prev
        ListNode* front = nullptr;  //front

        while(temp){
            front = temp->next;     //keep front ahead of curr
            temp->next = prev;      //make curr point to prev
            prev = temp;            //move prev ahead
            temp = front;           //move temp ahead too
        }

        return prev;        //new head will be at end which is prev
    }
};