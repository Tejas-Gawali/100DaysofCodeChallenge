#include<iostream>
using  namespace std;

int partition(int arr[] , int s , int e){

    int pivot = arr[s];
    int count = 0;

    for (int i = s+1; i <=e ; i++)
    {
        if(pivot >= arr[i]){
            count++;
        }
    }
        int pivotIndex = s + count;
        swap(arr[s], arr[pivotIndex]);

        int b =s ; int j =e;
        while(b < pivotIndex && j > pivotIndex){

            while(arr[b]< pivotIndex){
                b++;
            }

            while(arr[j] >  pivotIndex){
                j--;
            }

            if(b < pivotIndex && j > pivotIndex){
                swap(arr[b++] , arr[j--]);
            }
        }

        return pivotIndex;
    

    
    
}

void quickSort(int arr[] , int s , int e){

    if(s>=e){
        return;
    }

    int p = partition(arr , s ,e);
    

    quickSort(arr , s ,p-1);
    quickSort(arr , p+1 , e);
}


int main(){
    
    int arr[5] = {2,4,1,6,9};
    int n=5;

    quickSort(arr, 0  , n-1);
    
    for(int i =0 ; i< n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}