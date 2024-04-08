class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
     int circular = 0 , square = 0;
     for( auto it : students){
        if(it) square++;
        else circular++;
     }   
     for(auto it : sandwiches){
        if(it){
            square--;
            if(square<0) return circular;
        }
        else{
            circular--;
            if(circular < 0) return square;
        }
     }
     return circular + square;
    }
};
