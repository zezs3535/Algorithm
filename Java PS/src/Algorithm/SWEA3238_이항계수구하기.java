package Algorithm;

import java.util.Scanner;

public class SWEA3238_이항계수구하기 {
	static long n;
	static long r;
	static int MOD;
	static long ans;
	static long[] fact;

	static void comb(long n, long r) {
		while(n>0 && r>0) {
			long N = n % MOD;
			long R = r % MOD;
			if(R>N) {
				ans=0;
				break;
			}
			ans *= fact[(int)N]*power(fact[(int)R]*fact[(int)(N-R)],MOD-2)%MOD;
			ans%=MOD;
			n/=MOD;
			r/=MOD;
		}
	}

	static long power(long x, long y) {
		if (y == 0)
			return 1;
		long h = power(x, y / 2);
		if (y % 2 == 0)
			return (h % MOD) * (h % MOD) % MOD;
		else
			return (h * x % MOD) * (h % MOD) % MOD;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			n = sc.nextLong();
			r = sc.nextLong();
			MOD = sc.nextInt();
			ans = 1L;
			fact = new long[MOD+1];
			fact[0]=1;
			for(int i=1;i<MOD;i++) {
				fact[i]=(fact[i-1]*i)%MOD;
			}
			comb(n, r);
			System.out.println("#" + test + " " + ans);
		}
	}
}
