package Algorithm;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class SWEA4013_특이한자석 {
	static ArrayList<Integer>[] a;
	static int ans;
	
	static void shiftQueue(ArrayList<Integer> a, int dir) {
		int tmp;
		if(dir>0) {
			tmp = a.get(7);
			a.remove(7);
			a.add(0, tmp);
		}
		else {
			tmp = a.get(0);
			a.remove(0);
			a.add(7, tmp);
		}
	}
	
	static void shiftLeftQueue(int target, int dir) {
		if(target<0)return;
		if(a[target].get(2)==a[target+1].get(6)) {
			return;
		}
		else {
			shiftLeftQueue(target-1,(dir>0)?-1:1);
			shiftQueue(a[target],dir);
		}
	}
	
	static void shiftRightQueue(int target, int dir) {
		if(target>3)return;
		if(a[target].get(6)==a[target-1].get(2)) {
			return;
		}
		else {
			shiftRightQueue(target+1,(dir>0)?-1:1);
			shiftQueue(a[target],dir);
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int k = sc.nextInt();
			int cnt = 1;
			ans = 0;
			a = new ArrayList[4];
			for (int i = 0; i < 4; i++) {
				a[i] = new ArrayList<>();
				for (int j = 0; j < 8; j++) {
					int tmp = sc.nextInt();
					a[i].add(tmp);
				}
			}
			for(int i=0;i<k;i++) {
				int target = sc.nextInt();
				int dir = sc.nextInt();
				target--;
				shiftLeftQueue(target-1,(dir>0)?-1:1);
				shiftRightQueue(target+1,(dir>0)?-1:1);
				shiftQueue(a[target],dir);
			}
			for(int i=0;i<4;i++) {
				if(a[i].get(0)==1)ans+=cnt;
				cnt*=2;
			}
			System.out.println("#"+test+" "+ans);
		}
	}
}
