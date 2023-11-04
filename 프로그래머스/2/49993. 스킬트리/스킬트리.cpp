#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

queue<char> Q;
int tmp;
vector<int> V;
bool flag;

void findIdx(char a, string skill){
    tmp = -1;
    for(int k = 0; k < skill.size(); k++)
        if(a == skill[k])
            tmp = k;
    return ;
}

bool checkSkill(){
    cout << "flag : " << flag << "\n";
    if(V.empty()) return true;
    if(!flag) return false;
    for(int i=0; i<V.size()-1; i++){
        if(V[i] > V[i+1] || (V[i+1] - V[i] != 1)){
            cout << V[i] << ", " << V[i+1] << "\n";
            return false;
        }
    }
    cout << "catch\n";
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i<skill_trees.size(); i++){
        flag = false;
        while(!V.empty())
            V.pop_back();
        for(auto j : skill_trees[i]){
            findIdx(j, skill);
            
            if(tmp != -1){
                cout << tmp << " ";
                if(tmp == 0)
                    flag = true;
                V.push_back(tmp);   
            }
        }
        cout << "\n";
        if(checkSkill())
            answer++;
    }
    
    return answer;
}