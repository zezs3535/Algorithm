package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ15649_N과M1 {
	static int n;
	static int m;
	static int[] num; //1, 2, 3.... 숫자
	static int[] arr; //값을 담아서 출력할 배열
	static boolean[] v; //방문했냐?
	private static void permu(int k) {
		if(k==m) {
			for(int i : arr) {
				System.out.print(i+" ");
			}
			System.out.println();
			return;
		}
		for(int i=0;i<n;i++) {
			if(!v[i]) {
				v[i]=true;
				arr[k] = num[i];
				permu(k+1);
				v[i]=false;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		num = new int[n];
		arr = new int[m];
		v = new boolean[n];
		for(int i=0;i<n;i++) {
			num[i] = i+1;
		}
		permu(0);
	}

}
