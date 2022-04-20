package Algorithm;

import java.io.FileInputStream;
import java.util.HashMap;
import java.util.Scanner;

public class BOJ2002_추월 {

	static class Car {
		String carNum;
		int idx;

		public Car(String carNum, int idx) {
			super();
			this.carNum = carNum;
			this.idx = idx;
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		HashMap<String, Integer> hash = new HashMap<>();
		Car[] start = new Car[n];
		Car[] finish = new Car[n];
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			start[i] = new Car(s,i);
			hash.put(s, i);
		}
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			finish[i] = new Car(s,i);
		}
		for (int i = 0; i < n; i++) {
			int startOrder = hash.get(finish[i].carNum);
			for(int j=i;j<n;j++) {
				if(startOrder > hash.get(finish[j].carNum)) {
					ans++;
					break;
				}
			}
		}
		System.out.println(ans);
	}
}
