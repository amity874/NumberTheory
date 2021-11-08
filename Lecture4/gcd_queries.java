import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().replaceAll("\\s",""));
		for(int i=0; i<t; i++){
		    StringTokenizer st = new StringTokenizer(br.readLine());
		    int n = Integer.parseInt(st.nextToken());
		    int q = Integer.parseInt(st.nextToken());
		    
		    int[] arr = new int[n+1];
		    st = new StringTokenizer(br.readLine());
		    for(int a=1;a<=n; a++){
		        arr[a] = Integer.parseInt(st.nextToken());
		    }
		    int[] prefix = new int[n+2];
		    int[] suffix = new int[n+2];
		    prefix[1] = arr[1];
		    for(int p=2; p<=n; p++){
		        prefix[p] = findGCD(prefix[p-1], arr[p]);
		    }
		    suffix[n] = arr[n];
		    for(int s=n-1; s>0; s--){
		        suffix[s] = findGCD(suffix[s+1], arr[s]);
		    }
		    
		    for(int j=0; j<q; j++){
		        st = new StringTokenizer(br.readLine());
		        int l = Integer.parseInt(st.nextToken());
		        int r = Integer.parseInt(st.nextToken());
		        System.out.println(findGCD(prefix[l-1], suffix[r+1]));
		    }
		}
		
	}
	
	public static int findGCD(int a, int b){
	    if(b == 0){
	        return a;
	    }
	    return findGCD(b, a%b);
	}
}