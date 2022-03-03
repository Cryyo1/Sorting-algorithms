#include <stdio.h>
#include <stdlib.h>


int* Bubble_Sort(int* array,int length){
    int i,j,tmp;
    for(i=0;i<length;i++){
        for(j=1;j<length-i;j++){
            if(array[j]<array[j-1]){
                tmp=array[j];
                array[j]=array[j-1];
                array[j-1]=tmp;
            }
        }
    }
    return array;
}
/****************************************************************/
int* Insertion_Sort(int* array,int length){
    int i,j,tmp;

    for(i=1;i<length;i++){
        tmp=array[i];
        j=i;
        while(j>0 && array[j-1]>tmp){
            array[j]=array[j-1];
            j--;
        }
        array[j]=tmp;
    }
    return array;
}
/****************************************************************/
int* Selection_Sort(int* array,int length){
    int i,j,tmp,min;

    for(i=0;i<length;i++){
        min=i;
        for(j=i+1;j<length;j++){
            if(array[j]<min)
                min=j;
        }
        tmp=array[min];
        array[min]=array[i];
        array[i]=tmp;

    }
    return array;
}
/****************************************************************/
int* Merge(int* array,int first,int mid,int last){
    int i,j,k;
    int *left,*right;
    int length1 = mid - first + 1;
    int length2 = last - mid;
    left=(int*)malloc( length1 * sizeof(int) ); 
    right=(int*)malloc( length2 * sizeof(int) );

    for (i = 0; i < length1; i++)
        left[i] = array[first+i];

    for (j = 0; j < length2; j++)
        right[j] = array[mid+1+j];


    i = 0;
    j = 0;
    k =first;
    while (i < length1 && j < length2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
  
    while (i < length1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < length2) {
        array[k] = right[j];
        j++;
        k++;
    }
    free(right);
    free(left);
}

int* Merge_Sort(int* array,int first,int last){

    if(first<last){
        int mid=(first+last)/2;
        Merge_Sort(array,first,mid);
        Merge_Sort(array,mid+1,last);
        Merge(array,first,mid,last);
        return array;
    }
        
}

/****************************************************************/


///another version of partition

/* int partition(int* array,int first,int last){
    int pivot=array[first];
    int i,j,tmp;
    i=first+1;
    j=last-1;
    while(i<j){
        while(i<last && array[i]<=pivot){i++;}
        while(j>first && array[j]>=pivot){j--;}

        if(i<j){
            tmp=array[i];
            array[i]=array[j];
            array[j]=tmp;
            i++;
            j--;
        }
    }

    tmp=array[j];
    array[j]=array[first];
    array[first]=tmp;

    return j;

} */

int partition(int* array, int first, int last) {

    int pivot = array[first];
    int i = first,tmp;

    tmp=array[first];
    array[first]=array[last];
    array[last]=tmp;


    for (int j = first; j < last; j++) {
        if (array[j] <= pivot) {
            tmp=array[i];
            array[i]=array[j];
            array[j]=tmp;
            i++;
        }
    }

    tmp=array[i];
    array[i]=array[last];
    array[last]=tmp;

    return i;
}

int* Quick_Sort(int* array,int first,int last){
    if(first < last){
        int pivotIndex=partition(array,first,last);
        /*if you use fucntion partition 1u change last parameter to pivotIndex instead of pivotIndex-1*/
        Quick_Sort(array,first,pivotIndex-1);
        Quick_Sort(array,pivotIndex+1,last);
        return array;
    }
}

/****************************************************************/
void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int* array,int length,int i){
    int left,right,max;
    left=i*2+1;
    right=i*2+2;
    max=i;
    if(left<length && array[left]>array[max] ){
        max=left;
    }
    if(right<length && array[right]>array[max]){
        max=right;
    }
    printf("max=%d\n",array[max]);
    if(max!=i){
        swap(&array[max],&array[i]);
        heapify(array,length,max);
    }
    
}

int* Heap_Sort(int* array,int length){
    int i;
    for (i=length/2-1;i >= 0; i--)
        heapify(array, length, i);

    for(i=length-1;i>=0;i--){
        swap(&array[i],&array[0]);
        heapify(array,i,0);
    }
    return array;

}

