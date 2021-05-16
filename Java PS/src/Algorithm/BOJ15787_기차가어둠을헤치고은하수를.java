package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ15787_기차가어둠을헤치고은하수를 {
	static int[] arr;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		Set<Integer> s = new HashSet<>();
		int n = Integer.parseInt(st.nextToken());
		arr = new int[n + 1];
		int m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int com = Integer.parseInt(st.nextToken());
			int train = Integer.parseInt(st.nextToken());
			if (com < 3) { // com=1,2
				int seat = Integer.parseInt(st.nextToken());
				if(com==1) {
					arr[train] |= (1 << (seat-1));
				}
				else if(com==2) {
					if((arr[train] & (1<<seat-1)) == (1<<seat-1)) {
						arr[train] ^= (1<<seat-1);
					}
				}
			}
			else { // com=3,4
				if (com == 3) {
					arr[train] <<= 1;
					if((arr[train] & (1<<20)) == (1<<20)) {
						arr[train] ^= (1<<20);
					}
				} else {
					arr[train] >>= 1;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			s.add(arr[i]);
		}
		bw.write(s.size()+"");
		br.close();
		bw.flush();
		bw.close();
	}
}
