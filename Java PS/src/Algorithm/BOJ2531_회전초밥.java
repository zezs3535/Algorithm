package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ2531_회전초밥 {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		Set<Integer> s = new HashSet<>(); //종류 확인
		
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int ans=0;
		
		int[] arr = new int[n+k-1];
		int[] check = new int[d+1]; //몇개나 들어왔는지 확인
		
		for(int i=0;i<n;i++) {
			arr[i] = Integer.parseInt((new StringTokenizer(br.readLine())).nextToken());
		}
		for(int i=n;i<n+k-1;i++) {
			arr[i] = arr[i%n];
		}
		
		check[c]++; //쿠폰으로 먹는 초밥은 무료니까 넣어놓기
		s.add(c);
		
		for(int i=0;i<k;i++) { //첫 K개만큼 넣어놓기
			check[arr[i]]++;
			s.add(arr[i]);
		}
		ans = Math.max(ans, s.size());
		for(int i=k;i<n+k-1;i++) {
			check[arr[i]]++;
			s.add(arr[i]);
			
			check[arr[i-k]]--;
			if(check[arr[i-k]]==0)s.remove(arr[i-k]);
			ans = Math.max(ans, s.size());
		}
		bw.write(ans+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
