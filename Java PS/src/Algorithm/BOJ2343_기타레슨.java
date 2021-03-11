package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ2343_기타레슨 {
	static int n;
	static int m;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		int l=0;
		int r = 0;
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
			if(l<arr[i])l=arr[i];
			r+=arr[i];
		}
		while(l<=r) {
			int mid = (l+r)/2;
			int cnt=0;
			int lenSum=0;
			for(int i=0;i<n;i++) {
				if(lenSum+arr[i]>mid) {
					lenSum=0;
					cnt++;
				}
				lenSum+=arr[i];
			}
			if(lenSum!=0)cnt++;
			if(cnt<=m) { 
				r=mid-1;
			}
			else if(cnt>m) { 
				l=mid+1;
			}
		}
		bw.write(l+" ");
		br.close();
		bw.flush();
		bw.close();
	}
}
