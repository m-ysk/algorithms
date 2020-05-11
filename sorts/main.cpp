#include <string.h>

#include <chrono>
#include <iostream>

#include "bubble_sort.cpp"

using namespace std;

// Confirm initial data is not sorted
void validate_initial_data(int n, int data[], string name) {
  for (int i = 0; i < n - 1; ++i) {
    if (data[i] > data[i + 1]) {
      return;
    }
  }
  cout << "invalid initial data: " << name << endl;
}

// Confirm result is successfully sorted
void validate_result(int n, int data[], string name) {
  for (int i = 0; i < n - 1; ++i) {
    if (data[i] > data[i + 1]) {
      cout << "failed: " << name << endl;
      return;
    }
  }
  cout << "success: " << name << endl;
}

int main() {
  int N = 10000;
  int origin[N];

  for (int i = 0; i < N; ++i) {
    origin[i] = rand();
  }

  int data[N];
  memcpy(data, origin, sizeof(origin));

  validate_initial_data(N, data, "Bubble sort");
  auto start = chrono::system_clock::now();
  primitive_bubble_sort(N, data);
  auto end = chrono::system_clock::now();
  validate_result(N, data, "Bubble sort");
  double time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);
}
