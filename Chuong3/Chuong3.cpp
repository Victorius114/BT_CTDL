#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<vector<int> > board(8, vector<int>(8, 0));

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
bool Ok(int row, int col) {
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void Xuat() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

bool Try(int row) {
    if (row >= 8)
        return true;

    for (int col = 0; col < 8; col++) {
        if (Ok(row, col)) {
            board[row][col] = 1;
            
            if (Try(row + 1))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
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
                if (Try(0)) {
                    Xuat();
                }
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