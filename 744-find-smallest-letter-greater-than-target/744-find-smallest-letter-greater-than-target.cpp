class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int start =0;
        int end = letters.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(letters[mid]>target){
                ans = letters[mid];
                end = mid-1;
            }
            else if(letters[mid]<=target){
                start = mid+1;
            }
        }
        return ans;
    }
};