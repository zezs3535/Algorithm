package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ15683_감시 {
	static int n, m;
	static int ans = 100;
	static int[][] cctv1 = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }; // x,y
	static int[][] cctv2 = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
	static int[][] cctv3 = { { 0, -1, 1, 0 }, { 1, 0, 0, 1 }, { 0, 1, -1, 0 }, { -1, 0, 0, -1 } };
	static int[][] cctv4 = { { -1, 0, 0, -1, 1, 0 }, { 0, -1, 1, 0, 0, 1 }, { 1, 0, 0, 1, -1, 0 },
			{ 0, 1, -1, 0, 0, -1 } };
	static int[][] cctv5 = { { -1, 0, 1, 0, 0, 1, 0, -1 } };
	static Pos[] cctv;
	static int cctvCnt;
	static class Pos{
		int y;
		int x;
		int type;
		public Pos(int y, int x, int type) {
			super();
			this.y = y;
			this.x = x;
			this.type = type;
		}
		
	}
	static boolean check(int y, int x) {
		return (y >= n) || (y < 0) || (x >= m) || (x < 0);
	}

	static void copyArr(int[][] arr, int[][] tmp) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
	}

	static void copyArrB(boolean[][] arr, boolean[][] tmp) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
	}

	static void solve(int[][] arr, int cctvidx) {
		if(cctvCnt==cctvidx) {
			int zerocnt=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(arr[i][j]==0)zerocnt++;
				}
			}
			ans=Math.min(ans, zerocnt);
			return;
		}
		int y = cctv[cctvidx].y;
		int x = cctv[cctvidx].x;
		int type = cctv[cctvidx].type;
		if (type == 1) {
			for (int idx = 0; idx < 4; idx++) {
				int[][] tmp = new int[n][m];
				copyArr(arr, tmp);
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv1[idx][0] * cnt;
					int ny = y + cctv1[idx][1] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				solve(tmp,cctvidx+1);
			}
		} else if (type == 2) {
			for (int idx = 0; idx < 2; idx++) {
				int[][] tmp = new int[n][m];
				copyArr(arr, tmp);
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv2[idx][0] * cnt;
					int ny = y + cctv2[idx][1] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv2[idx][2] * cnt;
					int ny = y + cctv2[idx][3] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				solve(tmp,cctvidx+1);
			}
		} else if (type == 3) {
			for (int idx = 0; idx < 4; idx++) {
				int[][] tmp = new int[n][m];
				copyArr(arr, tmp);
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv3[idx][0] * cnt;
					int ny = y + cctv3[idx][1] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv3[idx][2] * cnt;
					int ny = y + cctv3[idx][3] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				solve(tmp,cctvidx+1);
			}
		} else if (type == 4) {
			for (int idx = 0; idx < 4; idx++) {
				int[][] tmp = new int[n][m];
				copyArr(arr, tmp);
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv4[idx][0] * cnt;
					int ny = y + cctv4[idx][1] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv4[idx][2] * cnt;
					int ny = y + cctv4[idx][3] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				for (int cnt = 1; cnt <= 8; cnt++) {
					int nx = x + cctv4[idx][4] * cnt;
					int ny = y + cctv4[idx][5] * cnt;
					if (check(ny, nx) || tmp[ny][nx] == 6)
						break;
					if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
						continue;
					tmp[ny][nx] = -1;
				}
				solve(tmp,cctvidx+1);
			}
		} else if (type == 5) {
			int[][] tmp = new int[n][m];
			copyArr(arr, tmp);
			for (int cnt = 1; cnt <= 8; cnt++) {
				int nx = x + cctv5[0][0] * cnt;
				int ny = y + cctv5[0][1] * cnt;
				if (check(ny, nx) || tmp[ny][nx] == 6)
					break;
				if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
					continue;
				tmp[ny][nx] = -1;
			}
			for (int cnt = 1; cnt <= 8; cnt++) {
				int nx = x + cctv5[0][2] * cnt;
				int ny = y + cctv5[0][3] * cnt;
				if (check(ny, nx) || tmp[ny][nx] == 6)
					break;
				if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
					continue;
				tmp[ny][nx] = -1;
			}
			for (int cnt = 1; cnt <= 8; cnt++) {
				int nx = x + cctv5[0][4] * cnt;
				int ny = y + cctv5[0][5] * cnt;
				if (check(ny, nx) || tmp[ny][nx] == 6)
					break;
				if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
					continue;
				tmp[ny][nx] = -1;
			}
			for (int cnt = 1; cnt <= 8; cnt++) {
				int nx = x + cctv5[0][6] * cnt;
				int ny = y + cctv5[0][7] * cnt;
				if (check(ny, nx) || tmp[ny][nx] == 6)
					break;
				if (tmp[ny][nx] > 0 && tmp[ny][nx] < 6)
					continue;
				tmp[ny][nx] = -1;
			}
			solve(tmp,cctvidx+1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		cctv = new Pos[8];
		cctvCnt=0;
		int[][] arr = new int[n][m];
		boolean[][] v = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j]<6 && arr[i][j]>0) {
					cctv[cctvCnt]=new Pos(i,j,arr[i][j]);
					cctvCnt++;
				}
			}
		}
		solve(arr,0);
		bw.write(ans + "");
		br.close();
		bw.flush();
		bw.close();
	}
}
