#include <stdio.h>

void printArray(int value[], int count);

//버블 정렬
void bubbleSort(int value[], int count)
{
  int i = 0, j = 0;
  int temp = 0;

  for(i = count - 1; i >= 0; i--)
  {
    // for(j = 0; j <= i; j++) {
    for(j = 1; j <= i; j++) {
      {
        if (value[j - 1] > value[j]) 
        //value의 첫 인덱스 보다 그 전에 있는 인덱스랑 비교했을 때 만약 조건이 맞다면 쓰래기 값과 swap을 할 수도 있다고 생각한다.
        // 그래서 더 좋은 코드로 바꿔야 한다는 생각이들어서 j = 0보다는 j = 1로 만들어주었다.
        {
          temp = value[j - 1];
          value[j - 1] = value[j];
          value[j] = temp;
        }
      }
    }
    printf("Step- %d, ", count - i);
    printArray(value, count);
  }
}

void printArray(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    };
    printf("\n");
}

int main(int argc, char *argv[])
{
  int values[] = {70, 60, 50, 40, 30, 20, 12, 10}; 
    printArray(values, 8);
    bubbleSort(values, 8);
    printArray(values, 8);
    // printf("%d", values[-1]);
    return 0;
}

