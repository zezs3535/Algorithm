package Algorithm;

public class BOJ4673_셀프넘버 {

	public static void main(String[] args) throws Exception {
		int[] arr = new int[10001];
		for (int i = 1; i <= 10000; i++) {
			int num = i;
			int sum = num;
			while (num != 0) {
				sum += (num % 10);
				num /= 10;
			}
			if (sum <= 10000)
				arr[sum] = 1;
		}
		for (int i = 1; i <= 10000; i++) {
			if (arr[i] == 0)
				System.out.println(i);
		}
	}
}
