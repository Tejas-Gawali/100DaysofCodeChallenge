#include<iostream>
using namespace std;



char getMAxChar(string s){
    int arr[26] = {0};

    for(int i = 0; i<s.length() ; i++){
        if(s[i]>='a' || s[i]<='z'){
            arr[(s[i] - 'a')]++;
        }
        else{
            arr[(s[i] - 'A')]++;
        }
    }

    int maximum = -1;
    int ans = 0;
    for(int i = 0; i<26; i++){
        if(maximum< arr[i]){
            maximum = arr[i];
            ans=i;
        }
    }

    return ans + 'a';
    
}

int main(){

    string s = "abDeDe";
    cout<<getMAxChar(s);

}