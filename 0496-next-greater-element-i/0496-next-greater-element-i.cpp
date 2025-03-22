class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int i=0; i<nums2.size(); i++){
            map[nums2[i]] = i;
        }

        for(int i=0; i<nums1.size(); i++){
            int k = map[nums1[i]]+1;
            int el = -1;
            for(; k<nums2.size(); k++){
                if(nums2[k] > nums1[i]){
                    el = nums2[k];
                    break;
                }
            }
            nums1[i] = el;
        }
        return nums1;
    }
};