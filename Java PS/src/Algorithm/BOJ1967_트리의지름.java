package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ1967_트리의지름 {
	static int n;
	static Node[] node;
	static int answer = 0;

	static class Node {
		int sum = 0;
		ArrayList<Integer> child = new ArrayList<>();
		ArrayList<Integer> dis = new ArrayList<>();
	}

	static int go(int idx, int w) {
		int disSum = 0;
		int disMax = 0;
		ArrayList<Integer> childSum = new ArrayList<>();
		for (int i = 0; i < node[idx].child.size(); i++) {
			int tmp = go(node[idx].child.get(i), node[idx].dis.get(i));
			childSum.add(tmp);
			disMax = Math.max(disMax, tmp);
		}
		int csize=childSum.size();
		if(csize<=2) {
			for(int i=0;i<csize;i++) {
				disSum+=childSum.get(i);
			}
		}
		else {
			Collections.sort(childSum);
			disSum+=childSum.get(csize-1)+childSum.get(csize-2);
		}
		answer = Math.max(answer, disSum);
		return w + disMax;
	}

	public static void main(String[] args) throws Exception {
		//System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		node = new Node[10001];
		for (int i = 0; i <= 10000; i++)
			node[i] = new Node();
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			node[u].child.add(v);
			node[u].dis.add(w);
		}
		go(1, 0);
		bw.write(answer + "");
		br.close();
		bw.flush();
		bw.close();
	}
}
