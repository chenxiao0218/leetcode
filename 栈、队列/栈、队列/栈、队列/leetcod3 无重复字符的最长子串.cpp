#include<iostream>
#include<deque>
#include<string>
using namespace std;

/*����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�*/
//�ⷨ1 �������ڣ�����û�õ�����
class Solution3 {
public:
    bool Isexit(string s, int l, int r, char c) {
        for (int i = l;  i < r; i++) {
            if (s[i] == c) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int fast = 0, slow = 0;
        int res = 0;
        if(s.empty()) {}
        else {
            while (++fast < s.size()) {
                while (Isexit(s, slow, fast, s[fast])) {
                    slow++;
              }
                res = max(res, fast - slow);

            }
        }
        return res;
    }
};

//�ⷨ2 ʹ�ö��еĻ�������

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }
};