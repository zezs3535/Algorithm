package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class JO1863_종교 {
	static int n,m;
	static int[] parent;
	
	static int find(int a) {
		if(parent[a]==a)return a;
		return parent[a]=find(parent[a]);
	}
	
	static void union(int a, int b) {
		if(find(a)==find(b))return;
		parent[find(b)]=find(a);
	}
	
	public static void main(String[] args) throws Exception{
		//System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		Set<Integer> s = new HashSet<>();
		parent = new int[n+1];
		for(int i=1;i<=n;i++) { //make_set
			parent[i]=i;
		}
		for(int i=0;i<m;i++) { //union a,b
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			union(a,b);
		}
		for(int i=1;i<=n;i++) {
			s.add(parent[i]);
		}
		bw.write(s.size()+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
