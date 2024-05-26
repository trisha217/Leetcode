class Solution {
public:
    int checkRecord(int n) {

        const int64_t mod = 1e9 + 7;
        
        // possible states after current day that allow giving award:
        int64_t A0L0 = 1; // never Absent, previous was not Late
        int64_t A0L1 = 0; // never Absent, previous one was Late
        int64_t A0L2 = 0; // never Absent, previous two were Late
        int64_t A1L0 = 0; // once Absent, previous was not Late
        int64_t A1L1 = 0; // once Absent, previous one was Late
        int64_t A1L2 = 0; // once Absent, previous two were Late

        for (int i = 0; i < n; ++i) {

            // count the ways it is possible to get to the new state
            // A0L0 is possible with P after A0L0, A0L1, A0L2
            int64_t new_A0L0 = (A0L0 + A0L1 + A0L2) % mod;
            // A0L1 is possible only with L after A0L0
            int64_t new_A0L1 = A0L0;
            // A0L2 is possible only with L after A0L1
            int64_t new_A0L2 = A0L1;

            // A1L0 is possible with A after A0L0, A0L1, A0L2 and 
            // with P after A1L0, A1L1, A1L2
            int64_t new_A1L0 = (A1L0 + A1L1 + A1L2 + A0L0 + A0L1 + A0L2) % mod;
            // A1L1 is possible only with L after A1L0
            int64_t new_A1L1 = A1L0;
            // A1L2 is possible only with L after A1L1
            int64_t new_A1L2 = A1L1;

            // Update states after the day.
            // This code is simple, fast and readable, but
            // it can be made more complicated with less temporary
            // variables being used, but readability would be worse.
            A0L0 = new_A0L0;
            A0L1 = new_A0L1;
            A0L2 = new_A0L2;
            A1L0 = new_A1L0;
            A1L1 = new_A1L1;
            A1L2 = new_A1L2;
        }

        // sum up all possible states that allow giving award 
        return (A0L0 + A0L1 + A0L2 + A1L0 + A1L1 + A1L2) % mod;
    }
};