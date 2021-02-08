package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class SWEA1228_암호문1 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int test = 1; test <= 10; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			LinkedList<String> l = new LinkedList<String>();
			int n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				l.add(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			int insNum = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < insNum; i++) {
				String c = st.nextToken();
				int idx = Integer.parseInt(st.nextToken());
				int cnt = Integer.parseInt(st.nextToken());
				for(int j=0;j<cnt;j++) {
					l.add(j+idx, st.nextToken());
				}
			}
			bw.write("#"+test+" ");
			for(int i=0;i<10;i++) {
				bw.write(l.get(i)+" ");
			}
			bw.write("\n");
		}

		br.close();
		bw.flush();
		bw.close();
	}

}
