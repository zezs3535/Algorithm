package Algorithm;

import java.util.Scanner;

public class BOJ21608_상어초등학교 {

	static int[][] arr; // 배열
	static int[][] favorite; // 좋아하는 학생
	static int[] order;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, -1, 0, 1 };
	static int n;
	static Scanner sc;

	static class FavorEmptyInfo {
		int favoriteCnt = 0;
		int emptyCnt = 0;
	}

	public static void main(String[] args) throws Exception {
		sc = new Scanner(System.in);
		n = sc.nextInt();
		order = new int[n*n];
		arr = new int[n][n];
		favorite = new int[n * n + 1][4];

		getFavoriteStudents();

		
		int pickY = -1;
		int pickX = -1;
		FavorEmptyInfo tmp;
		FavorEmptyInfo pickInfo;
		for(int pickIdx=0;pickIdx<n*n;pickIdx++) { // 1~n*n까지의 학생 순서
			pickInfo = new FavorEmptyInfo();	//현재 순번의 학생의 주변에 (좋아하는 학생, 비어있는 자리) 정보
			tmp = new FavorEmptyInfo();
			pickY = -1;
			pickX = -1;
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if(arr[i][j]!=0)continue;
					tmp = searchFavorite(i,j, order[pickIdx]); //현재 위치에서 좋아하는 학생, 비어있는 자리 정보
					if(pickInfo.favoriteCnt<tmp.favoriteCnt) { //주변에 좋아하는 학생의 수가 더 많으면
						pickInfo.favoriteCnt = tmp.favoriteCnt;
						pickInfo.emptyCnt = tmp.emptyCnt;
						pickY = i;
						pickX = j;
						continue;
					}
					else if(pickInfo.favoriteCnt==tmp.favoriteCnt) { //주변에 좋아하는 학생의 수가 같으면
						if(pickInfo.emptyCnt<tmp.emptyCnt) { //주변에 비어있는 자리가 더 많으면
							pickInfo.emptyCnt = tmp.emptyCnt;
							pickY = i;
							pickX = j;
						}
						else if(pickInfo.emptyCnt == tmp.emptyCnt) {
							pickY=i;
							pickX=j;
						}
					}
				}
			}
			arr[pickY][pickX] = order[pickIdx];
		}
		System.out.println(calcArr());
	}

	public static void getFavoriteStudents() { // 좋아하는 학생 입력받기
		int student = 0;
		for (int i = 0; i < n * n; i++) {
			student = sc.nextInt();
			order[i] = student;
			for (int j = 0; j < 4; j++) {
				favorite[student][j] = sc.nextInt();
			}
		}
	}

	public static FavorEmptyInfo searchFavorite(int y, int x, int pickIdx) {
		FavorEmptyInfo cnt = new FavorEmptyInfo();
		int ny = 0;
		int nx = 0;
		for (int dir = 0; dir < 4; dir++) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny >= n || ny < 0 || nx >= n || nx < 0)
				continue; // 범위를 나갈때
			if (arr[ny][nx] == 0) {
				cnt.emptyCnt++;
				continue;
			}
			for (int i = 0; i < 4; i++) {
				if (favorite[pickIdx][i] == arr[ny][nx]) {
					cnt.favoriteCnt++;
					break;
				}
			}
		}

		return cnt;
	}
	
	public static int calcArr() {
		int ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int cnt = 0;
				for(int dir=0;dir<4;dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny >= n || ny < 0 || nx >= n || nx < 0)
						continue; // 범위를 나갈때
					for(int idx=0;idx<4;idx++) {
						if(favorite[arr[i][j]][idx]==arr[ny][nx]) {
							cnt++;
							break;
						}
					}
				}
				if(cnt==0)ans+=0;
				else if(cnt==1)ans+=1;
				else if(cnt==2)ans+=10;
				else if(cnt==3)ans+=100;
				else if(cnt==4)ans+=1000;
			}
		}
		return ans;
	}
}
