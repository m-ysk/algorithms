#include <string.h>

#include <chrono>
#include <iostream>

#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"

using namespace std;

// Confirm initial data is not sorted
void validate_initial_data(int n, int data[]) {
  for (int i = 0; i < n - 1; ++i) {
    if (data[i] > data[i + 1]) {
      return;
    }
  }
  cout << "invalid initial data" << endl;
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
  int N = 20000;
  int origin[N];

  srand(time(0));
  for (int i = 0; i < N; ++i) {
    origin[i] = rand();
  }

  int data[N];
  double time;
  chrono::system_clock::time_point start, end;

  // Insertion sort
  memcpy(data, origin, sizeof(origin));

  validate_initial_data(N, data);
  start = chrono::system_clock::now();
  primitive_bubble_sort(N, data);
  end = chrono::system_clock::now();
  validate_result(N, data, "Insertion sort");
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);

  // Bubble sort
  memcpy(data, origin, sizeof(origin));

  validate_initial_data(N, data);
  start = chrono::system_clock::now();
  primitive_bubble_sort(N, data);
  end = chrono::system_clock::now();
  validate_result(N, data, "Bubble sort");
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);

  // Improved bubble sort
  memcpy(data, origin, sizeof(origin));

  validate_initial_data(N, data);
  start = chrono::system_clock::now();
  improved_bubble_sort(N, data);
  end = chrono::system_clock::now();
  validate_result(N, data, "Improved bubble sort");
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);

  // Quick sort
  memcpy(data, origin, sizeof(origin));

  validate_initial_data(N, data);
  start = chrono::system_clock::now();
  quick_sort(0, N, data);
  end = chrono::system_clock::now();
  validate_result(N, data, "Quick sort");
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);
}
