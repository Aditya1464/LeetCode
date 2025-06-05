class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index >= size) return -1;
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if(size == 0) {
            tail = head;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index >= size) return;
        if(index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            if(head == nullptr) tail = nullptr;
            size--;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if(temp->next == nullptr) tail = temp;
        delete toDelete;
        size--;
    }
};
