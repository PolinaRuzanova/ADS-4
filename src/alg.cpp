// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int sum = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }   
    }  
    int last = len-1;
    int perv = 0;
    while (perv < last) {
        while ((arr[perv] + arr[last] > value) && (last > perv)) {
            last--;
        }
        while (arr[perv] + arr[last] == value) {
            sum++;
            last--;
        }
        perv++;
        last = len - 1;
    }
    return sum;
}
int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int num = 0;
    int mid;
    while (right >= left) {
        mid = (right + left) / 2;
        if (arr[mid] == value) {
            num++;
            break;
        }   
        if (arr[mid] < value) {
            left = mid + 1;
        }
        if (arr[mid] > value) {
            right = mid - 1;
        }
    }
    if (num != 0) {
        for (int i = mid + 1; arr[i] == value && i <= size - 1; i++) {
            num++;
        }
        for (int i = mid - 1; arr[i] == value && i >= 0; i--) {
            num++;
        }
    }
    return num;
}
int countPairs3(int *arr, int len, int value) {
  for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int num = 0;
    int s = 0;
    for (int i = 0; arr[i] <= value / 2; i++) {
        num += cbinsearch(arr, len, value - arr[i]);
    }
    for (int i = 0; i <= cbinsearch(arr, len, value / 2); i++) {
        s = s + i;
    }
    return (num - s);
}
