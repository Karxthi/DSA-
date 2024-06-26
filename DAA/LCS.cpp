#include <iostream>
#include <string>
using namespace std;
int LCS(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];//m+1 n+1
    for (int i = 0; i <m+1; i++) {// 1 T m+1
        dp[i][0] = 0;
    }
    for (int j = 0; j <n+1; j++) {//1 to n+1
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
string str1 = "ABCBDAB";
string str2 = "BDCABB";
int lcsLength = LCS(str1, str2);
cout << "Length of LCS: " << lcsLength << endl;
return 0;
}