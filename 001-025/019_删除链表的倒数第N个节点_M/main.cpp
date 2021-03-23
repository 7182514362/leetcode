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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        int i = 0;
        while (first != nullptr) {
            first = first->next;
            if (i > n) {
                second = second->next;
            }
            ++i;
        }

        if (i < n) {
            return head;
        }
        if (i == n) {
            return head->next;
        }

        ListNode* p = second->next;
        second->next = p->next;
        delete p;

        return head;
    }
};

//官方
class Solution2 {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main() {
    vector<int> values = {1, 2};
    List list(values);
    printList(list.head);

    Solution sol;
    printList(sol.removeNthFromEnd(list.head, 2));

    return 0;
}