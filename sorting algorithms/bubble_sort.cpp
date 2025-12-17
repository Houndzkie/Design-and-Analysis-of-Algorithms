#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr) {
  for (int &a: arr) {
    cout << a << " ";
  }
  cout << endl;
}

void bubble_sort(vector<int>& arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int main() {
  vector<int> arr = {33,23,4325,356,34,3,34,773,75,5234,77};
  print(arr);
  bubble_sort(arr, (int)arr.size());
  print(arr);
}