#include <iostream>
using namespace std;

int Seq_Search(int X, int a[], int n)
{
	int i = 0;
	while (i < n && a[i] != X)
	{
		i++;
	}
	if (i < n) return i; 
	return -1; 
}

int Bin_Search(int X, int a[], int n)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (X < a[m]) r = m - 1;
		else if (X > a[m]) l = m + 1;
		else return m; 
	}
	return -1;
}

void displayMenu()
{
	cout << "\n====== TIM KIEM ======" << endl;
	cout << "1. Sequence Search" << endl;
	cout << "2. Binary Search" << endl;
	cout << "3. Exit" << endl;
	cout << "==================" << endl;
	cout << "Nhap lua chon cua ban: ";
}

int main()
{
	int n=0, menu = 0, choice;
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu a[" << i << "]: ";
		cin >> a[i];
	}
	do {
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int x;
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			int result = Seq_Search(x, a, n);
			if (result != -1)
			{
				cout << "Phan tu o vi tri a[" << result << "]";
			}
			else
			{
				cout << "Phan tu khong ton tai trong mang." << endl;
			}
			break;
		}
		case 2:
		{
			int x;
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			int result = Bin_Search(x, a, n);
			if (result != -1)
			{
				cout << "Phan tu o vi tri a[" << result << "]";
			}
			else
			{
				cout << "Phan tu khong ton tai trong mang." << endl;
			}
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
			cout << "Lua chon khong hop le. Vui long thu lai.";
			break;
		}
	} while (menu == 0);

	return 0;
}
