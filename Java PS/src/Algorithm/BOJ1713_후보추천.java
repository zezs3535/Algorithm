package Algorithm;

import java.io.FileInputStream;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ1713_후보추천 {

	static class Student implements Comparable<Student> {

		int num = 0;
		int recCnt = 0;
		int idx = 0;

		@Override
		public int compareTo(Student o) {
			if (this.recCnt > o.recCnt)
				return 1;
			else if (this.recCnt == o.recCnt) {
				return this.idx > o.idx ? 1 : -1;
			} else
				return -1;
		}

		public Student(int num, int recCnt, int idx) {
			super();
			this.num = num;
			this.recCnt = recCnt;
			this.idx = idx;
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		PriorityQueue<Student> pq = new PriorityQueue<>();
		PriorityQueue<Student> pqTmp = new PriorityQueue<>();
		PriorityQueue<Integer> ans = new PriorityQueue<>();
		int k = sc.nextInt(); // 사진틀
		int n = sc.nextInt();
		int rec = 0;
		for (int i = 0; i < n; i++) {
			rec = sc.nextInt(); // 추천받은 학생
			if (pq.isEmpty()) { // 비어있을때
				pq.add(new Student(rec, 1, i));
			} else { // 비어있지 않을때
				boolean flag = false;
				for (int j = 0; j < k; j++) {
					if (pq.isEmpty()) //사진틀 탐색하다가 큐가 비었을때
						break;
					Student tmp = pq.poll();
					if (tmp.num == rec) { // 사진틀에 이미 있을때
						Student tmp2 = new Student(rec, tmp.recCnt + 1, tmp.idx);
						pq.add(tmp2);
						flag = true;
						break;
					}
					pqTmp.add(tmp);
				}
				while (!pqTmp.isEmpty()) {
					Student tmp = pqTmp.poll();
					pq.add(tmp);
				}
				if (!flag) { //추천받은 학생이 사진틀에 없는 경우
					if (pq.size() < k) //자리가 남으면 바로 넣고
						pq.add(new Student(rec, 1, i));
					else { //자리가 남지 않으면 우선순위가 높은 학생을 빼고 방금 추천받은 학생을 넣는다.
						pq.poll();
						pq.add(new Student(rec, 1, i));
					}
				}
			}
		}
		while (!pq.isEmpty()) {
			int answer = pq.poll().num;
			ans.add(answer);
		}
		while (!ans.isEmpty()) {
			System.out.print(ans.poll() + " ");
		}
	}
}
