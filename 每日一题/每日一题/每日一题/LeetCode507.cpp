/*对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
给定一个 整数 n， 如果是完美数，返回 true，否则返回 false*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        double n = sqrt(num);
        if (num == 1) return false;
        int sum = 1;
        for (int i = 2; i < n; i++) {
            if (num % i == 0) sum += i;
        }
        if (num % (int)n == 0) sum += (int)n;
        if (sum == num) return true;
        return false;
    }
};