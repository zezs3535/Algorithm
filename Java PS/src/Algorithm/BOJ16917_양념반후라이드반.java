package Algorithm;

import java.util.Scanner;

public class BOJ16917_양념반후라이드반 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int price = 0;
		int small=Math.min(x, y);
		
		if (a + b >= (2 * c)) {
			price = small*c*2;
			if(x-small>0 && a>=c*2) {
				price+=(x-small)*2*c;
			}
			else if(x-small>0 && a<c*2) {
				price+=(x-small)*a;
			}
			if(y-small>0 && b>=c*2) {
				price+=(y-small)*2*c;
			}
			else if(y-small>0 && b<c*2) {
				price+=(y-small)*b;
			}
		}
		else {
			price = a*x+b*y;
		}
		System.out.println(price);
	}
}
