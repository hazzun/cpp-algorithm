#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int checkInclude(int k, string word, vector<string> words){
    for(int i=0; i<words.size(); i++)
        if(words[i] == word && k < i) 
            return i;
    return 0;
}

vector<int> solution(int n, vector<string> words) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int turn = 1;
    vector<int> answer;
    int tmp = 100;
    
    for(int i=1; i< words.size(); i++){
        
        char beforeEndWord = words[i-1][words[i-1].length()-1];
        char nextStartWorld = words[i][0];
        
        if(i % n == 0)
            turn++;
        if(beforeEndWord != nextStartWorld){
            cout << i << ", "<< turn << "\n";
            if(tmp > i){
            answer.push_back(i - ((turn - 1) * n - 1)); 
            answer.push_back(turn);}
            break;
        }
        int res = checkInclude(i-1, words[i-1], words);
        if(res > 0){
            tmp = min(tmp, res);
            // answer.push_back(res - ((res / n) * n) + 1); 
            // answer.push_back(res / n + 1);
            // break;
            cout <<"tmp : "<< tmp << "\n";
        }
    }
    if(answer.empty() && tmp != 100){
        answer.push_back(tmp - ((tmp / n) * n) + 1); 
        answer.push_back(tmp / n + 1);
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}