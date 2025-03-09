#include <bits/stdc++.h>
using namespace std;
typedef string Data;

class Node {
private:
    Data data;
    Node* nxt;
    Node* pre;

    friend class DoublyCircularLinkedList;
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyCircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyCircularLinkedList() {
        if (empty()) return;
       
        tail->nxt = nullptr;
        Node* cur = head;

        while (cur != nullptr) {
            Node* nextNode = cur->nxt;
            delete cur;
            cur = nextNode;
        }
    }

    bool empty() const { return size == 0; }

    int get_size() const { return size; }

    Data front() const {
        if (empty()) {
            cout << "List is empty" << '\n';
            return Data();
        }

        return head->data;
    }

    Data back() const {
        if (empty()) {
            cout << "List is empty" << '\n';
            return Data();
        }

        return tail->data;
    }

    void push_front(const Data& val) {
        Node* newNode = new Node;
        newNode->data = val;

        if (empty()) {
            head = tail = newNode;
            newNode->nxt = newNode;
            newNode->pre = newNode;
        }

        else {
            newNode->nxt = head;
            newNode->pre = tail;
            head->pre = newNode;
            tail->nxt = newNode;
            head = newNode;
        }

        size++;
    }

    void push_back(const Data& val) {
        Node* newNode = new Node;
        newNode->data = val;

        if (empty()) {
            head = tail = newNode;
            newNode->nxt = newNode;
            newNode->pre = newNode;
        }

        else {
            newNode->pre = tail;
            newNode->nxt = head;
            tail->nxt = newNode;
            head->pre = newNode;
            tail = newNode;
        }

        size++;
    }

    void pop_front() {
        if (empty()) return;

        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }

        else {
            Node* tmp = head;
            head = head->nxt;
            head->pre = tail;
            tail->nxt = head;
            delete tmp;
        }

        size--;
    }

    void pop_back() {
        if (empty()) return;

        if (size == 1) {
            delete tail;
            head = tail = nullptr;
        }

        else {
            Node* tmp = tail;
            tail = tail->pre;
            tail->nxt = head;
            head->pre = tail;
            delete tmp;
        }

        size--;
    }

    void merge(DoublyCircularLinkedList& other) {
        if (other.empty()) return;

        if (empty()) {
            head = other.head;
            tail = other.tail;
            size = other.size;
        }

        else {
            tail->nxt = other.head;
            other.head->pre = tail;
            tail = other.tail;
            tail->nxt = head;
            head->pre = tail;
            size += other.size;
        }

        other.head = other.tail = nullptr;
        other.size = 0;
    }

    int find(const Data& val) const {
        if (empty()) return -1;

        Node* frontPtr = head;
        Node* backPtr = tail;
        int front_idx = 0;
        int back_idx = size - 1;

        while (front_idx <= back_idx) {
            if (frontPtr->data == val) return front_idx;
            if (backPtr->data == val) return back_idx;

            frontPtr = frontPtr->nxt;
            backPtr = backPtr->pre;
            front_idx++;
            back_idx--;
        }

        return -1;
    }

    void insert(int idx, const Data& val) {
        if (idx < 0 || idx > size) {
            cout << "Out of index" << '\n';
            return;
        }

        if (idx == 0) {
            push_front(val);
            return;
        }

        if (idx == size) {
            push_back(val);
            return;
        }

        Node* newNode = new Node;
        newNode->data = val;

        Node* cur;
        if (idx < size / 2) {
            cur = head;
            for (int i = 0; i < idx - 1; i++) cur = cur->nxt;
        }

        else {
            cur = tail;
            for (int i = size - 1; i > idx - 1; i--) cur = cur->pre;
        }

        cur->nxt->pre = newNode;
        newNode->nxt = cur->nxt;
        newNode->pre = cur;
        cur->nxt = newNode;

        size++;
    }

    void remove(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Out of index" << '\n';
            return;
        }

        if (empty()) {
            cout << "List is empty" << '\n';
            return;
        }

        if (idx == 0) {
            pop_front();
            return;
        }

        if (idx == size - 1) {
            pop_back();
            return;
        }

        Node* cur;
        if (idx < size / 2) {
            cur = head;
            for (int i = 0; i < idx; i++) cur = cur->nxt;
        }

        else {
            cur = tail;
            for (int i = size - 1; i > idx; i--) cur = cur->pre;
        }

        cur->nxt->pre = cur->pre;
        cur->pre->nxt = cur->nxt;
        delete cur;

        size--;
    }

    void print() const {
        Node* cur = head;

        do {
            cout << cur->data;
            cur = cur->nxt;
        } while (cur != head);

        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<DoublyCircularLinkedList> lists(n);
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        lists[i].push_back(name);
    }

    for (int k = 0; k < n - 1; k++) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        lists[i].merge(lists[j]);
    }

    for (const auto& l : lists) {
        if (!l.empty()) {
            l.print();
            break;
        }
    }

    return 0;
}