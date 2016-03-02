import java.io.*;
import java.util.*;

public class TacoStand
{
    //Function to Sort ingredients.
	public static void sortIngredients(int[] a)
    {
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<3;j++)
			{
				if(a[j+1]>a[j])
				{
					int temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
		}
	}
	
    public static void main(String[] args) 
	{
		int t;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t!=0)
		{
            t--;
            long no=0;
            int[] a=new int[4];
            for(int i=0;i<4;i++)
            {
                a[i]=sc.nextInt();
            }       
            sortIngredients(a);
            if((a[2]+a[3])<a[1])
            {
				no+=a[2];
                a[2]=0;
                a[1]-=no;   
                if(a[1]<=a[3])
                    no+=a[1];
                else
                    no+=a[3];
            }
            else
            {
                no+=a[1];
                no+=(a[2]+a[3]-a[1])/2;
            }        
            if(no<a[0])
                System.out.println(no);
            else
                System.out.println(a[0]);
        }
    }
}