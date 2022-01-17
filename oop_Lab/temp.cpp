#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,q;
	cin>>t;
	while(t--){
		cin>>n>>q;
		vector<pair<int,int>> range(n);
		vector<int> k(q);
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			range[i]={a,b};
		}
		for(int i=0;i<q;i++){
			cin>>k[i];
		}
		for(int i=0;i<n;i++){
			int a=range[i].first, b=range[i].second, t=a-1;
			a-=t;b-=t;
			for(int j=0;j<q;j++){
				if(k>b) cout<<"-1"<<endl;
				else{
					if(t>0)
					cout<<to_string(k+t)<<endl;
				}
			}
		}
	}
	return 0;
}
