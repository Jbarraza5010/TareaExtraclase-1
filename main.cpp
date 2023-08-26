#include <iostream>
#include <fstream>
#include  <string>

using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// To check if array is sorted or not
bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

// To generate permutation of the array
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

// Sorts array a[0..n-1] using Bogo sort
void bogosort(int a[], int n)
{
    // if array is not sorted then shuffle
    // the array again
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

class PagedArray {
public:
    PagedArray operator [] (PagedArray p){
        PagedArray new_page;

        return new_page;
    }
};

int main () {
    string sortType;
    string file;
    int size;
    cout << "Ingrese el tamaño del archivo:";
    cin >> file;
    if (file == "1kb.txt")
        size = 256;
    else if (file == "4kb.txt")
        size = 1024;
    else if (file == "8kb.txt")
        size = 2048;
    else if (file == "12kb.txt")
        size = 3072;
    else if (file == "24kb.txt")
        size = 6144;
    else if (file == "32kb.txt")
        size = 9216;
    cout << "Ingrese el algoritmos de ordenamiento:";
    cin >> sortType;
    if (sortType == "QS") {
        int array1[size];
        int array2[size];
        int n = 0;
        fstream datafile;
        datafile.open(file);
        if (!datafile.is_open()) {
            cout << "Failure to open." << endl;
            return 0;
        }
        while (!datafile.eof()) {
            datafile >> array1[n];
            if (datafile.fail()) break;
            n++;
        }
        datafile.close();
        //for (int i = 0; i < n; i++)
        //cout << array1[i] << " ";

        quickSort(array1, 0, size);
        printArray(array1, size);

        ofstream sortFile ("/home/tomeito/CLionProjects/TareaExtraclase-1/example.txt");
        if (sortFile.is_open())
        {
            for(int count = 0; count < size; count ++){
                sortFile << array1[count] << " " ;
            }
            sortFile.close();
        }
        else cout << "Unable to open file";
    }
    else if (sortType == "IS") {
        int array1[size];
        int array2[size];
        int n = 0;
        fstream datafile;
        datafile.open(file);
        if (!datafile.is_open()) {
            cout << "Failure to open." << endl;
            return 0;
        }
        while (!datafile.eof()) {
            datafile >> array1[n];
            if (datafile.fail()) break;
            n++;
        }
        datafile.close();
        //for (int i = 0; i < n; i++)
        //cout << array1[i] << " ";

        insertionSort(array1, size);
        printArray(array1, size);

        ofstream sortFile ("/home/tomeito/CLionProjects/TareaExtraclase-1/example.txt");
        if (sortFile.is_open())
        {
            for(int count = 0; count < size; count ++){
                sortFile << array1[count] << " " ;
            }
            sortFile.close();
        }
        else cout << "Unable to open file";
    }

    else if(sortType == "SS")
    {
        int array1[size];
        int array2[size];
        int n = 0;
        fstream datafile;
        datafile.open(file);
        if (!datafile.is_open()) {
            cout << "Failure to open." << endl;
            return 0;
        }
        while (!datafile.eof()) {
            datafile >> array1[n];
            if (datafile.fail()) break;
            n++;
        }
        datafile.close();
        //for (int i = 0; i < n; i++)
        //cout << array1[i] << " ";

        selectionSort(array1, size);
        printArray(array1, size);

        ofstream sortFile ("/home/tomeito/CLionProjects/TareaExtraclase-1/example.txt");
        if (sortFile.is_open())
        {
            for(int count = 0; count < size; count ++){
                sortFile << array1[count] << " " ;
            }
            sortFile.close();
        }
        else cout << "Unable to open file";
    }

    else if(sortType == "PS")
    {
        int array1[size];
        int array2[size];
        int n = 0;
        fstream datafile;
        datafile.open(file);
        if (!datafile.is_open()) {
            cout << "Failure to open." << endl;
            return 0;
        }
        while (!datafile.eof()) {
            datafile >> array1[n];
            if (datafile.fail()) break;
            n++;
        }
        datafile.close();
        //for (int i = 0; i < n; i++)
        //cout << array1[i] << " ";

        bogosort(array1, size);
        printArray(array1, size);

        ofstream sortFile ("/home/tomeito/CLionProjects/TareaExtraclase-1/example.txt");
        if (sortFile.is_open())
        {
            for(int count = 0; count < size; count ++){
                sortFile << array1[count] << " " ;
            }
            sortFile.close();
        }
        else cout << "Unable to open file";
    }


    return 0;
}