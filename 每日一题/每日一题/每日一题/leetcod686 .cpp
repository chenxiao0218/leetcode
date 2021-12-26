#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool Isexit(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;
        while (j<n2&&b[j] != a[0]) j++;
        if (j == n2) return false;
        while (j < n2 && i < n1) {
            if (b[j++] != a[i++]) return false;
        }
        if (i != n1) return false;
        return true;
    }
    int repeatedStringMatch(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0, j = 0;
        int flag = 1;
        while (i < n1 && a[i] != b[0]) i++;
        cout << "a=" << a[i] << endl;
        if (i== n1) return -1;
        while (j<n2) {
            if (i == n1) { i = 0; flag++; }
            if (b[j] != a[i]) return -1;
            i++; j++;

        }
        if (i != n1) return flag;
    }
};

void test01() {
    Solution fun;
    string a = "abcd";
    string b = "cdabcdab";
    cout << fun.repeatedStringMatch(a, b) << endl;
}

int main() {
    test01();

    system("pause");
    return 0;
}