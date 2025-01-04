#include "../common_headers.h"


// sliding window
// TC: O(n)
// SC: O(k)
int lengthOfLongestSubstringKDistinct(string s, int k) {
        int rst = 0, left = 0;
        unordered_map<char, int> map;
        for(int right = 0; right < s.size(); right++){
            ++map[s[right]];
            while(map.size() > k){
                map[s[left]]--;
                if(map[s[left]] == 0){
                    map.erase(s[left]);
                }
                ++left;
            }
            rst = max(rst, right - left + 1);
            
        }
        return rst;
    }


int main(){
    string s1 = "eceba";
    int k1 = 2;
    cout << lengthOfLongestSubstringKDistinct(s1, k1) << endl;

}