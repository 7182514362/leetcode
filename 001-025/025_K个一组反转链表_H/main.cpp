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
    // reverse [first+1, kth]
    ListNode* reverseKNodes(ListNode* first, ListNode* kth) {
        ListNode* t1 = kth->next;
        ListNode* t2 = first->next;

        ListNode* cur = t2;
        ListNode* pre = first;
        while (cur != t1) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        t2->next = t1;
        first->next = kth;
        return t2;
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        if (k == 1) {
            return head;
        }
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* kth = head;
        int i = 1;
        while (kth != nullptr) {
            if (i == k) {
                ListNode* t = kth->next;
                first = reverseKNodes(first, kth);
                kth = t;
                i = 1;
                continue;
            }
            kth = kth->next;
            ++i;
        }
        return dummy.next;
    }
};

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List list(values);
    printList(list.head);

    Solution sol;
    printList(sol.reverseKGroup(list.head, 9));

    return 0;
}