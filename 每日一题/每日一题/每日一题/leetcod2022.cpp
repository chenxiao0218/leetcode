/*给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。
original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的
元素构成二维数组的第二行，依此类推。请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> res;
        if (m * n == size) {
            for (int i = 0; i < m; i++) {
                vector<int> help;
                for (int j = 0; j < n; j++) {
                    help.push_back(original[i * n + j]);
                }
                res.push_back(help);
                help.clear();
            }
        }
        return res;
    }
};