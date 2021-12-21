#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�*/

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