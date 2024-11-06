#include<iostream>
using namespace std;
class Stack {
public:
	void push(int x, int& top, int size, int a[]) {
		if (top >= size - 1) {
			cout << "Stack day\n";
		}
		else {
			top++;
			a[top] = x;
		}
	}

	void pop(int& top) {
		if (top <= -1) {
			cout << "Stack rong\n";
		}
		else {
			top--;
		}
	}
};

class Queue {
public:
	void queue_them(int queue[], int x, int rear, int size)
	{
		if (rear == size) {
			cout << "Queue day, khong the them!";
		}
		else {
			queue[rear] = x;
		}
	}

	void queue_xoa(int queue[], int x, int front, int rear)
	{
		if (rear == 0) {
			cout << "Khong con phan tu nao trong queue";
		}
		else {
			int j = 0;
			while (j < rear) {
				queue[j] = queue[j + 1];
				j++;
			}
		}
	}
};


void displayMenu()
{
	cout << "\n" << endl;
	cout << "\n====== STACK va QUEUE ======" << endl;
	cout << "1. Them phan tu vao stack" << endl;
	cout << "2. Them phan tu vao queue" << endl;
	cout << "3. Exit" << endl;
	cout << "==================" << endl;
	cout << "Nhap lua chon cua ban: ";
}

void displayArr(int a[], int i, int size) {
	for (i = 0; i < size; i++) {
		if (i == 0) {
			cout << "{" << a[i] << "; ";
		}
		else if (i == size - 1) {
			cout << a[i] << "}";
		}
		else {
			cout << a[i] << "; ";
		}
	}
}

int main()
{
	int size=0;
	int i;
	cout << "Nhap do dai cua a: "; cin >> size;
	int* a = new int[size];
	for (i = 0; i < size; i++) {
		cout << "Nhap phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
	cout << "a[]= ";
	displayArr(a, i, size);

	int menu = 0, choice;
	do {
		Stack s;
		Queue q;

		displayMenu();
		cin >> choice;
		switch (choice) {
			case 1:
			{
				int x;
				int top = size - 1;
				cout << "Nhap phan tu muon them vao stack: "; cin >> x;
				cout << "Lay phan tu a[" << size - 1 << "] ra khoi stack" << endl;
				s.pop(top);
				cout << "Them phan tu moi vao vi tri a[" << size - 1 << "]" << endl;
				s.push(x, top, size, a);
				displayArr(a, i, size);
				break;
			}

			case 2:
			{
				int x;
				cout << "Nhap phan tu muon them vao queue: "; cin >> x;
				q.queue_xoa(a, x, 0, size);
				cout << "Xoa phan tu a[0]: " << a[0];
				cout << "\n";
				displayArr(a, i, size-1);
				cout << "\nThem phan tu moi vao vi tri a[" << size-1<<"] ";
				q.queue_them(a, x, size - 1, size);
				cout << "\nQueue moi: "<<endl;
				displayArr(a, i, size);
				break;
			}

			case 3: {
				exit(0);
			}
		}
	} while (menu == 0);
}