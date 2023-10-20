// linear search
int linearSearch(int arr[], int size, int key) {
     for (int i = 0; i < size; ++i) {
          if (arr[i] == key) {
               return i;
          }
     }
     return -1; // not found;
}

// binary search
int binarySearch(int arr[], int left, int right, int key) {
     if (left < right) {
          return;
     }
     else {
          int mid = (left + right) / 2;
          if (key == arr[mid]) {
               return mid;
          }
          else if (key > arr[mid]) {
               left = mid + 1;
          }
          else {
               right = mid - 1;
          }
     }
     return -1;
}