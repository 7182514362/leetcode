#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct List {
    ListNode* head;
    ListNode* tail;
    List(vector<int>& values) : head(nullptr), tail(nullptr) {
        for (int v : values) {
            ListNode* t = new ListNode(v);
            if (head == nullptr) {
                head = t;
                tail = t;
            } else {
                tail->next = t;
                tail = t;
            }
        }
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* p = &dummy;
        while (second != nullptr) {
            ListNode* t = first;
            first->next = second->next;
            second->next = t;
            p->next = second;
            p = first;
            second = (first->next == nullptr) ? nullptr : first->next->next;
            first = first->next;
        }

        return dummy.next;
    }
};

int main() {
    vector<int> values = {1,2,3,4,5};
    List list(values);
    printList(list.head);

    Solution sol;
    printList(sol.swapPairs(list.head));

    return 0;
}