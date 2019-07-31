import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author allen
 */
public class CCC08S4TwentyFour {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

public static double calc(double n, ArrayList<Double> cards){
		double highest=0;
		if(cards.isEmpty()){
			return n;
		}
		else{
			for(int i=0;i<cards.size();i++){
				ArrayList<Double> tem=(ArrayList <Double> )cards.clone();
				double temp=cards.get(i);
				tem.remove(i);
				if(n!=0){
					double res=calc(temp/n,tem);
					if(res<=24){
						highest=Math.max(highest, res);
					}
				}
				else if(temp!=0){
					double res=calc(n/temp,tem);
					if(res<=24){
						highest=Math.max(highest, res);
					}
				}
				double res=calc(temp+n,tem);
				if(res<=24){
					highest=Math.max(highest, res);
				}
				res=calc(temp-n,tem);
				if(res<=24){
					highest=Math.max(highest, res);
				}
				res=calc(n-temp,tem);
				if(res<=24){
					highest=Math.max(highest, res);
				}
				res=calc(temp*n,tem);
				if(res<=24){
					highest=Math.max(highest, res);
				}
				if(!tem.isEmpty()){
					if(tem.size()==1&&n>24){
						if(n-temp*tem.get(0)<=24){
							highest=Math.max(highest, n-temp*tem.get(0));
						}
						if(n-(temp+tem.get(0))<=24){
							highest=Math.max(highest, n-(temp+tem.get(0)));
						}
						if(n-(temp-tem.get(0))<=24){
							highest=Math.max(highest, n-(temp-tem.get(0)));
						}
						if(n-(tem.get(0)-temp)<=24){
							highest=Math.max(highest, n-(tem.get(0)-temp));
						}
						if(n-(temp/tem.get(0))<=24){
							highest=Math.max(highest, n-(temp/tem.get(0)));
						}
						if(n-(tem.get(0)/temp)<=24){
							highest=Math.max(highest, n-(tem.get(0)/temp));
						}
					}
					res=calc(temp,tem);
					ArrayList<Double> temp1=new ArrayList<Double>();
					temp1.add(res);
					res=calc(n,temp1);
					if(res<=24){
						highest=Math.max(highest, res);
					}
				}
			}
			return highest;
		}
	}


	/**
	 * @param args the command line arguments
	 */
public static void main(String[] args) throws IOException {
			int n=readInt();
			for(int i=0;i<n;i++){
				ArrayList<Integer> cards = new ArrayList<Integer>();
				for(int j=0;j<4;j++){
					cards.add(readInt());
				}
				int highest=0;
				ArrayList<Integer> temp=(ArrayList <Integer> )cards.clone();
				temp.remove(0);
				highest=Math.max(highest, calc(cards.get(0),temp));
				temp=(ArrayList <Integer> )cards.clone();
				temp.remove(1);
				highest=Math.max(highest, calc(cards.get(1),temp));
				temp=(ArrayList <Integer> )cards.clone();
				temp.remove(2);
				highest=Math.max(highest, calc(cards.get(2),temp));
				temp=(ArrayList <Integer> )cards.clone();
				temp.remove(3);
				highest=Math.max(highest, calc(cards.get(3),temp));
				System.out.println(highest);
			}
	}
	static String next() throws IOException {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine().trim());
			}
			return st.nextToken();
	}

	static long readLong() throws IOException {
			return Long.parseLong(next());
	}

	static int readInt() throws IOException {
			return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
			return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
			return next().charAt(0);
	}

	static String readLine() throws IOException {
			return br.readLine().trim();
	}
}