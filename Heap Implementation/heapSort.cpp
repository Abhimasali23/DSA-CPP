#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i);

void heapSort(int arr[], int n) {

    int size = n;
    
    while(size > 1) {
        // step 1
        swap(arr[1], arr[size]);
        size--;

        // step 2
        heapify(arr, size, 1);
    }
}


void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {

    int arr[6] = {-1, 5, 4, 1, 2, 3};
    int n = 5;

    for(int i=n/2;i>0;i--) {
        heapify(arr, n, i);
    }

    for(int i=1;i<=n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}