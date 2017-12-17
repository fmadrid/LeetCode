#include <string>
#include <cstring>
#include<iostream>
#include <algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
		int len = s.length();
		
		vector<char> cArr(len);
		for(int i = 0; i < len; i++)
			cArr[i] = s[i];
		
		
		vector<int> lastSeen(26, -1);
		
		int score = 0;
		for(int i = 0; i < len; i++) {
			
			char c = cArr[i];
			cout << "Checking: " << c << "\n";
			if(lastSeen[c - 'a'] == -1) {
				cout << c << " never seen.\n";
				score++;
				lastSeen[c - 'a'] = i;
			} else {
				cout << c << " last seen at " << lastSeen[c-'a'] << "\n";;
				lastSeen[c-'a'] = i;
				
				cout << "\tLastSeen: ";
				for(int n : lastSeen)
					cout << n << " ";
				for(int j = 0; j < 26; j++) {
					
					if(lastSeen[j] == -1) score = i;
					else score = (score >= i - lastSeen[j]) ? score : i - lastSeen[j];
				}
			}
			
			cout << "Current Score: " << score << "\n\n";
		}
		
		return score;
		
    }
};

int main() {
	
	Solution s;
	string str = "abcabcbb";
	cout << s.lengthOfLongestSubstring(str);
	
	return 0;
	
}