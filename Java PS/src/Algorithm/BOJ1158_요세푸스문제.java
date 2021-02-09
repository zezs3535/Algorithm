package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ1158_요세푸스문제 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		Queue<Integer> q = new LinkedList<Integer>();
		for(int i=1;i<=n;i++) {
			q.offer(i);
		}
		int cnt=1;
		sb.append("<");
		while(!q.isEmpty()) {
			if(cnt==k) {
				sb.append(q.poll()+", ");
				cnt=1;
				continue;
			}
			q.offer(q.poll());
			cnt++;
		}
		sb.setLength(sb.length()-2);
		sb.append(">");
		bw.write(sb.toString());
		br.close();
		bw.close();
	}

}
