#include<iostream>
#include<deque>
#include<string>
using namespace std;

/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。*/
//解法1 滑动窗口，但是没用到队列
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

//解法2 使用队列的滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }
};