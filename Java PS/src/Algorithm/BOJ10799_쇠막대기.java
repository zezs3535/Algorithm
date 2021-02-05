package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ10799_쇠막대기 {

	static String s;

	static boolean isLaser(int idx) {
		if (s.charAt(idx) == '(' && s.charAt(idx + 1) == ')')
			return true;
		return false;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		s = st.nextToken();
		int cnt = 0;
		int answer = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			if(s.charAt(i)=='(') {
				if(isLaser(i)){
					answer+=cnt;
					i++;
					continue;
				}
				cnt++;
			}
			else {
				answer++;
				if(cnt<=0)cnt=0;
				else {
					cnt--;
				}
			}
		}
		if(!isLaser(s.length()-2))answer++;
		bw.write(answer+" ");
		br.close();
		bw.flush();
		bw.close();
	}

}
