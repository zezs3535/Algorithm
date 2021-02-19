package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ18512_점프점프 {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		boolean flag = false;
		while (a <= 10000 && b <= 10000) {
			if(a>b) {
				b+=y;
			}
			else if(a<b) {
				a+=x;
			}
			else {
				flag = true;
				break;
			}
		}
		if(flag) {
			bw.write(a+"");
		}
		else {
			bw.write("-1");
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
