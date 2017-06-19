#include <iostream>

using namespace std;

void quickSort(int *array, int esq, int dir) {
  int i = esq, j = dir;
  int temp;
  int pivot = array[(esq + dir) / 2];
  while(i <= j) {
    while(array[i] < pivot) {
      i ++;
    }
    while(array[j] > pivot) {
      j --;
    }
    if(i <= j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i ++;
      j --;
    }
  }
  if(esq < j) {
    quickSort(array, esq, j);
  }if(i < dir) {
    quickSort(array, i, dir);
  }
}

int main() {
  int vetor[] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
  quickSort(vetor, 0, 8);
  for(int i = 0; i < 9; i ++) {
    cout << vetor[i] << " ";
  }
  return 0;
}
