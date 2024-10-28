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

Bin_Tree* insert(int value, Bin_Tree* root) {

    if (root == nullptr) {
        return new Bin_Tree(value);
    }
    if (value < root->data) {
        root->pLeft = insert(value, root->pLeft);
    }
    else {
        root->pRight = insert(value, root->pRight);
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

int main()
{
    Bin_Tree* root=NULL;

    int n;
    cout << "Nhap so nut cua cay (khong chia het cho 2): "; cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap nut a[" << i << "]:"; cin >> a[i];
        root = insert(a[i], root);
    }

    cout << "Duyet truoc: ";
    duyetTruoc(root);
    cout << endl;

    cout << "Duyet giua: ";
    duyetGiua(root);
    cout << endl;

    cout << "Duyet sau: ";
    duyetSau(root);
    cout << endl;

    return 0;
}
