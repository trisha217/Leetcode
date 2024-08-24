class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length() ;
        if(len==1) return to_string(stoi(n)-1 ) ;

        vector<long long> cases ;
        // 1.greatest number just one digit less, e.g: case when 999 is nearest pallindrome to 1000
        cases.push_back(pow(10, len-1)-1 );  
        // 2.biggest number just one digit greater, e.g: case when 1001 is nearest pallindrome to 999
        cases.push_back(pow(10, len)+1 );   

        // pallindrome using first half of n
        long long prefix = stoll(n.substr(0, (len+1)/2 )) ;
        // taking other nearest pallindromes
        for(int i=-1; i<=1; i++ ){
            string p = to_string(prefix+i );
            // adding the current prefix with the reverse of same i.e pallindrome
            string candidate = p+ string(p.rbegin()+(len%2) , p.rend() );
            cases.push_back(stoll(candidate ));
        }
        long long num = stoll(n), closest = -1 ;
        // iterating all the cases and finding the minimal absolute diff closest num.

        for(long long curr: cases ){
            if(curr == num ) continue ;
            if(closest == -1 ||  abs(curr-num) < abs(closest-num ) || 
                abs(curr-num)==abs(closest-num) && curr<closest  ){
                    closest = curr;
                }
        }
        return to_string(closest );


    }
};