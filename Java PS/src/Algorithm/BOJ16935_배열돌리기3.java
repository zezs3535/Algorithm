package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ16935_배열돌리기3 {
	static int n;
	static int m;
	static BufferedReader br;
	static BufferedWriter bw;
	static int flag; // 0이면 arr배열, 1이면 arr2배열 사용

	static void upDown(int[][] arr) {
		for (int i = 0; i < arr.length / 2; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[arr.length - i - 1][j];
				arr[arr.length - i - 1][j] = tmp;
			}
		}
	}

	static void leftRight(int[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length / 2; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[i][arr[i].length - 1 - j];
				arr[i][arr[i].length - 1 - j] = tmp;
			}
		}
	}

	static void rotate(int[][] arr, int[][] arr2) {
		if (flag == 0) { // n*m arr을 회전해서 arr2
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					arr2[i][j] = arr[n - 1 - j][i];
				}
			}
		} else { // m*n arr2를 회전해서 arr
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = arr2[m - 1 - j][i];
				}
			}
		}
		flag ^= 1;
	}

	static void revRotate(int[][] arr, int[][] arr2) {
		if (flag == 0) { // n*m arr을 회전해서 arr2
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					arr2[i][j] = arr[j][m - 1 - i];
				}
			}
		} else { // m*n arr2를 회전해서 arr
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = arr2[j][n - 1 - i];
				}
			}
		}
		flag ^= 1;
	}

	static void moveRight(int[][] arr) { // 시계
		int yy = arr.length;
		int xx = arr[0].length;
		int y = arr.length / 2;
		int x = arr[0].length / 2;
		int[][] tmp = new int[y][x];
		for (int i = 0; i < y; i++) { // 3->1
			for (int j = 0; j < x; j++) {
				tmp[i][j] = arr[i][j];
				arr[i][j] = arr[i + y][j];
			}
		}
		for (int i = y; i < yy; i++) { //4->3
			for (int j = 0; j < x; j++) {
				arr[i][j] = arr[i][j + x];
			}
		}
		for (int i = y; i < yy; i++) { //2->4
			for (int j = x; j < xx; j++) {
				arr[i][j] = arr[i-y][j];
			}
		}
		for(int i=0;i<y;i++) { //1->2
			for(int j=x;j<xx;j++) {
				arr[i][j] = tmp[i][j-x];
			}
		}
	}

	static void moveLeft(int[][] arr) { // 반시계
		int yy = arr.length;
		int xx = arr[0].length;
		int y = arr.length / 2;
		int x = arr[0].length / 2;
		int[][] tmp = new int[y][x];
		for (int i = 0; i < y; i++) { // 2->1
			for (int j = 0; j < x; j++) {
				tmp[i][j] = arr[i][j];
				arr[i][j] = arr[i][j + x];
			}
		}
		for(int i=0;i<y;i++) { //4->2
			for(int j=x;j<xx;j++) {
				arr[i][j] = arr[i+y][j];
			}
		}
		for(int i=y;i<yy;i++) { //3->4
			for(int j=x;j<xx;j++) {
				arr[i][j] = arr[i][j-x];
			}
		}
		for(int i=y;i<yy;i++) { //1->3
			for(int j=0;j<x;j++) {
				arr[i][j] = tmp[i-y][j];
			}
		}
	}

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n][m];
		int[][] arr2 = new int[m][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for (int t = 0; t < r; t++) {
			int ins = Integer.parseInt(st.nextToken());
			if (ins == 1) {
				if(flag == 0)upDown(arr);
				else {
					upDown(arr2);
				}
			} else if (ins == 2) {
				if(flag==0)leftRight(arr);
				else {
					leftRight(arr2);
				}
			} else if (ins == 3) {
				rotate(arr, arr2);
			} else if (ins == 4) {
				revRotate(arr, arr2);
			} else if (ins == 5) {
				if (flag == 0)
					moveRight(arr);
				else {
					moveRight(arr2);
				}
			} else if (ins == 6) {
				if (flag == 0)
					moveLeft(arr);
				else {
					moveLeft(arr2);
				}
			}

		}
		if(flag==1) {
			for(int i=0;i<m;i++) {
				for(int j=0;j<n;j++) {
					bw.write(arr2[i][j]+" ");
				}
				bw.write("\n");
			}
		}
		else {
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					bw.write(arr[i][j]+" ");
				}
				bw.write("\n");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
