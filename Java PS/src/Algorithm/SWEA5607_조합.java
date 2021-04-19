package Algorithm;

import java.util.Scanner;

public class SWEA5607_조합 {
	static int n;
	static int r;
	static int MOD = 1234567891;
	
	static long comb(int n, int r) {
		if(r==0)return 1L;
		long[] fac = new long[n+1];
		fac[0]=1;
		for(int i=1;i<=n;i++) {
			fac[i]=fac[i-1]*i%MOD;
		}
		return (fac[n]*power(fac[r],MOD-2)%MOD*power(fac[n-r],MOD-2)%MOD)%MOD;
	}
	
	static long power(long x, long y) {
		long res = 1L;
		x=x%MOD;
		while(y>0) {
			if(y%2==1)res=(res*x)%MOD;
			y=y>>1;
			x=(x*x)%MOD;
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int test = 1; test <= t; test++) {
			n = sc.nextInt();
			r = sc.nextInt();
			long ans = comb(n,r);
			System.out.println("#"+test+" "+ans);
		}
	}
}
