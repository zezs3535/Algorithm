package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA8382_방향전환 {
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			int ysum = Math.abs(y2-y1);
			int xsum = Math.abs(x2-x1);
			int sum = ysum+xsum;
			System.out.println("#"+test+" "+(sum%2==0?Math.max(ysum, xsum)*2:Math.max(ysum, xsum)*2-1));
		}
	}
}
