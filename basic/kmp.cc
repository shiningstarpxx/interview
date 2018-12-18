#include <vector>
#include <string>
#include <assert.h>

using namespace std;

void CalcLps(const string& pattern, vector<int>* lps) {
	assert(lps != NULL && lps->size() == pattern.length());
	int len = 0;
	(*lps)[0] = 0;

	for (int i = 1; i < pattern.length(); ) {
		if (pattern[i] == pattern[len]) {
			len++;
			(*lps)[len] = len;
			++i;
		} else {
			if (len != 0) {
				len = (*lps)[len - 1];
			} else {
				(*lps)[i] = 0;
				++i;
			}
		}
	}
}

void StrPattern(const string& origin, const string& pattern) {
	vector<int> lps(pattern.size(), 0);

	CalcLps(pattern, &lps);

	for (int i = 0, j = 0; i < origin.size(); ) {
		
		if (origin[i] == pattern[j]) {
			++i;
			++j;
			if (j >= pattern.size()) {
				printf("the pattern find at index %d\n", i - j);
				j = lps[j - 1];
			}
		} else {
			if (j != 0) {
				j = lps[j-1];
			} else {
				++i;
			}
		}
	}
}

int main() {
	string source = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";
	StrPattern(source, pattern);
	return 0;
}
