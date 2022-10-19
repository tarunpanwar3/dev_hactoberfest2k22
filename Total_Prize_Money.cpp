#include <iostream>
using namespace std;

void calc(int a,int b)
{
    cout<<(a*10)+(b*90)<<"\n";
    return;
}

int main() {
	// your code goes here
	int i,n,x,y;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>x>>y;
	    calc(x,y);
	    
	}
	return 0;
}
