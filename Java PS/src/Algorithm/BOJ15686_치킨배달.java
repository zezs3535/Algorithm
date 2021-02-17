package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ15686_치킨배달 {
	static class Pos {
		@Override
		public String toString() {
			return "Pos [y=" + y + ", x=" + x + "]";
		}
		Pos(){
			
		}
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
		int y;
		int x;
	}
	static boolean np(int[] arr) {
		int i = arr.length-1;
		while(i>0&&arr[i-1]>=arr[i]) {--i;}
		// 꼭지점이 없으면 종료
		if(i==0) return false;
		
		// i 가 꼭지점
		// 뒤에서 부터 꼭지점까지 검색을해서 i-1 보다 큰값이 나오면 정지
		int j=arr.length-1;
		while(arr[i-1]>=arr[j]) {--j;}
		
		// j 는 i-1 보다 크거나같은 값입니다
		// 그래서 i-1 가 j값을 교환
		swap(arr,i-1,j);
		
		// 꼭지점이 맨마지막값이 아니라면 꼭지점자리를 기준으로 오름차순 정렬
		int k = arr.length-1;
		while(i<k) {
			swap(arr,i++,k--);
		}
		return true;
	}
	static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		
	}
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		LinkedList<Pos> home = new LinkedList<Pos>();
		LinkedList<Pos> chicken = new LinkedList<Pos>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				if(tmp==1)home.add(new Pos(i-1,j-1));
				if(tmp==2)chicken.add(new Pos(i-1,j-1));
			}
		}
		int h = home.size();
		int l = chicken.size();
		int[] choice = new int[l];
		Pos[] homeArr = new Pos[home.size()];
		Pos[] chickArr = new Pos[l];
		for(int i=0;i<h;i++) {
			homeArr[i] = new Pos();
			homeArr[i] = home.poll();
		}
		for(int i=0;i<l;i++) {
			chickArr[i] = new Pos();
			chickArr[i] = chicken.poll();
		}
		Arrays.fill(choice, l-m, l, 1);
		int answer=1000000;
		do {
			int tmp=0;
			for(int j=0;j<homeArr.length;j++) {
				int ret = 100000;
 				for(int i=0;i<l;i++) {
					if(choice[i]==0)continue;
					ret = Math.min(ret, Math.abs(homeArr[j].y-chickArr[i].y)+Math.abs(homeArr[j].x-chickArr[i].x));
				}
				tmp+=ret;
			}
			answer = Math.min(answer, tmp);
		}while(np(choice));
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
