package Algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1755_숫자놀이 {
	static String[] num = {"zero","one","two","three","four","five","six","seven","eight","nine"}; //숫자를 문자열로 변환할 배열
	static String[] numToStr; //숫자를 문자열로 변환한 값을 저장할 배열
	static int[] strToNum; //문자열을 숫자로 변환한 값을 저장할 배열
	static BufferedReader br;
	static BufferedWriter bw;
	static StringTokenizer st;
	
	public static String numToString(int i) { //숫자를 문자열로 변환하는 메소드
		StringBuilder sb = new StringBuilder(); 
		String s="";
		if(i<10) { //한자리 수일때
			s = num[i]; //한자리만 변환함
		}
		else { //두자리 수일때
			sb.append(num[i/10]+" "); //십의자리를 먼저 바꿔주고
			sb.append(num[i%10]); //일의자리를 그다음에 붙여주고
			s=sb.toString(); //문자열 변수 s에 대입
		}
		return s;
	}
	
	public static int stringToNum(String s) { //문자열을 숫자로 변환하는 메소드
		int n=0;
		String[] tmp = s.split(" "); //문자열을 공백을 기준으로 분리
		if(tmp.length>1) { //두자리 수일때
			for(int i=0;i<=9;i++) { //0~9까지 돌면서 맞으면 n에 대입
				if(tmp[0].equals(num[i])) {
					n = i*10;
				}
			}
			for(int i=0;i<=9;i++) { //0~9까지 돌면서 맞으면 n에 대입
				if(tmp[1].equals(num[i])) {
					n += i;
				}
			}
		}
		else { //한자리 수일때
			for(int i=0;i<=9;i++) { //0~9까지 돌면서 맞으면 n에 대입
				if(tmp[0].equals(num[i])) {
					n = i;
				}
			}
		}
		return n;
	}
	
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken()); //수 입력
		int b = Integer.parseInt(st.nextToken()); //수 입력
		numToStr = new String[b-a+1]; //문자열 저장할 배열 할당
		strToNum = new int[b-a+1]; //숫자 저장할 배열 할당
		int idx=0; //배열 인덱스 체크 위한 변수
		for(int i=a;i<=b;i++) {
			numToStr[idx++]=numToString(i); //주어진 a이상 b이하의 숫자를 다 넣는다
		}
		Arrays.sort(numToStr); //문자열 정렬
		for(int i=0;i<idx;i++) {
			strToNum[i] = stringToNum(numToStr[i]); //문자열을 숫자로 변환해서 배열에 넣는다
		}
		for(int i=0;i<strToNum.length;i++) { //정답 출력
			if(i%10==9)bw.write(strToNum[i]+"\n"); //10개씩 끊어서 출력하기 위함
			else{
				bw.write(strToNum[i]+" ");
			}
		}
		bw.flush();
		bw.close();
		br.close();
	}

}
