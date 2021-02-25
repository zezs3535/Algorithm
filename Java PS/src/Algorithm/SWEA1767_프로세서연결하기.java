package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA1767_프로세서연결하기 {
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, -1, 0, 1 };
	static int idx;
	static int n;
	static int ansProCnt;
	static int ansLen;
	static Pos[] pro;

	static class Pos {
		int y;
		int x;

		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}

	static void dfs(int[][] arr, Pos[] pro, int proCnt, int proSel, int len) {
		if (proCnt == idx) { // 프로세서 다 탐색했을때
			if (ansProCnt <= proSel) {
				if (ansProCnt == proSel) {
					ansLen = Math.min(ansLen, len);
					return;
				}
				ansProCnt = proSel;
				ansLen = len;
				return;
			}
			return;
		}

		int cy = pro[proCnt].y;
		int cx = pro[proCnt].x;
		for (int dir = 0; dir < 4; dir++) {
			int cnt = 1; // 한칸씩 추가
			boolean flag = true; // 현재 dir로 전선을 놓을 수 있나?
			while (true) { // 현재 dir로 끝까지 탐색
				int ny = cy + dy[dir] * cnt;
				int nx = cx + dx[dir] * cnt;
				if (ny >= n || ny < 0 || nx >= n || nx < 0 || !flag) { // 끝에 도달했을때, 탐색이 불가할때
					if (cy == n - 1 || cy == 0 || cx == 0 || cx == n - 1) { // 원래 가에 있던거면 탐색 ㄴㄴ (밑에 입력에서 예외처리를 통해 해결)
						flag = false;
						break;
					}
					for (int i = 1; i < cnt; i++) {
						arr[cy + dy[dir] * i][cx + dx[dir] * i] = 2; // 탐색이 가능할때 벽에 닿으면 선을 연결
					}
					break;
				}
				if (arr[ny][nx] != 0) { // 프로세서가 있거나 이미 전선이 깔려있는경우
					flag = false;
					break;
				}
				cnt++;
			}
			if (flag) {
				dfs(arr, pro, proCnt + 1, proSel + 1, len + cnt - 1);
				for (int i = 1; i < cnt; i++) {
					arr[cy + dy[dir] * i][cx + dx[dir] * i] = 0; // 탐색 후 다시 돌려놓기
				}
			} else {
				dfs(arr, pro, proCnt + 1, proSel, len);
			}

		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			ansProCnt = 0;
			ansLen = Integer.MAX_VALUE;
			n = sc.nextInt();
			int[][] arr = new int[n][n];
			pro = new Pos[12];
			idx = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
					if (arr[i][j] == 1) {
						if(i==n-1 || i==0 || j==n-1 || j==0)continue; //이미 벽에 붙어있는것은 연결된거라 카운트 ㄴㄴ
						pro[idx] = new Pos(i, j);
						idx++;
					}
				}
			}
			dfs(arr, pro, 0, 0, 0);
			System.out.println("#" + test + " " + ansLen);
		}

	}

}
