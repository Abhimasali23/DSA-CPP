#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for(int i=0;i<len1;i++) {
        first[i] = arr[k++];
    }    

    k = mid+1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    
    k = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[k++] = first[index1++];
        }
        else {
            arr[k++] = second[index2++];
        }
    }

    while (index1 < len1)
    { 
        arr[k++] = first[index1++];   
    }

    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
}


void MergeSort(int *arr, int s, int e) {

    // base case 
    if(s >= e) 
        return;

    int mid = s + (e-s)/2;

    // left part
    MergeSort(arr, s, mid);

    //right part
    MergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}


void Print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[10] = {15, 36, 98, 10, 0, 2, 65, 78, 45, 1};
    int n = 10;

    cout << "Before Sorting " << endl;
    Print(arr, n);

    MergeSort(arr, 0, n - 1);

    cout << "After Sorting " << endl;
    Print(arr, n);

    return 0;
}