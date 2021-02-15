package Algorithm;

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class SWEA6808_규영이와인영이의카드게임 {
	static int[] gyu = new int[9];
	static int[] in = new int[9];
	static int[] sel;
	static boolean[] v = new boolean[9];
	static int win;
	static int lose;
	static void permu(int cnt) {
		if(cnt==9) {
			int gyuScore=0;
			int inScore=0;
			for(int i=0;i<9;i++) {
				if(sel[i]>in[i])gyuScore+=(sel[i]+in[i]);
				else if(sel[i]<in[i])inScore+=(sel[i]+in[i]);
			}
			if(gyuScore>inScore)win++;
			else if(gyuScore<inScore)lose++;
		}
		for(int i=0;i<9;i++) {
			if(!v[i]) {
				v[i]=true;
				sel[cnt]=gyu[i];
				permu(cnt+1);
				v[i]=false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			win=0;
			lose=0;
			int[] tmp = new int[19];
			sel = new int[9];
			for(int i=1;i<=18;i++)tmp[i]=i;
			for(int i=0;i<9;i++) {
				gyu[i]=sc.nextInt();
				tmp[gyu[i]]=0;
			}
			int cnt=0;
			for(int i=1;i<=18;i++) {
				if(tmp[i]!=0)in[cnt++]=i;
			}
			permu(0);
			System.out.println("#"+test+" "+win+" "+lose);
		}
	}
}
