package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class SWEA1233_사칙연산유효성검사 {
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		for(int test=1;test<=10;test++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int flag = 1;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				if(st.countTokens()==4) {
					int v = Integer.parseInt(st.nextToken());
					String op = st.nextToken();
					int ln = Integer.parseInt(st.nextToken());
					int rn = Integer.parseInt(st.nextToken());
					if(op.charAt(0)>=48 && op.charAt(0)<=57) {
						flag=0;
					}
				}
				if(st.countTokens()==2) {
					int v = Integer.parseInt(st.nextToken());
					String op = st.nextToken();
					if(!(op.charAt(0)>=48 && op.charAt(0)<=57)) {
						flag=0;
					}
				}
			}
			bw.write("#"+test+" "+flag+"\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
