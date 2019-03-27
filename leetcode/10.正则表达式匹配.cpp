/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (21.06%)
 * Total Accepted:    9.6K
 * Total Submissions: 45.8K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的元素。
 * 
 * 
 * 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */
class Solution {
public:
    /*
    // 递归
    bool isMatch(string s, string p) {
        return Helper(s, s.length() - 1, p, p.length() - 1);
    }
    bool Helper(string s, int s_index, string p, int p_index) {
        if (p_index < 0) {
            if (s_index < 0) return true;
            else return false;
        }
        if (p[p_index] == '*') {
            if (s_index >= 0 && (p[p_index - 1] == s[s_index] || p[p_index - 1] == '.'))
                if (Helper(s, s_index - 1, p, p_index)) return true;
            return Helper(s, s_index, p, p_index - 2);
        } else if (s_index >= 0) {
            if (p[p_index] == s[s_index] || p[p_index] == '.') 
                return Helper(s, s_index - 1, p, p_index - 1);
        }
        return false;
    }
    */

    // DP
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < p.length() + 1; i++) 
            dp[0][i] = i > 1 && p[i - 1] == '*' && dp[0][i-2];
        
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 1; j < p.length() + 1; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = (dp[i][j - 2]) || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));                  
                } else {
                    dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }

        return dp[s.length()][p.length()];
    }
};

