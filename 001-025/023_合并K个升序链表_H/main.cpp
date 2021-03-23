#include <iostream>
#include <queue>
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

// 分治
class Solution {
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

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (r == l) {
            return lists[l];
        }
        int mid = (r + l) / 2;
        ListNode* first = divide(lists, l, mid);
        ListNode* second = divide(lists, mid + 1, r);
        return mergeTwoLists(first, second);
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
};

// 优先队列- 官方
class Solution2 {
   public:
    struct Status {
        int val;
        ListNode* ptr;
        bool operator<(const Status& rhs) const { return val > rhs.val; }
    };

    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node : lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

int main() {
    vector<vector<int>> values = {{1, 4}, {2, 5}, {3, 4, 5}, {1, 2}};
    vector<List> lists;

    for (auto& v : values) {
        lists.push_back(v);
    }
    vector<ListNode*> heads;
    for (auto& l : lists) {
        heads.push_back(l.head);
        printList(l.head);
    }

    Solution sol;
    printList(sol.mergeKLists(heads));

    return 0;
}