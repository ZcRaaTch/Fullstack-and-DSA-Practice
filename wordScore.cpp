#include "bits/stdc++.h"
using namespace std;

int findScore(string str,char c){
    int wordCount=0;
    int score=0,defaultScore=2;
    bool flag=false;
    for(auto ch:str){
        if(isspace(ch)){
            if(flag) flag=false;
        }else{
            if(!flag){
                flag=true;
                if(ch=='s' or ch=='S') {wordCount++;}
                else{
                    wordCount=0;
                    break;
                }
            }
        }
    }
    if(wordCount>=3){
        score=2+(wordCount-3)*2;
    }
    
    return score;
}
int main(){
    string str = "She sells she shells shelly";
    cout<<findScore(str,'s');
    return 0;
}