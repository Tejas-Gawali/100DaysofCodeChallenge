#include<iostream>
using namespace std;

bool valid(char ch){
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
            cout<<ch;
            return 1;
            
        }
        return 0;
    }
    
    char lower(char ch){
        if((ch>='a' && ch<='z') || (ch<='0' && ch>='9') ){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool ifPali(string a){
        int s =0;
        int e = a.length()-1;
        while(s<=e){
            if(a[s]!=a[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    
    bool Palindrome(string s) {
        string temp = "";
        for(int i = 0; i<s.length() ; i++){
            if(valid(s[i])){
                temp.push_back(lower(s[i]));
            }
        }
        
       return ifPali(temp);
    }

int main(){

    


    string s = "A man, a plan, a canal: Panama";
    
    cout<<Palindrome("0P");
    
    
}
