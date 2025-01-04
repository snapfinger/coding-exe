#include "../common_headers.h"

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int cnt = 0;
    int i = 0;
    while(i < nums.size()){
        int cur_len = 1;
        for(int j = 0;  j < k - 1 && i + j + 1 < nums.size(); j++){
            if(nums[i + j + 1] > nums[i + j]){
                cur_len += 1;
                if(cur_len == k){
                    cnt = 1;
                    break;
                }
            }else{
                break;
            }
        }
        
        if(cnt == 1){
            for(int j = 0;  j < k - 1; j++){
                if(nums[i + j + 1] > nums[i + j]){
                    cur_len += 1;
                    if(cur_len == k) return true;
                }
            }    
        }else{
            i += 1;     
        }
        
        
    }
    
    return false;
}


int main(){
    vector<int> test1 = {2,5,7,8,9,2,3,4,3,1};
    int k1 = 3;
    cout << hasIncreasingSubarrays(test1, k1) << endl;

}