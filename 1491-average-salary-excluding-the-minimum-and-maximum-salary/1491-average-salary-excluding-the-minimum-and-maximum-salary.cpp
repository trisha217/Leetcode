class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        for(int i=0;i<salary.size();i++){
            sum = sum + salary[i];
        }
        int n = salary.size() - 2;
        double maxi = *max_element(salary.begin(), salary.end());
        double mini = *min_element(salary.begin(), salary.end());
        sum = sum - ( maxi + mini);
        double avg = sum/n;
        return avg;
    }
};