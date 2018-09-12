	#include <bits/stdc++.h>
	using namespace std;
#define mod1 1000000007
typedef long long ll;
map<ll,ll> mapa;
ll has(string cad)
{
	ll total=0LL;
	for(int p=0; p<cad.size(); p++)
	{
		//total+=((((total)*29)%mod1)+(cad[i]-'a'))%mod1;
		if(cad[p]=='0')
			total = ( total * 11  + (10) ) ;
		else
			total = ( total * 11 + (cad[p] - '0') ) ;
	}
	return total;
}

int main()
{
	vector<pair<int,string>> numeros;
	int casos;
	cin>>casos;
	ll busca;
	for(int z=0; z<casos; z++)
	{
		int total;
		cin>>total;
		for(int i=0; i<total; i++)
		{
			string aux;
			cin>>aux;
			pair<int,string> dos;
			dos.first=aux.size();
			dos.second=aux;
			numeros.push_back(dos); 
		}
		//int ban=0;
		ll potencia=1;
		for(int i=0; i<total; i++)
		{

			string nuevo;
			
			
			//mapa[busca]=1;
			for(int j=1; j<numeros[i].first; j++)
				{

					string nuevo=numeros[i].second.substr(0,j);
					 busca=has(nuevo);
					//cout<<nuevo<<"  con has: "<<busca<<endl;
					mapa[busca]=1;
				}

		}
		int ban=0;
		//cout<<endl;
		for(int i=0; i< total; i++)
		{
			ll nuevo=has(numeros[i].second);
			//cout<<"  numero: "<<numeros[i].second<<" con has: "<<nuevo<<endl;
			if(mapa[nuevo]==1)
			{
				cout<<"NO"<<endl;
				ban=1;
				break;
			}
		}
		if (ban==0)
		{
			cout<<"YES"<<endl;

		}
		mapa.clear();
		numeros.clear();
	}
	return 0;
}