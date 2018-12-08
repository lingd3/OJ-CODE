public int numUniqueEmails(String[] emails) {
        Set<String> strs = new HashSet<>();
        for (String s : emails) {
        	int index = s.indexOf('@');
        	StringBuilder sb = new StringBuilder();
        	for (int i = 0; i < index; i++) {
        		char c = s.charAt(i);
        		if (c == '.') continue;
        		if (c == '+') break;
        		sb.append(c + "");
        	}
        	sb.append(s.substring(index));
        	strs.add(sb.toString());
        }
		return strs.size();
    }