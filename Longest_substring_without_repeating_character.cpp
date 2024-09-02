#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int right = 0,left = 0;
        unordered_map<char,int> m;
        while(right < n)
        {
            if(m.find(s[right]) != m.end())
                left = max(left, m[s[right]] + 1); // if any char repeated then move left pointer
 
            m[s[right]] = right; // putting the index where last time it appears
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution solution;
    int maxLength = solution.lengthOfLongestSubstring(s);

    cout << "Length of the longest substring without repeating characters: " << maxLength << endl;
    return 0;
}