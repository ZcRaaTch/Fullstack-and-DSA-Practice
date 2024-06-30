// converte an infix expression to postfix.
// infix expression (a-b/c)*(a/k-l) | Expected Answer:- abc/-ak/l-*
#include "bits/stdc++.h"
#include<stack>
#include<unordered_map>
using namespace std;
// using unordered map to get the precedence of the operator.
int prece(char s){
    unordered_multimap<char, int> mp={
        {'^',3},{'/',2},{'*',2},{'+',1},{'-',1}
    };
    if(mp.count(s)!=0){
        auto i=mp.find(s);
        return i->second;
    }

    return -1;
}
string infixToPostfix(string s){
    stack<char> st;
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' ){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prece(st.top())>=prece(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    cout<<"Infix Expression=> (a-b/c)*(a/k-l)"<<endl;
    cout<<"Postfix Expression=> " + infixToPostfix("(a-b/c)*(a/k-l)") <<endl;
    return 0;
}