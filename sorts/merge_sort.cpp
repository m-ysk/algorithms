void merge(int data[], int result[], int left, int mid, int right) {
  int i = left;
  int j = mid;
  int cur = 0;
  while (i < mid && j < right) {
    if (data[i] < data[j]) {
      result[cur] = data[i];
      ++i;
      ++cur;
    } else {
      result[cur] = data[j];
      ++j;
      ++cur;
    }
  }

  while (i < mid) {
    result[cur] = data[i];
    ++i;
    ++cur;
  }

  while (j < right) {
    result[cur] = data[j];
    ++j;
    ++cur;
  }

  for (int k = 0; k < cur; ++k) {
    data[left + k] = result[k];
  }
}

void merge_sort(int data[], int arr[], int left, int right) {
  if (right - left <= 1) return;
  int mid = (left + right) / 2;
  merge_sort(data, arr, left, mid);
  merge_sort(data, arr, mid, right);
  merge(data, arr, left, mid, right);
}