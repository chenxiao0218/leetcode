#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

/*给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

//搞两个栈，一个保存数字，一个保存字符和[]
class Solution394 {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> st;
        string res = "";
        int val = 0;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                val = val * 10 + s[i] - '0';
            }
            //这里的res其实保留的时临时的值，即【到下一个【之间的字符
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                res = res + s[i];
            }
            //当遇到【时，说明【左边的东西在外层，数字需要最后运算，字符需要之后加上，因此先压栈
            else if (s[i] == '[') {
                num.push(val);
                st.push(res);
                cout << "val=" << val << endl;
                cout << "res=" << res << endl;
                val = 0;
                res = "";

            }
            //当遇到】时，要将【】内的字符进行数字的解密运算，即增加num.top()倍的字符
            else {
                int k = num.top();
                num.pop();
                for (int j = 0; j < k; j++) {
                    st.top() = st.top() + res;
                }
                res = st.top();
                st.pop();
            }
        }
        return res;
    }
};

void test394() {
    string s = "abcd";
    cout << s[2] << endl;
}

int main() {
    test394();

    system("pause");
    return 0;
}

