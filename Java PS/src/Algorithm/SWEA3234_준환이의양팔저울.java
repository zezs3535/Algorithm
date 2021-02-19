package Algorithm;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class SWEA3234_준환이의양팔저울 {
	static int answer;
	static void permu(int[] arr, boolean[] v, int idx, int cnt, int leftw, int rightw, int n) {
		if (cnt == n) {
			answer++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				v[i] = true;
				permu(arr,v,idx+1,cnt+1, leftw+arr[i], rightw, n);
				if(leftw>=rightw+arr[i]) {
					permu(arr,v,idx+1,cnt+1, leftw, rightw+arr[i], n);
				}
				v[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			answer=0;
			int n = sc.nextInt();
			int[] arr = new int[n];
			int idx=0;
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			permu(arr,new boolean[n],idx,0,0,0,n);
			System.out.println("#"+test+" "+answer);
		}
		sc.close();
	}

}
