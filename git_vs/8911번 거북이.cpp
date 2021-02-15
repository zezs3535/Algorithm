#include <iostream>
#include <algorithm>

using namespace std;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 }; //0 ºÏ 1 µ¿ 2 ³² 3 ¼­
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	
	for (int t = 0; t < n; t++) {
		int maxy = -1000;
		int maxx = -1000;
		int miny = 1000;
		int minx = 1000;
		int cy = 0;
		int cx = 0;
		int dir = 0;
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			maxy = max(maxy, cy);
			maxx = max(maxx, cx);
			miny = min(miny, cy);
			minx = min(minx, cx);
			if (s[i] == 'F') {
				cy += dy[dir];
				cx += dx[dir];
			}
			else if (s[i] == 'B') {
				cy -= dy[dir];
				cx -= dx[dir];
			}
			else if (s[i] == 'L') {
				if (dir == 0)dir = 3;
				else {
					dir = ((dir - 1) % 4);
				}
			}
			else if (s[i] == 'R') {
				dir = (dir + 1) % 4;
			}
		}
		maxy = max(maxy, cy);
		maxx = max(maxx, cx);
		miny = min(miny, cy);
		minx = min(minx, cx);
		cout << (maxy - miny) * (maxx - minx)<<"\n";
	}
	return 0;
}