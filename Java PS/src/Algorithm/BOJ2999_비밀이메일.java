package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ2999_비밀이메일 {
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String in = br.readLine();
		int n = in.length();
		int y = 0;
		int x = 0;
		for(int i=n;i>0;i--) {
			for(int j=1;j<=n;j++) {
				if(n == i*j && i<=j) { //곱이 같고 R<=C 일때
					y=i;
					x=j;
					break;
				}
			}
			if(x!=0)break; //이미 구했으면 break
		}
		char[][] arr = new char[y][x];
		int idx = 0;
		for(int i=0;i<x;i++) {
			for(int j=0;j<y;j++) {
				arr[j][i] = in.charAt(idx++); 
			}
		}
		for(int i=0;i<y;i++) {
			for(int j=0;j<x;j++) {
				System.out.print(arr[i][j]); 
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
