package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2564_경비원 {
	static int maxDis;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] dis = new int[n+1];
		maxDis = 2 * x + 2 * y;
		int ans = 0;
		for (int i = 0; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine());
			int dir = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			if (dir == 1)
				dis[i] = num;
			else if (dir == 4)
				dis[i] = x + num;
			else if (dir == 2)
				dis[i] = x + y + (x - num);
			else if (dir == 3)
				dis[i] = x * 2 + y + (y - num);
		}
		for (int i = 0; i < n; i++) {
			ans += getDis(dis[i], dis[n]);
		}
		bw.write(ans+"");
		br.close();
		bw.flush();
		bw.close();
	}

	static int getDis(int shop, int dg) {
		if(shop<dg) {
			return dg-shop>maxDis-dg+shop?maxDis-dg+shop:dg-shop;
		}
		else {
			return shop-dg>maxDis-shop+dg?maxDis-shop+dg:shop-dg;
		}
	}
}
