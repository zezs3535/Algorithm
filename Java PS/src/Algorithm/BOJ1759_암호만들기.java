package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ1759_암호만들기 {
	static char[] mo = {'a','e','i','o','u'};
	static int l;
	static int c;
	static char[] word;
	static ArrayList<char[]> answer = new ArrayList<>();
	static void comb(int idx, int k, char[] sel) {
		if(k==sel.length) {
			int mcnt=0;
			int jcnt=0;
			for(int i=0;i<sel.length;i++) {
				boolean isMo=false;
				for(int j=0;j<5;j++) {
					if(sel[i]==mo[j]) {
						mcnt++;
						isMo=true;
						break;
					}
				}
				if(!isMo)jcnt++;
			}
			
			if(jcnt>1 && mcnt>0) {
				char[] tmp = new char[sel.length];
				for(int i=0;i<sel.length;i++) {
					tmp[i]=sel[i];
				}
				answer.add(tmp);
			}
			return;
		}
		if(idx==word.length)return;
		sel[k]=word[idx];
		comb(idx+1,k+1,sel);
		comb(idx+1,k,sel);
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		word=new char[c];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<c;i++) {
			word[i]=st.nextToken().charAt(0);
		}
		Arrays.sort(word);
		comb(0,0,new char[l]);
		Collections.sort(answer, new Comparator<char[]>(){
			@Override
			public int compare(char[] o1, char[] o2) {
				for(int i=0;i<o1.length;i++) {
					if(o1[i]==o2[i]) {
						continue;
					}
					return o1[i]-o2[i];
				}
				return 0;
			}
		});
		for(int i=0;i<answer.size();i++) {
			bw.write(answer.get(i));
			bw.write("\n");
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
