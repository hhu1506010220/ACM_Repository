#include<bits/#include<iostream>>                                                             
using namespace std;                                                            
int main()                                                                      
{                                                                               
	int n,i,*fib;                                                                  
	cin>>n;                                                                        
	if(n==1||n==2)                                                                 
		cout<<"1"<<endl;                                                              
	else                                                                           
	{                                                                              
		fib=new int[n];                                                               
		fib[0]=fib[1]=1;                                                              
		for(i=2;i<n;i++)                                                              
			fib[i]=fib[i-2]+fib[i-1];                                                    
	                    cout<<fib[n-1]<<endl;                                      
		delete[] fib;                                                                 
	}                                                                              
	return 0;                                                                      
}  >
