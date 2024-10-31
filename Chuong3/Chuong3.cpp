#include<iostream>
#include<cmath>

using namespace std;

int giai_thua(int n)
{
	if (n == 0) return 1;
	else return n * giai_thua(n - 1);
}

int Fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
        return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int a[20];

//8 con hậu
bool Ok(int x2, int y2) {
    for (int i = 1; i < x2; i++) {
        if (a[i] == y2 || abs(i - x2) == abs(a[i] - y2))
            return false;
    }
    return true;
}

void Xuat(int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i, int n) {
    for (int j = 1; j <= n; j++) {
        if (Ok(i, j)) {
            a[i] = j;
            if (i == n) {
                Xuat(n);
            }
            else {
                Try(i + 1, n);
            }
        }
    }
}
//8 con hậu

void ThapHaNoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "\t" << a << "-------" << c << endl;
        return;
    }
    ThapHaNoi(n - 1, a, c, b);
    ThapHaNoi(1, a, b, c);
    ThapHaNoi(n - 1, b, a, c);
}

void displayMenu() 
{
    cout << "\n====== DE QUY ======" << endl;
    cout << "1. Tinh giai thua" << endl;
    cout << "2. Tinh Fibonacci" << endl;
    cout << "3. 8 con hau" << endl;
    cout << "4. Thap Ha Noi" << endl;
    cout << "5. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main()
{
    int menu;
    do
    {
        displayMenu();
        cin >> menu;
        switch (menu) {
            case 1:
            {
                int n;
                cout << "Nhap so can tinh giai thua: ";
                cin >> n;
                cout << "Giai thua la: " << giai_thua(n);
                break;
            }
            case 2:
            {
                int n;
                cout << "Nhap so can tinh Fibonacci: ";
                cin >> n;
                cout << Fibonacci(n);
                break;
            }
            case 3:
            {
                Try(1, 8); 
                break;
            }
            case 4:
            {
                char a = 'A', b = 'B', c = 'C';
                int n;
                cout << "Nhap so dia: ";
                cin >> n;
                ThapHaNoi(n, a, b, c);
                cout << "\nHoan thanh!";
                break;
            }
            case 5: {
                exit(0);
            }
            default:
            {
                cout << "Lua chon khong kha dung, vui long chon lai";
                break;
            }
        }
    } while (menu != 6);
}