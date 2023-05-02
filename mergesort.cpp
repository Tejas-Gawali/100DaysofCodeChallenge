#include<iostream>
using namespace std;

void merge(int *arr , int s ,int e){
    

    int mid = (s+e)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    int mai = s ;

    for(int i = 0 ; i< len1 ; i++){
        first[i] = arr[mai++];
    }

    mai = mid+1;
    for(int i = 0 ; i < len2 ; i++){
        second[i]= arr[mai++];
        
    }

    

    int j = 0;
    int k = 0;
    mai = s;

    while(j < len1 && k < len2){
        if(first[j] < second[k]){
            arr[mai++] = first[j++];
        }
        else{
            arr[mai++] = second[k++];
        }

        
    }

    while(j < len1){
            arr[mai] = first[j];
            mai++;
            j++;
    }

    while(k < len2){
            arr[mai] = second[k];
            mai++;
            k++;
    }

    delete []first;
    delete []second;


}

void mergeSort(int *arr , int s , int e){
    

    if(s>=e){
        return;
    }

    int mid = (s+e)/2;

    mergeSort(arr , s , mid);
    mergeSort(arr, mid + 1 , e);

    merge(arr , s ,e);
}

void print(int *arr , int n){
    for (int i = 0; i < n; i++)
    {
    cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}


int main(){

    int arr[7] = {2 ,5 , 29 , 1 ,6 , 9 , 0};
    int n = 7;
    print(arr ,n);

    mergeSort(arr , 0 , n-1);
    print(arr, n);

    return 0;
}