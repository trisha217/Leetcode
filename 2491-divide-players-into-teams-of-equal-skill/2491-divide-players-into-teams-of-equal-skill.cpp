class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());

        int i = 0, j = n - 1;
        int teamSum = skill[i] + skill[j];
        int mul = skill[i] * skill[j];
        i++;
        j--;

        long long chemistry = 0;
        chemistry += mul;

        while(i < j){
            int sum = skill[i] + skill[j];
            if(sum != teamSum)return -1;

            mul = skill[i] * skill[j];
            chemistry += mul;  
            i++;
            j--;
        }
        return chemistry;
    }
};