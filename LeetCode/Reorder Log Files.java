public String[] reorderLogFiles(String[] logs) {
    List<String> digit_logs = new ArrayList<>();
    List<String> letter_logs = new ArrayList<>();
	for (String log : logs) {
		String s = log.substring(log.indexOf(' ')+1);
		if (s.charAt(0) >= '0' && s.charAt(0) <= '9') digit_logs.add(log);
		else letter_logs.add(log);
	}
    letter_logs.sort(new Comparator<String>() {

		@Override
		public int compare(String log1, String log2) {
			String l1 = log1.substring(log1.indexOf(' ')+1);
			String l2 = log2.substring(log2.indexOf(' ')+1);
			return l1.compareTo(l2);
		}
	});
	String[] rtn = new String[logs.length];
	int len = 0;
	for (int i = 0; i < letter_logs.size(); i++) {
		rtn[len++] = letter_logs.get(i);
	}
	for (int i = 0; i < digit_logs.size(); i++) {
		rtn[len++] = digit_logs.get(i);
	}
	return rtn;
}