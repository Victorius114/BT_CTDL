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
    cout << "4. Heap Sort" << endl;
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

// Hàm để xây dựng max-heap từ mảng
void heapify(int arr[], int n, int i) {
    int largest = i;        // Giả sử nút hiện tại là lớn nhất
    int left = 2 * i + 1;   // Con trái
    int right = 2 * i + 2;  // Con phải

    // Nếu con trái lớn hơn nút hiện tại
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn nút hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu nút hiện tại không phải lớn nhất
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm thực hiện Heap Sort
void heapSort(int arr[], int n) {
    // Xây dựng max-heap từ mảng
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Đưa phần tử lớn nhất hiện tại về cuối mảng
        heapify(arr, i, 0);    // Xây dựng lại max-heap trên mảng thu gọn
    }
}

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
            heapSort(a, n);
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