package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

//상어 큐에 상어들을 저장하면서, 상어pos 큐에도 상어의 위치를 저장한다
//상어pos를 돌며 배열에 저장했다가 뭐 잡아먹히고 처리한다음 상어pos만큼 돌면서
//배열에서 지우고 상어큐에 저장.. 반복

public class BOJ17143_낚시왕 {
	static class Pos {
		int r;
		int c;

		public Pos(int r, int c) {
			super();
			this.r = r;
			this.c = c;
		}

	}

	static class Shark {
		int r;
		int c;
		int s;
		int d;
		int z;

		public Shark() {
			super();
		}

		public Shark(int r, int c, int s, int d, int z) {
			super();
			this.r = r;
			this.c = c;
			this.s = s;
			this.d = d;
			this.z = z;
		}
	}

	static int[] dy = { -1, 1, 0, 0 };
	static int[] dx = { 0, 0, 1, -1 };
	static int n, m, sharkCnt;
	static Shark[][] arr;
	static Queue<Shark> shark;
	static Queue<Pos> sharkPos;
	static int ans = 0;

	static void fishing(int idx) {
		int killy = -1;
		int killx = -1;
		for (int i = 0; i < n; i++) {
			if (arr[i][idx].z > 0) { // 상어 만나면 죽임
				ans+=arr[i][idx].z;
				arr[i][idx] = new Shark();
				killy = i;
				killx = idx;
				break;
			}
		}
		if (killy >= 0 && killx >= 0) {
			int qsize = sharkPos.size(); // 죽은 위치가 들어있는 queue에서 pop
			for (int i = 0; i < qsize; i++) {
				Pos tmp = sharkPos.poll();
				if (tmp.r == killy && tmp.c == killx) {
					continue;
				} else {
					sharkPos.add(tmp);
				}
			}
		}
	}

	static void sharkMove() { // sharkPos에 있는 배열의 값 초기화하면서 상어큐로, 다 옮기면 다시 움직인값으로 배열로
		int qsize = sharkPos.size();
		for (int i = 0; i < qsize; i++) {
			Pos tmp = sharkPos.poll();
			shark.add(arr[tmp.r][tmp.c]); // 큐에 넣고
			arr[tmp.r][tmp.c] = new Shark(); // 배열 초기화
		}
		while (!shark.isEmpty()) {
			Shark tmp = shark.poll();
			int moveCnt = 0;
			if (tmp.d < 2) {
				moveCnt = tmp.s % (2 * n - 2);
			} else {
				moveCnt = tmp.s % (2 * m - 2);
			}
			for (int i = 0; i < moveCnt; i++) {
				if (tmp.r + dy[tmp.d] >= n || tmp.r + dy[tmp.d] < 0 || tmp.c + dx[tmp.d] >= m || tmp.c + dx[tmp.d] < 0) { // 경계선 나가면
					if (tmp.d % 2 == 0)
						tmp.d+=1;
					else {
						tmp.d-=1;
					}
				}
				tmp.r = tmp.r + dy[tmp.d];
				tmp.c = tmp.c + dx[tmp.d];
			}
			if (arr[tmp.r][tmp.c].z < tmp.z) {
				arr[tmp.r][tmp.c] = tmp;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j].z > 0) {
					sharkPos.add(new Pos(i,j));
				}
			}
		}
	}

	static void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(arr[i][j].z);
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		shark = new LinkedList<>();
		sharkPos = new LinkedList<>();

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		sharkCnt = Integer.parseInt(st.nextToken());
		arr = new Shark[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = new Shark();
			}
		}

		for (int i = 0; i < sharkCnt; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			r--;
			c--;
			d--;
			sharkPos.add(new Pos(r, c));
			arr[r][c] = new Shark(r, c, s, d, z);
		}
		for (int i = 0; i < m; i++) {
			// 낚시
			fishing(i);
			// 상어 이동
			sharkMove();
		}
		bw.write(ans + "");
		br.close();
		bw.flush();
		bw.close();
	}
}
