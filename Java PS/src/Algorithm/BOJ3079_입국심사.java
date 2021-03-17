package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ3079_입국심사 {
	
	public static void main(String[] args) throws Exception{
		//System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] num = new int[n];
		int maxnum=0;
		long answer=0;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			num[i] = Integer.parseInt(st.nextToken());
			if(maxnum<num[i])maxnum=num[i];
		}
		long l = 1;
		long r = maxnum * m;
		while(l<=r) {
			long mid = (l+r)/2;
			long cnt=0;
			for(int i=0;i<n;i++) {
				cnt+=mid/num[i];
			}
			if(cnt>=m) {
				r=mid-1;
				answer=mid;
			}
			else {
				l=mid+1;
			}
		}
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
