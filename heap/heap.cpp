#include <chrono>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Heap {
  vector<int> data;

 public:
  Heap() {}

  void push(int v) {
    data.push_back(v);
    int i = data.size() - 1;
    while (i > 0) {
      int p = (i - 1) / 2;
      if (data[p] >= v) break;
      data[i] = data[p];
      i = p;
    }
    data[i] = v;
  }

  int top() {
    if (data.empty()) return 0;
    return data[0];
  }

  void pop() {
    if (data.empty()) return;

    data[0] = data.back();
    data.pop_back();

    int last_idx = data.size() - 1;
    int i = 0;
    while (true) {
      int right = 2 * i + 2;
      int left = right - 1;

      if (right <= last_idx) {
        if (data[right] > data[left] && data[right] > data[i]) {
          swap(data[i], data[right]);
          i = right;
          continue;
        } else if (data[left] > data[i]) {
          swap(data[i], data[left]);
          i = left;
          continue;
        }
        break;
      } else if (left <= last_idx && data[left] > data[i]) {
        swap(data[i], data[left]);
        i = left;
        continue;
      }
      break;
    }
  }

  int size() { return data.size(); }
};

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
      cout << i << ": " << data[i] << endl;
      cout << i + 1 << ": " << data[i + 1] << endl;
      return;
    }
  }
  cout << "success: " << name << endl;
}

const int large_N = 3000000;
int large_origin[large_N];
int large_data[large_N];

int main() {
  srand(time(0));
  for (int i = 0; i < large_N; ++i) {
    large_origin[i] = rand();
  }

  double time;
  chrono::system_clock::time_point start, end;

  Heap heap = Heap();

  start = chrono::system_clock::now();
  for (int i = 0; i < large_N; ++i) {
    heap.push(large_origin[i]);
  }
  end = chrono::system_clock::now();
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);

  start = chrono::system_clock::now();
  int prev = -1;
  for (int i = 0; i < large_N; ++i) {
    int cur = heap.top();
    heap.pop();

    if (prev != -1 && cur > prev) {
      cout << "failed" << endl;
      cout << "prev: " << prev << endl;
      cout << "cur: " << cur << endl;
      return 0;
    }

    prev = cur;
  }
  end = chrono::system_clock::now();
  time = static_cast<double>(
      chrono::duration_cast<chrono::milliseconds>(end - start).count());
  printf("time %lf[ms]\n", time);

  cout << "success" << endl;
}
