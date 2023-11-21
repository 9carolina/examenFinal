/*Ejercicio 3. Búsqueda 
**NO SIEMPRE DA 0's ms
	SI SALE DISTINTO, SOLO ES CUESTION DE COMPILAR VARIAS VECES*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sequentialSearch(int arr[], int n, int x){
    int i;
	for (i=0;i<n;i++){
        if (arr[i]==x){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int left, int right, int x){
    if (right>=left){
        int mid=left+(right-left)/2;
        if (arr[mid]==x){
            return mid;
        }
        if (arr[mid]>x){
            return binarySearch(arr,left,mid-1,x);
        }
        return binarySearch(arr,mid+1,right,x);
    }
    return -1;
}

int main(){
    const int arr_size=50000;
    int sortedArray[arr_size];
    int i,j;
    for (i=0;i<arr_size;i++){
        sortedArray[i]=i; 
    }
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    const int num_runs=100;
    int searchValue;
    double sequentialTimes[num_runs], binaryTimes[num_runs];
    for (i=0;i<num_runs;i++){
        searchValue=rand()%arr_size;

        start=clock();
        sequentialSearch(sortedArray, arr_size, searchValue);
        end=clock();
        cpu_time_used=((double)(end - start))/CLOCKS_PER_SEC*1000;
        sequentialTimes[i]=cpu_time_used;

        start=clock();
        binarySearch(sortedArray, 0, arr_size-1, searchValue);
        end=clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        binaryTimes[i] = cpu_time_used;
    }

    double sequentialSum=0, binarySum=0;
    double sequentialMin=sequentialTimes[0], binaryMin=binaryTimes[0];
    double sequentialMax=sequentialTimes[0], binaryMax=binaryTimes[0];

    for (i=0;i<num_runs;i++){
        sequentialSum+=sequentialTimes[i];
        binarySum+=binaryTimes[i];
        if (sequentialTimes[i]<sequentialMin) sequentialMin=sequentialTimes[i];
        if (sequentialTimes[i]>sequentialMax) sequentialMax=sequentialTimes[i];
        if (binaryTimes[i]<binaryMin) binaryMin=binaryTimes[i];
        if (binaryTimes[i]>binaryMax) binaryMax=binaryTimes[i];
    }

    double sequentialAvg=sequentialSum/num_runs;
    double binaryAvg=binarySum/num_runs;

    printf("Sequential Search:\n");
    printf("Average time: %.6f ms\n", sequentialAvg);
    printf("Minimum time: %.6f ms\n", sequentialMin);
    printf("Maximum time: %.6f ms\n\n", sequentialMax);

    printf("Binary Search:\n");
    printf("Average time: %.6f ms\n", binaryAvg);
    printf("Minimum time: %.6f ms\n", binaryMin);
    printf("Maximum time: %.6f ms\n", binaryMax);

    return 0;
}
