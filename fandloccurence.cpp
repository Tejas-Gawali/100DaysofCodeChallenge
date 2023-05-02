#include<iostream>
using namespace std;

int fOcc(int arr[], int n , int key){
    int s = 0 , e = n-1 ;
    int mid = (s+e/2);
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid -1;
        }

        else if(arr[mid] < key){
            s = mid + 1 ;
        }
        else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

int main(){

        int odd[6] = {1,2,3,3,4,5};
        int a= fOcc(odd , 6 ,3);
        cout<<a;

}