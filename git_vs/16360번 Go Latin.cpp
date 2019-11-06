#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s[s.length() - 1] == 'i') {
			s.append("os");
		}
		else if (s[s.length() - 1] == 'a') {
			s.append("s");
		}
		else if (s[s.length() - 1] == 'l') {
			s.append("es");
		}
		else if (s[s.length() - 1] == 'y') {
			s.pop_back();
			s.append("ios");
		}
		else if (s[s.length() - 1] == 'n') {
			s.pop_back();
			s.append("anes");
		}
		else if (s[s.length() - 1] == 'e' && s[s.length()-2]=='n') 
		{
			s.pop_back();
			s.pop_back();
			s.append("anes");
		}
		else if (s[s.length() - 1] == 'o') {
			s.append("s");
		}
		else if (s[s.length() - 1] == 'r') {
			s.append("es");
		}
		else if (s[s.length() - 1] == 't') {
			s.append("as");
		}
		else if (s[s.length() - 1] == 'u') {
			s.append("s");
		}
		else if (s[s.length() - 1] == 'v') {
			s.append("es");
		}
		else if (s[s.length() - 1] == 'w') {
			s.append("as");
		}
		else {
			s.append("us");
		}
		cout << s <<"\n";
	}
	return 0;
}