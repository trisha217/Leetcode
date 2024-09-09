/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n, vector<int> (m, -1));
        ListNode* temp = head;
        int t = 0, l = 0, b = n-1, r = m-1;
        while(1)
        {
            for(int i=l;i<=r;i++)
            {
                res[t][i] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            t++;
            if(temp == NULL)
                break;
            
            for(int i = t;i<=b;i++)
            {
                res[i][r] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            r--;
            if(temp == NULL)
                break;
            
            for(int i = r;i>=l;i--)
            {
                res[b][i] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            b--;
            if(temp == NULL)
                break;
            
            for(int i = b;i>=t;i--)
            {
                res[i][l] = temp->val;
                temp = temp->next;
                if(temp == NULL)
                    break;
            }
            l++;
            if(temp == NULL)
                break;
        }
        return res;
    }
};