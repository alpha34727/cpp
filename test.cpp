#include <iostream>

#include <string>
using namespace std;

string s = "hello";
string s2(s); // 複製構造
string s3(10, 'a'); // 10個'a'

// 常用方法
s.push_back('!'); // 添加字符到末尾 - O(1)
s.pop_back(); // 刪除末尾字符 - O(1)
s.size(); // 獲取長度 - O(1)
s.length(); // 獲取長度 - O(1)
s.empty(); // 判斷是否為空 - O(1)
s.clear(); // 清空字串 - O(1)
s.substr(1, 3); // 獲取子字串 - O(n)
s.find("ll"); // 查找子字串 - O(n*m)
s += " world"; // 字串連接 - O(n)
s[i]; // 訪問字符 - O(1)
s.compare("hello"); // 比較字串 - O(n)
s.replace(1, 2, "aa"); // 替換子字串 - O(n)

// 數值轉換
int num = 123;
string s = to_string(num); // 數字轉字串
int n = stoi(s); // 字串轉整數
double d = stod(s); // 字串轉浮點數