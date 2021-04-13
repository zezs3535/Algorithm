package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ14890_경사로 {
	static int N, X, map[][];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		map = new int[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		System.out.println(process());
		br.close();
		bw.flush();
		bw.close();
	}

	static int process() {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (makeRoad(map[i]))cnt++; //가로 체크
			int[] tmp = new int[N];
			for(int j=0;j<N;j++) {
				tmp[j]=map[j][i];
			}
			if(makeRoad(tmp))cnt++; //세로 체크
		}

		return cnt;
	}

	static boolean makeRoad(int[] map) {
		int beforeHeight = map[0], size = 0;
		int j = 0;
		while (j < N) {
			if (beforeHeight == map[j]) {
				size++;
				j++;
			} else if (beforeHeight + 1 == map[j]) {
				if (size < X)
					return false;
				beforeHeight++;
				size = 1;
				j++;
			} else if (beforeHeight - 1 == map[j]) {
				int cnt = 0;
				for (int k = j; k < N; k++) {
					if (map[k] != beforeHeight - 1)
						break;
					if (++cnt == X)
						break;
				}
				if (cnt < X)
					return false;
				beforeHeight--;
				size = 0;
				j += X;
			}else {
				return false;
			}
		}
		return true;
	}
}
