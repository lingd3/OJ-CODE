class Solution {
public:
    int myAtoi(string str) {
    if (str.size() == 0) return 0;
	int t = 0;
	char str1[100] ={'\0'}, str2[100] = {'\0'};
	for (int i = 0, j = 0; i < str.size(); i++) {
		if (str[i] == ' ' && t == 0) continue;
		else {
			str2[j] = str[i];
			j++;
			t = 1;
		}
	}
	str1[0] = str2[0];
	str1[1] = str2[1];
	if (str1[0] >= 'a' && str1[0] <= 'z') return 0;
	if (str1[1] < '0' || str1[1] > '9') {
		if (str1[0] < '0' || str1[0] > '9') return 0;
		else {
			int sum = str1[0]-'0';
			return sum;
		}
	}
	for (int i = 2, j = 2; str2[i] != '\0'; i++) {
		if (str2[i] >= '0' && str2[i] <= '9') {
			str1[j] = str2[i];
			j++;
		}
		else break;
	}
	int d = 0;
	for (int i = 0; str1[i] != '\0'; i++) d++;
	for (int i = 0; i < d; i++) {
		if (str1[i] == ' ') return 0;
	}
	for (int i = 1; i < d; i++) {
		if (str1[i] < '0' || str1[i] > '9') return 0;
	}
	if (str1[0] == '+') {
	    if (d > 11) return 2147483647;
		int sum = str1[d-1]-'0', i, k = 1;
        for (i = d-2; i > 0; i--) {
        	k *= 10;
          	if (2147483648/100.0-sum/100.0 <= (str1[i]-'0')*k/100.0) return 2147483647;
          	else sum += (str1[i]-'0')*k;
        }
        return sum;
	}
	else if (str1[0] == '-') {
	    if (d > 11) return -2147483648;
		int sum = str1[d-1]-'0', i, k = 1;
        for (i = d-2; i > 0; i--) {
        	k *= 10;
        	if (2147483648/100.0-sum/100.0 <= (str1[i]-'0')*k/100.0) return -2147483648;
          	else sum += (str1[i]-'0')*k;
        }
        return -1*sum;
	}
	else if (str1[0] < '0' || str[0] > '9') return 0;
	else {
		int sum = str1[d-1]-'0', i, k = 1;
		if (d >= 11) return 2147483647;
        for (i = d-2; i >= 0; i--) {
        	k *= 10;
        	if (2147483648/100.0-sum/100.0 <= (str1[i]-'0')*k/100.0) return 2147483647;
          	else sum += (str1[i]-'0')*k;
        }
        return sum;
	}
    }
};
