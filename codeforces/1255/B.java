import java.util.Scanner;
import java.util.Arrays;
public class class1 
{

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		int t= sc.nextInt();
		while(t-->0)
		{
			int n,m;
			n=sc.nextInt();
			m=sc.nextInt();
			long[] a;
			a= new long[n];
			for(int i=0;i<n;i++)
			{
				a[i]=sc.nextInt();
			}
			
			if(m<n)
			{
				System.out.println(-1);
				continue;
			}
			
			if(n==2)
			{
				System.out.println(-1);
				continue;
			}
			long ans=0;
			for(long i:a)
			{
				ans+=i;
			}
			ans*=2;
			m-=n;
			long first=1,second=1;
			long mi=a[0];
			for(int i=0;i<n;i++)
			{
				if(mi>a[i])
				{
					first=i+1;
				}
			}
			
			for(int i=0;i<n;i++)
			{
				if(mi>a[i] && i!= first)
				{
					second=i+1;
				}
			}
			Arrays.sort(a);
			ans+=m*(a[0]+a[1]);
			System.out.println(ans);
			for(int i=1;i<n;i++)
				System.out.println(i+" "+(i+1));
			System.out.println(1+" "+(n));
			for(int i=0;i<m;i++)
				System.out.println(first+" "+(second));
			
		}
       
        
    
    }
}
