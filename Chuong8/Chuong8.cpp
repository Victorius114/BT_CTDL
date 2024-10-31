#include<iostream>
#include<cmath>
using namespace std;
int a[100];
void displayMenu()
{
    cout << "\n" << endl;
    cout << "\n====== SAP XEP ======" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= "; cin >> a[i];
    }
}

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        int min = i; 
        for (int j = i + 1; j < n; j++) { 
            if (a[j] < a[min]) {
                min = j; 
            }
        }
        if (min != i) {
            swap(a[i], a[min]);
        }
    }
}

void insertionSort(int a[], int n)
{
    int holePosition;
    int valueToInsert;
    for (int i = 0; i < n; i++)
    {
        valueToInsert = a[i];
        holePosition = i;
        while (holePosition > 0 && a[holePosition - 1] > valueToInsert)
        {
            a[holePosition] = a[holePosition - 1];
            holePosition = holePosition - 1;
        }
        a[holePosition] = valueToInsert;
    }
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { 
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]); 
            }
        }
    }
}



//mergesort
void merge(int a[], int n1, int b[], int n2, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }

    while (i < n1) {
        c[k++] = a[i++];
    }

    while (j < n2) {
        c[k++] = b[j++];
    }
}

void mergesort(int a[], int n) {
    if (n < 2) return;

    int m = n / 2;

    int* l1 = new int[m]; 
    int* l2 = new int[n - m];

    for (int i = 0; i < m; i++) {
        l1[i] = a[i];
    }

    for (int i = m; i < n; i++) {
        l2[i - m] = a[i];
    }

    mergesort(l1, m); 
    mergesort(l2, n - m); 

    merge(l1, m, l2, n - m, a);

    delete[] l1;
    delete[] l2;
}
//mergesort


//quick sort
int partitionFunc(int left, int right, int pivot)
{
    int leftPointer = left - 1;
    int rightPointer = right;
    while (1)
    {
        while (a[++leftPointer] < pivot)
        {
        }
        while (rightPointer > 0 && a[--rightPointer] > pivot)
        {
        }

        if (leftPointer >= rightPointer)
        {
            break;
        }
        else swap(leftPointer, rightPointer);
    }
    swap(leftPointer, right);
    return leftPointer;
}
void quickSort(int left, int right)
{
    if (right - left <= 0)
        return;
    else
    {
        int pivot = a[right];
        int partition = partitionFunc(left, right, pivot);
        quickSort(left, partition - 1);
        quickSort(partition + 1, right);
    }
}
//quick sort

int main()
{
    int n;
    cout << "Nhap so phan tu: "; cin >> n;
    nhap(a, n);

    int menu;
    do
    {
        displayMenu();
        cin >> menu;
        switch (menu) {
        case 1:
        {
            SelectionSort(a, n);
            cout << "Sap xep: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << "  ";
            }
            break;
        }
        case 2:
        {
            insertionSort(a, n);
            cout << "Sap xep: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << "  ";
            }
            break;
        }
        case 3:
        {
            BubbleSort(a, n);
            cout << "Sap xep: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << "  ";
            }
            break;
        }
        case 4:
        {
            mergesort(a, n);
            cout << "Sap xep: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << "  ";
            }
            break;
        }
        case 5:
        {
            quickSort(1, n-1);
            cout << "Sap xep: ";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << "  ";
            }
            break;
        }
        case 6: {
            exit(0);
        }
        default:
        {
            cout << "Lua chon khong kha dung, vui long chon lai";
            break;
        }
        }
    } while (menu != 7);
}