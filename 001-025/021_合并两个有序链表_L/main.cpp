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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* l3 = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }

        l3->next = (l1 == nullptr) ? l2 : l1;

        return dummy.next;
    }
};

int main() {
    vector<int> values1 = {1, 3, 5, 7, 8};
    vector<int> values2 = {2, 4, 5, 6, 9, 9};
    List list1(values1);
    List list2(values2);
    printList(list1.head);
    printList(list2.head);

    Solution sol;
    printList(sol.mergeTwoLists(list1.head, list2.head));
    return 0;
}