package Algorithm;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA1225_암호생성기 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<Integer>();
		for(int test=1;test<=10;test++) {
			int t = sc.nextInt();
			for(int i=0;i<8;i++) {
				q.offer(sc.nextInt());
			}
			int cnt=1;
			while(true) {
				int tmp = q.peek()-cnt;
				if(tmp<=0) {
					q.offer(0);
					q.poll();
					break;
				}
				q.offer(tmp);
				q.poll();
				cnt=(cnt%5)+1;
			}
			System.out.print("#"+t+" ");
			for(int i=0;i<8;i++) {
				System.out.print(q.poll()+" ");
			}
			System.out.println();
		}
		while(!q.isEmpty()) {
			q.poll();
		}

	}

}
