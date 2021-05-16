package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ18113_그르다김가놈 {
	static ArrayList<Integer> arr;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int tmp = Integer.parseInt(st.nextToken());
			if (tmp <= k || tmp == 2 * k)
				continue; // 작으면 폐기
			else if (tmp < 2 * k) { // 2K보다 작으면 한쪽만 잘라냄
				arr.add(tmp - k);
			} else {
				arr.add(tmp - 2 * k);
			}
		}
		if (arr.isEmpty())
			bw.write(-1 + "");
		else {
			int l = 1;
			int r = 2000000000;
			int cnt = 0;
			while (l <= r) {
				cnt = 0;
				int mid = (l + r) / 2;
				for (int a : arr) {
					cnt += a / mid;
				}
				// bw.write(l+" "+r+" "+mid+" "+cnt+"\n");
				if (cnt >= m) { // 갯수가 더 많으면 길이를 최대로 늘리기
					l = mid + 1;
				} else if (cnt < m) { // 갯수가 더 적으면 길이를 줄여서 갯수 늘리기
					r = mid - 1;
				}
			}
			bw.write(r+"");
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
