package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ10820_문자열분석 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		boolean flag = true;
		while (flag) {
			try {
				String in = sc.nextLine();
				int[] arr = new int[4];
				for(int i=0;i<in.length();i++) {
					char tmp = in.charAt(i);
					if(tmp>='a' && tmp<='z') {
						arr[0]++;
					}else if(tmp>='A' && tmp<='Z') {
						arr[1]++;
					}else if(tmp>='0' && tmp<='9') {
						arr[2]++;
					}else if(tmp == ' '){
						arr[3]++;
					}
				}
				for(int i=0;i<3;i++) {
					System.out.print(arr[i]+" ");
				}
				System.out.println(arr[3]);
			} catch (Exception e) {
				flag = false;
			}
		}

	}
}
