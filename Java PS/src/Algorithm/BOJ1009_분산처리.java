package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ1009_분산처리 {
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int mul = a%10;
			for(int j=1;j<b;j++) {
				mul = (mul * a) % 10;				
			}
			System.out.println(mul == 0? 10 : mul%10);
		}
	}
}
