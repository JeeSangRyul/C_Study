#include <stdio.h>

#define max 6

//conquer - 여기서 서열정리를 진행
void merge(int a[], int low, int mid, int high) {
    int b[10]; //임시 배열
    int i = low, j = mid + 1, k = 0;

    //싸움 붙이는 역할(한 쪽이 전멸할 때까지
    while(i <= mid && j <= high) { 
        //왼쪽 진영에서 가장 낮은 i가 mid까지 갈때,
        //오른쪽 진영에서 가장 낮은 j가 high까지 갈때.
        if (a[i] <= a[j]) {       
            b[k] = a[i]; //패배자 list가 들어가게된다.
            k++;
            i++;
        }else{
            b[k] = a[j];
            k++;
            j++;
        }
    }

    //왼쪽이 살아있다면
    while(i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    //오른쪽이 살아있다면
    while (j <= high) {
        b[k] = a[j];
        k++;
        j++;
    }
    k--;
    //문서작성
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    } 
}

//divide - 나눠서 merge()에 보내면
void mergesort(int a[], int low, int high) { //low는 첫번째 index, high는 마지막 index

    //exit condition
    if(low < high){ //low 와 high가 같아지는 시점에 재귀함수를 탈출하게 된다.
        int middle = (low + high)/2; //나누는 과정
        
        //left
        mergesort(a, low, middle);

        //right
        mergesort(a, middle + 1, high);

        //fight
        merge(a, low, middle, high);

    }else{
        return ;
    }
}

int main() {
    int arr[max] = {20, 10, 70, 80, 40, 90};
    int i = 0;
    printf("\n before merge ");
    for (i = 0; i < max; i++) {
        printf("%d, ", arr[i]);
    }
    mergesort(arr, 0, max - 1);
    printf("\n after merge ");
    for (i = 0; i < max; i++) {
        printf("%d, ", arr[i]);
    }
}