/*����һ�� ��������������ͳ������������������ ������ ֮����ȣ����ǳ���Ϊ ������������
����һ�� ���� n�� ����������������� true�����򷵻� false*/

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