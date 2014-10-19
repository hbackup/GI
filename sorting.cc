#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void initialize(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }
}

void randomize(int *a, int n) {
  for (int i = 0; i < n; i++) {
    int r = rand() % n;
    swap(a[i], a[r]);
  }
}

void print(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void checkSorted(int *a, int n) {
  for (int i = 1; i < n; i++) {
    if (a[i-1] > a[i]) {
      cout << "bad!!" << endl;
    }
  }
}

void insertionSort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int m = a[i];
    while (j >= 0 && a[j] > m) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = m;
  }
  checkSorted(a, n);
}

int partition(int *a, int n) {
  int pivot = a[0];
  int div = 0;  // a[div] <= pivot and a[div + 1] > pivot
  for (int i = 1; i < n; i++) {
    if (a[i] <= pivot) {
      div++;
      swap(a[div], a[i]);
    }
  }
  swap(a[0], a[div]);
  return div;
}

void quickSort(int *a, int n) {
  if (n < 2) return;
  int p = partition(a, n);
  quickSort(a, p);
  quickSort(a + p + 1, n - p - 1);
}

void siftDown(int *a, int i, int n) {
  //  if a node is smaller than its children than sift down
  if (i >= n) return;
  int left = 2 * i + 1, right = left + 1;
  if (left >= n) {
    return;
  }
  else if (right >= n) {  // only have left child
    if (a[left] > a[i]) {
      swap(a[left], a[i]);
    }
  }
  else {  // have both children
    if (a[left] > a[right]) {
      if (a[left] > a[i]) {
        swap(a[left], a[i]);
        siftDown(a, left, n);
      }
    }
    else {
      if (a[right] > a[i]) {
        swap(a[right], a[i]);
        siftDown(a, right, n);
      }
    }
  }
}

void checkHeap(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int parent = (i - 1) / 2;
    if (a[parent] < a[i]) {
      cout << a[parent] << ' ' << a[i] << ' ';
      cout << "bad!!" << endl;
    }
  }
}

void makeHeap(int *a, int n) {
  for (int i = n / 2; i >= 0; i--) {
    siftDown(a, i, n);
  }
  checkHeap(a, n);
}

void heapSort(int *a, int n) {
  makeHeap(a, n);
  int i = n - 1;
  while (i > 0) {
    swap(a[0], a[i]);
    siftDown(a, 0, i);
    i--;
  }
}

int main() {
  int size = 32;
  int *p = new int[size];
  initialize(p, size);
  print(p, size);
  randomize(p, size);
  print(p, size);
  heapSort(p, size);
  print(p, size);
}
