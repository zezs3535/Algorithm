package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ18310_안테나 {
	// 평균 지점에서 왼쪽, 오른쪽으로 쭉 가면서 더 작아지는지 확인
	// 더 안작아지면 break 한 뒤 왼쪽idx와 오른쪽idx 값 비교
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		long[] arr = new long[t];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < t; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);

		long ans = 0;
		long sum = 0;
		for (int i = 0; i < t; i++) {
			sum += arr[i];
		}

		long avg = sum / t;
		int startIdx = 0;
		long min = 1000001;
		for (int i = 0; i < t; i++) {
			if (Math.abs(avg - arr[i]) <= min) {
				min = Math.abs(avg - arr[i]);
				startIdx = i;
			}
		}

		for (int i = 0; i < t; i++) {
			ans += (Math.abs(arr[startIdx] - arr[i]));
		}

		int leftIdx = startIdx - 1;
		int rightIdx = startIdx + 1;
		boolean flag = false;
		
		long minLeft = ans;
		while (true) {
			if (leftIdx < 0)break;
			long tmp = 0;
			for(int i=0;i<t;i++) {
				tmp += (Math.abs(arr[leftIdx] - arr[i]));
			}
			if(tmp<=minLeft) {
				minLeft = tmp;
				leftIdx--;
				flag = true;
			}
			else {
				break;
			}
		}

		long minRight = ans;
		while (true) {
			if (rightIdx >= t)break;
			long tmp = 0;
 			for(int i=0;i<t;i++) {
				tmp += (Math.abs(arr[rightIdx] - arr[i]));
			}
			if(tmp<=minRight) {
				minRight = tmp;
				rightIdx++;
				flag = true;
			}
			else {
				break;
			}
		}
		
		if(!flag)bw.write(arr[startIdx]+"");
		else {
			if(minLeft<=minRight)bw.write(arr[leftIdx+1]+"");
			else {
				bw.write(arr[rightIdx-1]+"");
			}
		}
		
		br.close();
		bw.flush();
		bw.close();
	}
}
