#include <iostream>

int N, K;
int count = 0, result = 0;
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main() {
  std::cin >> N >> K;
  int *array = new int[N];
  for (int i = 0; i < N; i++)
    std::cin >> array[i];

  merge_sort(array, 0, N - 1);
  if (count < K)
    result = -1;
  std::cout << result << '\n';

  return 0;
}

void merge_sort(int *arr, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void merge(int *arr, int start, int mid, int end) {
  int *sorted_array = new int[end + 1];
  int left = start, right = mid + 1, index = left;

  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right])
      sorted_array[index++] = arr[left++];
    else
      sorted_array[index++] = arr[right++];
  }
  while (left <= mid) {
    sorted_array[index++] = arr[left++];
  }
  while (right <= end) {
    sorted_array[index++] = arr[right++];
  }
  for (int i = start; i < end + 1; i++) {
    arr[i] = sorted_array[i];
    count++;
    if (count == K)
      result = arr[i];
  }

  delete[] sorted_array;
}