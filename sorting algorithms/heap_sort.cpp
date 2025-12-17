#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr) {
  for (int &a: arr) {
    cout << a << " ";
  }
  cout << endl;
}

void selection_sort(vector<int>& arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(arr[i], arr[min_idx]);
  }
}

int main() {
  vector<int> arr = {33,23,4325,356,34,3,34,773,75,5234,77};
  print(arr);
  selection_sort(arr, (int)arr.size());
  print(arr);
}