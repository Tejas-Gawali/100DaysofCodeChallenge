#include<iostream>
using namespace std ;

void print(int arr[]){
    
    for(int i =0; i< 26; i++){
        cout<<arr[i]<<" ";
    }
}

bool ifEqual(int a[] , int b[]){
        for(int i = 0 ; i< 26 ; i++){
            if(a[i]!=b[i]){
                
                return 0;
            } 
        }
        
        return 1;
}

bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i =0; i<s1.length() ; i++){
            int index = s1[i] - 'a';
            count1[index]++;
            
        }

        
        
        int i = 0;
        int window = s1.length();
        int count2[26] = {0};
        while(i<window){
            int index = s2[i] - 'a';
            count2[index]++;
            
            i++;
        }
        
        if(ifEqual(count1 , count2)){
                return 1;
        }
        
        
        while(i < s2.length()){
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;
            
            char oldchar = s2[i - window];
            index = oldchar - 'a';
            count2[index]--;
            
            i++;
            
            if(ifEqual(count1 , count2)){
                return 1;
            }
        }
        return 0;
}

int main(){
    string s1 =  "ab";
    string s2 =  "abeidbaooo";

    cout<<checkInclusion(s1,s2);

    

}