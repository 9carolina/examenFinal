//Ejercicio 2. Ordenamiento
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inter(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertionSort(int arr[], int n){
    int i,key,j;
    for (i=1;i<n;i++) {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high){
    if (low<high) {
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=(low-1),j;

    for ( j=low;j<=high-1;j++){
        if (arr[j]<pivot) {
            i++;
            inter(&arr[i], &arr[j]);
        }
    }
    inter(&arr[i+1], &arr[high]);
    return (i+1);
}

void bubbleSort(int arr[], int n){
    int i, j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                inter(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    const int arr_size=10000;
    int randomArray[arr_size];
    int i,j;

    srand(time(NULL));
    for (i=0;i<arr_size;i++){
        randomArray[i]=rand()%10000;
    }

    clock_t start,end;
    double cpu_time_used;

    const int num_runs=100;
    double insertionTimes[num_runs], quickTimes[num_runs], bubbleTimes[num_runs];

    for (i=0;i<num_runs;i++){
        int copyArray[arr_size];
        for (j=0;j<arr_size;j++){
            copyArray[j]=randomArray[j];
        }

        start=clock();
        insertionSort(copyArray, arr_size);
        end=clock();
        cpu_time_used=((double)(end - start))/CLOCKS_PER_SEC * 1000;
        insertionTimes[i]=cpu_time_used;

        for (j=0;j<arr_size;j++){
            copyArray[j]=randomArray[j];
        }
        start=clock();
        quickSort(copyArray, 0, arr_size - 1);
        end=clock();
        cpu_time_used=((double)(end - start))/ CLOCKS_PER_SEC * 1000;
        quickTimes[i]=cpu_time_used;

        for (j=0;j<arr_size;j++){
            copyArray[j]=randomArray[j];
        }
        start=clock();
        bubbleSort(copyArray, arr_size);
        end=clock();
        cpu_time_used=((double)(end - start))/ CLOCKS_PER_SEC * 1000;
        bubbleTimes[i]=cpu_time_used;
    }

    double insertionSum=0, quickSum=0, bubbleSum=0;
    double insertionMin=insertionTimes[0], quickMin=quickTimes[0], bubbleMin=bubbleTimes[0];
    double insertionMax=insertionTimes[0], quickMax=quickTimes[0], bubbleMax=bubbleTimes[0];

    for (i=0;i<num_runs;i++){
        insertionSum+=insertionTimes[i];
        quickSum+=quickTimes[i];
        bubbleSum+=bubbleTimes[i];

        if (insertionTimes[i]<insertionMin) insertionMin=insertionTimes[i];
        if (insertionTimes[i]>insertionMax) insertionMax=insertionTimes[i];

        if (quickTimes[i]<quickMin) quickMin=quickTimes[i];
        if (quickTimes[i]>quickMax) quickMax=quickTimes[i];

        if (bubbleTimes[i]<bubbleMin) bubbleMin=bubbleTimes[i];
        if (bubbleTimes[i]>bubbleMax) bubbleMax=bubbleTimes[i];
    }

    double insertionAvg=insertionSum / num_runs;
    double quickAvg=quickSum / num_runs;
    double bubbleAvg=bubbleSum / num_runs;

    printf("Insertion Sort:\n");
    printf("Tiempo promedio: %.6f ms\n", insertionAvg);
    printf("Tiempo minimo: %.6f ms\n", insertionMin);
    printf("Tiempo mximo: %.6f ms\n\n", insertionMax);

    printf("Quick Sort:\n");
    printf("Tiempo promedio: %.6f ms\n", quickAvg);
    printf("Tiempo minimo: %.6f ms\n", quickMin);
    printf("Tiempo maximo: %.6f ms\n\n", quickMax);

    printf("Bubble Sort:\n");
    printf("Tiempo promedio: %.6f ms\n", bubbleAvg);
    printf("Tiempo minimo: %.6f ms\n", bubbleMin);
    printf("Tiempo maximo: %.6f ms\n", bubbleMax);

    return 0;
}
