// to reverse a given sentence using stack.
// given senetence "My name is Abhinav Awana".
// expected output "Awana Abhinav is name My".

#include"bits/stdc++.h"
#include<stack>

using namespace std;
string reverseStr(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        ans+=" ";
        st.pop();
    }
    return ans;
}

int main (){
    string s ="My name is Abhinav Awana";
    cout<<reverseStr(s)<<endl;

    return 0;
}