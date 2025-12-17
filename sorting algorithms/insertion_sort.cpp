#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr) {
  for (int &a: arr) {
    cout << a << " ";
  }
  cout << endl;
}

void selection_sort(vector<int>& arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  vector<int> arr = {33,23,4325,356,34,3,34,773,75,5234,77};
  print(arr);
  selection_sort(arr, (int)arr.size());
  print(arr);
}