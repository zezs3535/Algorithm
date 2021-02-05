package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2503_숫자야구 {
	static int n;

	static class Game {
		int q;
		int s;
		int b;
	}

	static boolean hasZero(int num) {
		if (num / 100 == 0 || (num % 100) / 10 == 0 || (num % 10) == 0)
			return true;
		return false;
	}

	static boolean isDiff(int num) {
		int n1 = num/100;
		int n2 = (num%100)/10;
		int n3 = (num%10);
		if (n1 != n2 && n2 != n3 && n1 != n3)return false;
		return true;
	}

	static boolean canGuess(Game g, int num) {
		int scnt = 0;
		int bcnt = 0;
		int q100 = g.q / 100;
		int n100 = num / 100;
		int q10 = (g.q % 100) / 10;
		int n10 = (num % 100) / 10;
		int q1 = g.q % 10;
		int n1 = num % 10;
		if (q100 == n100)
			scnt++;
		if (q10 == n10)
			scnt++;
		if (q1 == n1)
			scnt++;
		if (q100 == n10)
			bcnt++;
		if (q100 == n1)
			bcnt++;
		if (q10 == n100)
			bcnt++;
		if (q10 == n1)
			bcnt++;
		if (q1 == n100)
			bcnt++;
		if (q1 == n10)
			bcnt++;
		if (g.s == scnt && g.b == bcnt)
			return true;
		return false;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int num = 100;
		int answer = 0;
		n = Integer.parseInt(st.nextToken());
		Game[] game = new Game[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			game[i] = new Game();
			game[i].q = Integer.parseInt(st.nextToken());
			game[i].s = Integer.parseInt(st.nextToken());
			game[i].b = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < 900; i++) {
			int cnt = 0;
			if (hasZero(num + i))
				continue;
			if (isDiff(num + i)) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (canGuess(game[j], num + i))
					cnt++;
			}
			if (cnt == n) {
				answer++;
			}
		}
		bw.write(answer + " ");
		br.close();
		bw.flush();
		bw.close();
	}

}
