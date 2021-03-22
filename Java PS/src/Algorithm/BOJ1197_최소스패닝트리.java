package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1197_최소스패닝트리 {
	static class Node implements Comparable<Node>{
		int w;
		int end;

		public Node(int w, int end) {
			super();
			this.w = w;
			this.end = end;
		}

		@Override
		public int compareTo(Node o) {
			return this.w-o.w;
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		PriorityQueue<Node> pq = new PriorityQueue<>();
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int answer = 0;
		ArrayList<Node>[] node = new ArrayList[n + 1];
		boolean[] visited = new boolean[n + 1];
		for (int i = 0; i <= n; i++) {
			node[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int u, v, w;
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			node[u].add(new Node(w, v));
			node[v].add(new Node(w, u));
		}
		visited[1] = true;
		for (Node a : node[1])pq.add(a);
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if (visited[cur.end])continue;
			visited[cur.end] = true;
			answer+=cur.w;
			for(Node a : node[cur.end])pq.add(a);
		}
		bw.write(answer+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
