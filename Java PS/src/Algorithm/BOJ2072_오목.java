package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ2072_오목 {
	static int[] dx = { 1, 1, 0, -1, -1, -1, 0, 1 };
	static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static int[][] baduk = new int[25][25];
	static int n;
	static int answer = 0;

	static void search(int ypos, int xpos, int turn) {
		int curColor = baduk[ypos][xpos];
		for (int idx = 0; idx < 8; idx++) {
			int cnt = 0;
			for (int i = 1; i <= 5; i++) {
				int ny = ypos + dy[idx] * i;
				int nx = xpos + dx[idx] * i;
				if (ny >= 20 || ny < 1 || nx >= 20 || nx < 1)
					break;
				if (baduk[ny][nx] == curColor) {
					cnt++;
					continue;
				}
				break;
			}
			for (int i = 1; i <= 5; i++) {
				int by = ypos + (dy[(idx + 4) % 8] * i);
				int bx = xpos + (dx[(idx + 4) % 8] * i);
				if (by >= 20 || by < 1 || bx >= 20 || bx < 1)
					break;
				if (baduk[by][bx] == curColor) {
					cnt++;
					continue;
				}
				break;
			}
			if(cnt>=5)continue;
			else if(cnt==4) {
				answer=turn;
				return;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		if (n <= 8) {
			bw.write("1");
			return;
		}
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			int ypos = Integer.parseInt(st.nextToken());
			int xpos = Integer.parseInt(st.nextToken());
			if (i % 2 == 1) {
				baduk[ypos][xpos] = 1;
			} else {
				baduk[ypos][xpos] = 2;
			}
			if (i <= 8)
				continue;
			search(ypos, xpos, i);
			if (answer > 0)
				break;
		}
		if (answer > 0)
			bw.write(answer + "");
		else {
			bw.write("-1");
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
