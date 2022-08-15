class Solution {
    public static int romanToInt(String s) {
	if (s == null || s.length() == 0)
		return -1;
	HashMap<Character, Integer> rti = new HashMap<Character, Integer>();
	rti.put('I', 1);
	rti.put('V', 5);
	rti.put('X', 10);
	rti.put('L', 50);
	rti.put('C', 100);
	rti.put('D', 500);
	rti.put('M', 1000);
	int len = s.length(), result = rti.get(s.charAt(len - 1));
	for (int i = len - 2; i >= 0; i--) {
		if (rti.get(s.charAt(i)) >= rti.get(s.charAt(i + 1)))
			result += rti.get(s.charAt(i));
		else
			result -= rti.get(s.charAt(i));
	}
	return result;
    }
}