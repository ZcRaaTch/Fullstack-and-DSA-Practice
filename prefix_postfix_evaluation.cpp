// evaluation of given prefix and postfix expressions using stack.
// prefix string:- -+7*45+20  | Answer=25
// postfix string:- 46+2/5*7+ | Answer=32
#include "bits/stdc++.h"
#include <stack>
#include <math.h>
using namespace std;
// function to evaluate prefix
int prefixEvaluation(string s){
    stack<int> st;
    // in prefix expression we traverse form the end of the string
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){         //checking if the char is operand
            st.push(s[i]-'0');
        }
        else{
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '/':
                st.push(operand1/operand2);
                break;
            case '^':
                st.push(pow(operand1,operand2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
// function to evaluate postfix
int postfixEvaluation(string s){
    stack<int> st;
    // in postfix expression we traverse form the start of the string
    for(int i=0;i<s.length();i++){
         if(s[i]>='0' && s[i]<='9'){         //checking if the char is operand
            st.push(s[i]-'0');
        }
        else{
            int operand2=st.top();
            st.pop();
            int operand1=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '/':
                st.push(operand1/operand2);
                break;
            case '^':
                st.push(pow(operand1,operand2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main(){
    cout<<"Answer to the given Prefix expression :- "<<prefixEvaluation("-+7*45+20")<<endl;
    cout<<"Answer to the given Postfix expression :- "<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}