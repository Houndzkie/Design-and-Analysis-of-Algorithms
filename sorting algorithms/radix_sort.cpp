#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr) {
  for (int &a: arr) {
    cout << a << " ";
  }
  cout << endl;
}

void radix_sort(vector<int>& arr, int n) {
  // butngan pa
}

int main() {
  vector<int> arr = {33,23,4325,356,34,3,34,773,75,5234,77};
  print(arr);
  radix_sort(arr, (int)arr.size());
  print(arr);
}