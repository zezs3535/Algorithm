#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    string expression = "100-200*300-500+20";
    int order[6][3] = { {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0} }; //+ - *의 연산순서
    char operands[3] = { '+','-','*' };
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            tmp += expression[i];
        }
        else {
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
            op.push_back(expression[i]);
        }
    }
    num.push_back(atoi(tmp.c_str()));
    for (int i = 0; i < 6; i++) {
        vector<long long> numtmp = num;
        vector<char> optmp = op;
        for (int j = 0; j < 3; j++) {
            vector<long long> stNum;
            vector<char> stOp;
            stNum.push_back(numtmp[0]);
            for (int k = 0; k < optmp.size(); k++) {
                stNum.push_back(numtmp[k + 1]);
                stOp.push_back(optmp[k]);
                if (stOp.back() == operands[order[i][j]]) { //현재 연산해야하는 순서일때
                    long long num1 = stNum.back();
                    stNum.pop_back();
                    long long num2 = stNum.back();
                    stNum.pop_back();
                    char curOp = stOp.back();
                    stOp.pop_back();
                    if (curOp == '*')stNum.push_back(num2 * num1);
                    else if (curOp == '-')stNum.push_back(num2 - num1);
                    else if (curOp == '+')stNum.push_back(num2 + num1);
                }
            }
            numtmp = stNum;
            optmp = stOp;
        }
        answer = max(answer, abs(numtmp[0]));
    }
    cout << answer;
    return 0;
}