class Solution {
public:
    static bool canSortArray(const vector<int> &nums) {
        uint16_t pmax = 0, cmin = 0, cmax = 0;
        uint8_t pcnt = 0;

        for (const uint16_t v : nums) {
            const uint8_t ccnt = count_bits(v);

            if (pcnt == ccnt) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }

        return cmin >= pmax;
    }

    static uint8_t count_bits(uint16_t num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
};