#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr) {
  for (int &a: arr) {
    cout << a << " ";
  }
  cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
  }
}

int main() {
  vector<int> arr = {33,23,4325,356,34,3,34,773,75,5234,77};
  print(arr);
  quick_sort(arr, 0, (int)arr.size());
  print(arr);
}