#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。*/

class Solution20 {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[') mystack.push(i);
            else {
                if (mystack.empty()) return false;
                switch (mystack.top()) {
                case '(':
                    if (i == ')') {
                        mystack.pop();
                        break;
                    }
                    return false;
                case '[':
                    if (i == ']') {
                        mystack.pop();
                        break;
                    }
                    return false;
                case '{':
                    if (i == '}') {
                        mystack.pop();
                        break;
                    }
                    return false;
                default:
                    return false;
                }
            }
        }
        if (mystack.empty()) return true;
        return false;
    }
};