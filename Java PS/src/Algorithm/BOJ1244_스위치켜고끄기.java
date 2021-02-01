package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ1244_스위치켜고끄기 {
	static class Person {
		int gender;
		int idx;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine()); // 8
		StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
		int[] arr = new int[n+3];
		for (int i = 1; i <= n; i++) {
			arr[i] = Integer.parseInt(st.nextToken()); // 0 1 0 1 0 0 0 1
		}
		int m = Integer.parseInt(br.readLine()); // 2
		Person[] person = new Person[m];
		for (int i = 0; i < m; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			person[i] = new Person();
			person[i].gender = Integer.parseInt(st2.nextToken());
			person[i].idx = Integer.parseInt(st2.nextToken());
		}
		for(int i=0;i<m;i++) {
			if(person[i].gender==1) { //남자일때
				for(int j=person[i].idx;j<=n;j+=person[i].idx) {
					arr[j]^=1;
				}
			}
			else { //여자일때
				int cnt=1;
				while(true) {
					int left = person[i].idx-cnt;
					int right = person[i].idx+cnt;
					if(left<=0 || right>n || arr[left]!=arr[right]) {
						break;
					}
					if(arr[left] == arr[right]) {
						cnt++;
					}
				}
				cnt--;
				for(int j=person[i].idx+1;j<=person[i].idx+cnt;j++) {
					arr[j]^=1;
				}
				for(int j=person[i].idx-1;j>=person[i].idx-cnt;j--) {
					arr[j]^=1;
				}
				arr[person[i].idx]^=1;
			}
		}
		for(int i=1;i<=n;i++) {
			if(i%20==0)bw.write(arr[i]+"\n");
			else{
				bw.write(arr[i]+" ");
			}
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
