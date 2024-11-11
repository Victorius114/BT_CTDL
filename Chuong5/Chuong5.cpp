#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DS_Don {
private:
    Node* head;

public:
    DS_Don() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteValue(int x) {
        if (!head) return;

        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != x) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            cout << "Nut khong ton tai" << endl;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl; 
    }

    ~DS_Don() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

class DS_Kep {
private:
    Node* head;

public:
    DS_Kep() : head(nullptr) {}

    void add_Dau(int value) {
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

    void add_Cuoi(int value) {
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
            add_Dau(x);
        }
        else {
            add_Cuoi(x);
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
        cout << "Nut khong ton tai" << endl;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DS_Kep() {
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

void displayMenu()
{
    cout << "\n====== DANH SACH MOC NOI ======" << endl;
    cout << "1. Danh sach moc noi don" << endl;
    cout << "2. Danh sach moc noi kep" << endl;
    cout << "3. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

void displayMenu1()
{
    cout << "\n====== DANH SACH MOC NOI DON ======" << endl;
    cout << "1. Them mot nut vao danh sach" << endl;
    cout << "2. Xoa mot nut khoi danh sach" << endl;
    cout << "3. Hien thi danh sach hien tai" << endl;
    cout << "4. Back" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

void displayMenu2()
{
    cout << "\n====== DANH SACH MOC NOI KEP ======" << endl;
    cout << "1. Them mot nut vao dau danh sach" << endl;
    cout << "2. Them mot nut vao cuoi danh sach" << endl;
    cout << "3. Xoa mot nut khoi danh sach" << endl;
    cout << "4. Hien thi danh sach hien tai" << endl;
    cout << "5. Back" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    DS_Don list;
    DS_Kep list2;
    int choice, menu = 0;
    displayMenu();
    do {
        cin >> choice;
        system("cls");
        switch (choice)
        {

        case 1: {
            int choice1, menu1 = 0;
            displayMenu1();
            do {
                cin >> choice1;
                system("cls");
                switch (choice1) {

                case 1: {
                    int val1;
                    cout << "Nhap gia tri nut muon them vao danh sach: "; cin >> val1;
                    list.append(val1);
                    cout << "Danh sach hien tai: ";
                    list.display();
                    cout << "\n";
                    displayMenu1();
                    break;
                }                
                case 2: {
                    int val1;
                    cout << "Nhap gia tri nut muon xoa khoi danh sach: "; cin >> val1;
                    list.deleteValue(val1);
                    cout << "Danh sach hien tai: ";
                    list.display();
                    cout << "\n";
                    displayMenu1();
                    break;
                }

                case 3: {
                    cout << "Danh sach hien tai: ";
                    list.display();
                    cout << "\n";
                    displayMenu1();
                    break;
                }

                case 4:
                {
                    menu1 = 1;
                    displayMenu();
                    break;
                }

                }
            } while (menu1 == 0);
            break;
        }

        case 2: {
            int choice2, menu2 = 0;
            displayMenu2();
            do {
                cin >> choice2;
                system("cls");
                switch (choice2) 
                {
                case 1: {
                    int val2;
                    cout << "Nhap gia tri nut muon them vao danh sach: "; cin >> val2;
                    list2.add_Dau(val2);
                    cout << "Danh sach hien tai: ";
                    list2.display();
                    cout << "\n";
                    displayMenu2();
                    break;
                }
                case 2: {
                    int val2;
                    cout << "Nhap gia tri nut muon them vao danh sach: "; cin >> val2;
                    list2.add_Cuoi(val2);
                    cout << "Danh sach hien tai: ";
                    list2.display();
                    cout << "\n";
                    displayMenu2();
                    break;
                }

                case 3: {
                    int val2;
                    cout << "Nhap gia tri nut muon xoa khoi danh sach: "; cin >> val2;
                    list2.deleteNode(val2);
                    cout << "Danh sach hien tai: ";
                    list2.display();
                    cout << "\n";
                    displayMenu2();
                    break;
                }

                case 4: {
                    cout << "Danh sach hien tai: ";
                    list2.display();
                    cout << "\n";
                    displayMenu2();
                    break;
                }

                case 5:
                {
                    menu2 = 1;
                    displayMenu();
                }

                }
            } while (menu2 == 0);
            break;
        }

        case 3: {
            exit(0);
        }

        }
    } while (menu == 0);

    return 0;
}
