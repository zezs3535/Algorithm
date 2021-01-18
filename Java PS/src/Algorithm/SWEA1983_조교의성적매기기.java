package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA1983_조교의성적매기기 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 0; t < test; t++) {
			int studentNum = sc.nextInt();
			int key = sc.nextInt();
			float[] student = new float[studentNum];
			String[] score = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
			for (int i = 0; i < studentNum; i++) {
				int mi = sc.nextInt();
				int fi = sc.nextInt();
				int hw = sc.nextInt();
				student[i]=(float) (mi*0.35+fi*0.45+hw*0.2);
			}
			int cnt=0;
			/*for(int i=0;i<studentNum;i++) {
				System.out.println(student[i]);
			}*/
			for(int i=0;i<studentNum;i++) {
				if(student[i]>student[key-1])cnt++;
			}
			System.out.println("#" + (t + 1) + " "+score[(cnt/(studentNum/10))]);
		}
	}
}
