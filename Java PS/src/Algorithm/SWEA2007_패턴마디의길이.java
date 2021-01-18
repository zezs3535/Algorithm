package Algorithm;

import java.util.Scanner;

public class SWEA2007_패턴마디의길이 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			String s = sc.next();
			int answer=0;
			for(int j=1;j<=10;j++) {
				String word = s.substring(0,j);
				String wordNext = s.substring(j,j+j);
				if(word.equals(wordNext)) {
					answer=j;
					break;
				}
			}
			System.out.println("#" + (i + 1) + " "+answer);
		}
	}
}
