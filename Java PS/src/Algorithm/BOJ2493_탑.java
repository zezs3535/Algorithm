package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

class Tower {
	int idx;
	int height;

	Tower(int idx, int height) {
		this.idx = idx;
		this.height = height;
	}

}

public class BOJ2493_탑 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Stack<Tower> s = new Stack<Tower>();
		int n = Integer.parseInt(st.nextToken());
		int[] arr = new int[n+1];
		int[] answer = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		s.push(new Tower(n, arr[n]));
		for (int i = n - 1; i > 0; i--) {
			while (!s.empty()) {
				if (arr[i] > s.peek().height) { // 지금이 더 크면 레이저를 수신
					answer[s.peek().idx] = i;
					s.pop();
				}
				else {
					break;
				}
			}
			s.push(new Tower(i, arr[i]));
		}
		for(int i=1;i<=n;i++) {
			bw.write(answer[i]+" ");
		}
		br.close();
		bw.flush();
		bw.close();
	}

}
