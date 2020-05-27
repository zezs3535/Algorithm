#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> record;
	map<string, string> user;
	vector<pair<string, string>> ins;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");
	for (int i = 0; i < record.size(); i++) {
		int idx = 0;
		string id = "", name = "";
		if (record[i][0] == 'E') {
			idx = 6;
			for (int j = idx; j < record[i].size(); j++, idx++) {
				if (record[i][j] == ' ')break;
				id += record[i][j];
			}
			for (int j = idx + 1; j < record[i].size(); j++) {
				name += record[i][j];
			}
			user[id] = name;
			ins.push_back({ "Enter",id });
		}
		else if (record[i][0] == 'L') {
			idx = 6;
			for (int j = idx; j < record[i].size(); j++, idx++) {
				if (record[i][j] == ' ')break;
				id += record[i][j];
			}
			ins.push_back({ "Leave", id });
		}
		else {
			idx = 7;
			for (int j = idx; j < record[i].size(); j++, idx++) {
				if (record[i][j] == ' ')break;
				id += record[i][j];
			}
			for (int j = idx + 1; j < record[i].size(); j++) {
				name += record[i][j];
			}
			user[id] = name;
		}
	}
	//ins.first = 명령어, ins.second = 유저 아이디
	for (int i = 0; i < ins.size(); i++) {

		//cout << ins[i].first << " " << user[ins[i].second]<<endl;
		if (ins[i].first == "Enter") {
			cout << user[ins[i].second] << "님이 들어왔습니다.";
		}
		else {
			cout << user[ins[i].second] << "님이 나갔습니다.";
		}
	}
	return 0;
}
