class Solution {
    public int minSwapsCouples(int[] row) {
        int[] pos = new int[row.length];
	for (int i = 0; i < row.length; i++)
		pos[row[i]] = i;

	int res = 0;
	for (int i = 0; i < row.length; i += 2) {
		int j = row[i] % 2 == 0 ? (row[i] + 1) : (row[i] - 1); 
		if (row[i + 1] != j) {
			row[pos[j]] = row[i + 1];
			pos[row[i + 1]] = pos[j];
			res++;
		}
	}
	return res;
    }
}