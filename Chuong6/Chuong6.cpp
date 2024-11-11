#include <iostream>
#include<cmath>
using namespace std;

class Bin_Tree {
public:
    int data;
    Bin_Tree* pLeft;
    Bin_Tree* pRight;

    Bin_Tree(int val) {
        data = val;
        pLeft = nullptr;
        pRight = nullptr;
    }
};

Bin_Tree* root = nullptr;

Bin_Tree* insert(int val, Bin_Tree* root) {
    if (root == nullptr) {
        return new Bin_Tree(val);
    }

    if (val < root->data) {
        root->pLeft = insert(val, root->pLeft);
    }
    else if (val > root->data) {
        root->pRight = insert(val, root->pRight);
    }

    return root;
}

void duyetTruoc(Bin_Tree* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        duyetTruoc(node->pLeft);
        duyetTruoc(node->pRight);
    }
}

void duyetGiua(Bin_Tree* node) {
    if (node != nullptr) {
        duyetGiua(node->pLeft);
        cout << node->data << " ";
        duyetGiua(node->pRight);
    }
}

void duyetSau(Bin_Tree* node) {
    if (node != nullptr) {
        duyetSau(node->pLeft);
        duyetSau(node->pRight);
        cout << node->data << " ";
    }
}

Bin_Tree* find(int val, Bin_Tree* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (val < root->data) {
        return find(val, root->pLeft);
    }
    else if (val > root->data) {
        return find(val, root->pRight);
    }
    else {
        return root;
    }
}

Bin_Tree* del(int val, Bin_Tree* root) {
    if (root == nullptr) return nullptr;

    if (val < root->data) {
        root->pLeft = del(val, root->pLeft);
    }
    else if (val > root->data) {
        root->pRight = del(val, root->pRight);
    }
    else {
        if (!root->pLeft && !root->pRight) {
            delete root;
            return nullptr;
        }
        else if (!root->pLeft || !root->pRight) {
            Bin_Tree* child = (root->pLeft) ? root->pLeft : root->pRight;
            delete root;
            return child;
        }
        else {
            Bin_Tree* successor = root->pRight;
            while (successor->pLeft) {
                successor = successor->pLeft;
            }
            root->data = successor->data;
            root->pRight = del(successor->data, root->pRight);
        }
    }

    return root;
}


void displayMenu()
{
    cout << "\n====== CAY ======" << endl;
    cout << "1. Duyet cay" << endl;
    cout << "2. Tim mot nut trong cay" << endl;
    cout << "3. Xoa mot nut khoi cay" << endl;
    cout << "4. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main()
{
    Bin_Tree* root=NULL;

    int n;
    int x, choice, menu=0;
    cout << "Nhap so nut cua cay: "; cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap nut a[" << i << "]:"; cin >> a[i];
        root = insert(a[i], root);
    }


    displayMenu();
    do {
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Duyet truoc: ";
            duyetTruoc(root);
            cout << endl;

            cout << "Duyet giua: ";
            duyetGiua(root);
            cout << endl;

            cout << "Duyet sau: ";
            duyetSau(root);
            cout << endl;

            displayMenu();
            break;
        }
        case 2: {
            cout << "Nhap nut can tim: "; cin >> x;
            Bin_Tree* foundNode = find(x, root);
            if (foundNode != nullptr) {
                cout << "Tim thay gia tri " << x << " trong cay." << endl;
            }
            else {
                cout << "Khong tim thay gia tri " << x << " trong cay." << endl;
            }
            displayMenu();
            break;
        }
        case 3: {
            cout << "Nhap nut can xoa: "; cin >> x;
            Bin_Tree* delNode = del(x, root);
            if (delNode != nullptr) {
                cout << "Da xoa gia tri " << x << " trong cay." << endl;
                cout << "Cay hien tai duyet theo thu tu truoc: ";
                duyetTruoc(root);
            }
            else {
                cout << "Khong tim thay gia tri " << x << " trong cay." << endl;
            }
            displayMenu();
            break;
        }
        case 4: {
            menu = 1;
        }

        }
    } while (menu == 0);

    return 0;
}
