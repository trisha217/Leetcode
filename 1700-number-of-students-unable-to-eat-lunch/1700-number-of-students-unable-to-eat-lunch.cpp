class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int square =0;
        int circle = 0;
        for(auto it: students){
            if(it ==1){
                square++;
            }
            else{
                circle++;
            }
        }
        for(auto it: sandwiches){
            if(it==1){
                square--;
                if(square<0)
                    return circle;
            }
            else{
                circle--;
                if(circle<0)
                    return square;
            }     
        }
        return square+circle;
    }
};