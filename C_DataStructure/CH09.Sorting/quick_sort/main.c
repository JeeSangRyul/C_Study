#include <stdio.h>
#include <unistd.h>

void printArray(int values[]) {
    for (int i = 0; i < sizeof(values); i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r]; // 맨 오른쪽을 pivot으로 두는 QuickSort
    int i = (l - 1);    // 일단 l보다 하나 전 위치에 둔다.
    //여기서 i의 역할은 pivot보다 작은 방의 개수를 알려주는 역할도 한다.
    int temp = 0;

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } //j가 가리키는 값이 pivot값보다 작아야지만 if문으로 들어올 수 있다.
    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;

    printf("start-[%d], end-[%d],pivot-[%d], in - loop \n", l, r, pivot);
    return (i + 1);//i 이하의 방들은 i + 1보다 작은 방이라는 것을 알 수 있다.
}

void quickSort(int arr[], int l, int r)
{
    if (l < r) // l과 r이 만나거나 클경우 -> 방이 하나만 남을 때 끝이나는 조건
    {
        int p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int value[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(value);
    quickSort(value, 0, 7);
    printArray(value);
    return 0;
}