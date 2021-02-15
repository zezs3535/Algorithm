package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2961_도영이가만든맛있는음식 {
	static int n;
	static int flag;
	static int answer = Integer.MAX_VALUE;
	static Ingre[] ingre;

	static class Ingre {
		int s;
		int b;

		public Ingre(int s, int b) {
			this.s = s;
			this.b = b;
		}

		Ingre() {

		}
	}

	static void ps(int cnt) {
		if (cnt == n) {
			if(flag==0)return;
			int ss = 1;
			int sb = 0;
			int food = 0;
			for (int j = 0; j < n; j++) {
				if ((flag & (1 << j)) != 0) {
					ss *= ingre[j].s;
					sb += ingre[j].b;
				}
			}
			food = Math.abs(ss - sb);
			answer = Math.min(food, answer);
			return;
		}
		flag = (flag | (1 << cnt));
		ps(cnt + 1);
		flag = (flag & ~(1 << cnt));
		ps(cnt + 1);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		ingre = new Ingre[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			ingre[i] = new Ingre(s, b);
		}
		ps(0);
		bw.write(answer + "");
		br.close();
		bw.flush();
		bw.close();

	}

}
