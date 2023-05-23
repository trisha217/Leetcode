class KthLargest {
public:
    int k2;
    multiset<int> nums2;
    KthLargest(int k, vector<int>& nums) {
        k2=k;
        for(int& val:nums) nums2.insert(val); 
    }
    
    int add(int val) {
        nums2.insert(val);
        auto it=nums2.begin();advance(it,nums2.size()-k2);
        return *it;
    }
};