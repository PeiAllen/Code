import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        while(t-->0){
            int n=in.nextInt();
            int m=in.nextInt();
            char[] type= new char[2];
            type[0]='.';
            type[1]='.';
            in.nextLine();
            boolean poss=true;
            for(int i=0;i<n;i++){
                String a=in.nextLine();
                for(int j=0;j<m;j++){
                    if(a.charAt(j)!='.'){
                        if(type[(i+j)%2]=='.')type[(i+j)%2]=a.charAt(j);
                        else poss&=(type[(i+j)%2]==a.charAt(j));
                    }
                }
            }
            if(!poss||(type[0]==type[1]&&type[0]!='.')){
                System.out.println("no");
            }
            else{
                System.out.println("yes");
                if(type[0]=='.')type[0]=(type[1]=='R'?'W':'R');
                if(type[1]=='.')type[1]=(type[0]=='R'?'W':'R');
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        System.out.print(type[(i+j)%2]);
                    }
                    System.out.println();
                }
            }
        }
	}
}