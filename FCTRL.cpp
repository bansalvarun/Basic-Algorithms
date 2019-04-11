#include <iostream>
using namespace std;

int main(){
	int t,n,i,zeros;
	cin>>t;
	while(t){
		cin>>n;
		zeros = 0;
		i = 5;
		while(i<=n){
			zeros = zeros + (n/i);
			i = i*5;
		}
		cout<<zeros<<endl;
		t--;
	}
	return 0;
}