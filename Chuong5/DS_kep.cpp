#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void addAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current; 
        }
    }

    Node* createNode(int x) {
        return new Node(x);
    }

    void addNode(int x, bool atHead = true) {
        if (atHead) {
            addAtHead(x);
        }
        else {
            addAtTail(x);
        }
    }


    void deleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << value << " not found." << endl; 
    }

    void duyet() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            deleteHead();
        }
    }

    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }
};

int main() {
    DoublyLinkedList list;

    list.addAtHead(10);
    list.addAtTail(20);
    list.addAtTail(30);
    list.addAtHead(5);

    cout << "List: ";
    list.duyet();

    cout << "Them 15 vao cuoi danh sach" << endl;
    list.addNode(15, false);
    list.duyet();

    
    cout << "Them 1 vao dau danh sach" << endl;
    list.addNode(1);
    list.duyet();

    cout << "Xóa nút có giá trị 20." << endl;
    list.deleteNode(20);
    list.duyet();

    cout << "Thử xóa nút có giá trị 100." << endl;
    list.deleteNode(100);

    return 0;
}
