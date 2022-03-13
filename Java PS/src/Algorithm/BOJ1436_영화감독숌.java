package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ1436_영화감독숌 {
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int cnt = 0;
		int num = 666;
		while(true) { //n번째 수를 찾을때까지
			int tmp = num;
			int cnt6 = 0;
			while(tmp!=0) {
				if(tmp%10==6) {
					cnt6++;
				}
				else {
					cnt6=0;
				}
				if(cnt6==3) {
					cnt++;
					break;
				}
				tmp/=10;
			}
			if(cnt==n)break;
			num++;
		}
		System.out.println(num);
	}
}
