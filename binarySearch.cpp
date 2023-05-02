#include<iostream>
using namespace std;

int binarySearch(int arr[], int size , int key){
    int start = 0;
    int end = size -1;
    int mid = (start+end)/2;

    while(start<=end){

        if(arr[mid]==key){
            return mid;
        }

        else if(arr[mid]<key){
            start= mid+1;
        }
        else{
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int main(){

    int odd[5] = {1,4,8,9,23};
    int even[6]= {3,5,11,19,25,43};

    int ans =binarySearch(even , 6 ,43);
    cout<<ans;



}