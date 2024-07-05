class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> dist;
        ListNode* temp = head;
        while(temp != NULL) {
            dist.push_back(temp -> val);
            temp = temp -> next;
        }
        vector<int> ans;

        for(int i=0;i<dist.size();i++) {
            if(i>0 && i<dist.size()-1) {
                if(dist[i] < dist[i-1] && dist[i] < dist[i+1]) {
                    ans.push_back(i+1);
                } else if(dist[i] > dist[i-1] && dist[i] > dist[i+1]) {
                    ans.push_back(i+1);
                }
            }
        }

        if(ans.size() < 2) {
            return {-1,-1};
        }

        sort(ans.begin(),ans.end());
        vector<int> aa;
        int maxDist = ans[ans.size()-1] - ans[0];
        int minDist = INT_MAX;
        for(int i=1;i<ans.size();i++) {
            minDist = min(minDist,ans[i]-ans[i-1]);
        }
        aa.push_back(minDist);
        aa.push_back(maxDist);

        return aa;
    }
};