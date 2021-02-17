package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class JO1828_냉장고 {
	static class Chemic {
		int low;
		int high;

		Chemic() {

		}

		Chemic(int low, int high) {
			this.low = low;
			this.high = high;
		}

		@Override
		public String toString() {
			return "Chemic [low=" + low + ", high=" + high + "]";
		}

	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int now = -270;
		int answer=0;
		Chemic[] arr = new Chemic[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int lt = Integer.parseInt(st.nextToken());
			int ht = Integer.parseInt(st.nextToken());
			arr[i] = new Chemic(lt, ht);
		}
		Arrays.sort(arr, new Comparator<Chemic>() {
			@Override
			public int compare(Chemic o1, Chemic o2) {
				return o1.high - o2.high;
			}
		});
		for (int i = 0; i < n; i++) {
			if(now<=arr[i].low) {
				answer++;
				now=arr[i].high;
			}
		}
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
