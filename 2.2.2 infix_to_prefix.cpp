// converte an infix expression to prefix.
// infix expression (a-b/c)*(a/k-l) | Expected Answer:- *-a/bc-/akl
#include "bits/stdc++.h"
#include<stack>
#include<algorithm>
using namespace std;
// checking precedence of operators
int prece(char s){
    if(s=='^'){return 3;}
    else if(s=='/'||s=='*'){return 2;}
    else if(s=='+'||s=='-'){return 1;}
    else{return -1;}
}
// function to convert infix to prefix
// approach is to reverse the given infix expression and interchaging opening and closing bracket of the resulting reversed string.
// then use stack to convert the infix expression and thus reversing the resulting expression to get the prefix expression.
string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' ){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
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
    while (!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    cout<<"Infix Expression=> (a-b/c)*(a/k-l)"<<endl;
    cout<<"Prefix Expression=> " + infixToPrefix("(a-b/c)*(a/k-l)") <<endl;
    return 0;
}