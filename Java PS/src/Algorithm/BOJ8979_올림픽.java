package Algorithm;

import java.io.FileInputStream;
import java.util.Scanner;

public class BOJ8979_올림픽 {
	
	static class Country{
		int order = 0;
		int gold = 0;
		int silver = 0;
		int bronze = 0;
		
		public Country(int order, int gold, int silver, int bronze) {
			super();
			this.order = order;
			this.gold = gold;
			this.silver = silver;
			this.bronze = bronze;
		}
	}
	
	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int cnt = 0;
		Country ans = new Country(0,0,0,0);
		Country[] countries = new Country[n];
		
		for(int i=0;i<n;i++) {
			int o = sc.nextInt(); //order
			int g = sc.nextInt(); //gold
			int s = sc.nextInt(); //silver 
			int b = sc.nextInt(); //bronze
			if(o==k) {
				ans = new Country(o,g,s,b);
			}
			countries[i] = new Country(o,g,s,b);
		}
		
		for(int i=0;i<n;i++) {
			
			if(countries[i].gold>ans.gold) {
				cnt++;
			} else if(countries[i].gold == ans.gold && countries[i].silver > ans.silver) {
				cnt++;
			} else if(countries[i].gold == ans.gold && countries[i].silver == ans.silver && countries[i].bronze > ans.bronze) {
				cnt++;
			}
		}
		System.out.println(cnt+1);
	}
}
