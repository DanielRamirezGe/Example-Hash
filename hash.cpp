#include <bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod2 1000000003
map <int, int> mapa;
long long mult(long long mul,int veces,int con)
{
	if(veces==con)
		return mul%mod1;
	con++;
	mul=(mul*mul)%mod1;
	return mult(mul,veces,con);

}
long long busca( long long otro,char letra,char quitar,long long pot)
{
	//cout<<endl<<endl;
		long long valor;
		//long long por=mult(29,cad.size()-1,1);
		//cout<<renglon[i]<<"   valor:  "<<(((renglon[i-1]))%mod1)<<"  por: "<<por<<"  La suma:  "<<(renglon[cad.size()+i]*29)%mod1<<endl;
		valor=(((((otro-((quitar-'a')*pot)+mod1))%mod1)*29)%mod1)+letra-'a';

	return valor;
}
long long hah(string cad,int con,long long val) 
{
	if(con == cad.size())
		return val;

	con++;
	val=(((val * 29) % mod1) + (cad[con]-'a')) % mod1;
	return hah(cad, con, val);
}	
int main()
{
 	int casos;
 	cin>> casos;
 	int renglones,columnas;
 	cin>> renglones;
 	cin>> columnas;
 	vector<string> mat;
 	for(int i=0; i< renglones; i++)
 	{
 		string aux;
 		cin>>aux;
 		mat.push_back(aux);
 	}
 	int consulta;
 	cin>>consulta;

 	for(int i=0; i< consulta; i++)
 	{
 		string aux,palabra;
 		cin>>aux;
 		for(int u=0; u<aux.size(); u++)
 		{
 			if(aux[u]<'a')
 				palabra.push_back(aux[u]+32);
 			else
 				palabra.push_back(aux[u]);
 		}
 		long long normal=hah(palabra,-1,0);
 		mapa[normal]=1;
 		string otro;
 		for(int h=0; h< palabra.size(); h++)
 		{
 			char let;
 			if(mat[0][h]<97)
 				let=mat[0][h]+32;
 			else
 				let=mat[0][h];
 			otro.push_back(let);
 		}
 		cout<<" la primera palabra: "<<otro<<" a buscar: "<<palabra<<endl; 		
 		long long cambia=hah(otro,-1,0);
 		cout<<" has de palabra: "<<normal<<"  cambia: "<<cambia<<endl;
 		long long pot=mult(29,palabra.size()-1,2);
 		cout<<" potencia:  "<<pot<<endl;
 		//cout<<"Aqui....   mapa: "<<mapa[normal]<<"    has: "<<normal<<"   segundo: "<<segundo<<endl;
 		if(cambia!=normal)
 		{	
	 		for(int y=0; y<(mat[0].size()/2)+1; y++)
		 	{
		 		string sol;
		 		for(int p=y; p< palabra.size()+y; p++)
		 		{
		 			if(mat[0][p]<'a')
		 			sol.push_back(mat[0][p]+32);
		 			else
		 			sol.push_back(mat[0][p]);
		 		}
		 		long long vas=hah(sol,-1,0);
		 		cout<<"palabra otro: "<<sol<<"  has otro: "<<vas<<endl<<endl;
		 		char poner,quitar;
		 		if(mat[0][palabra.size()+y]<'a')
		 		{
		 			poner=mat[0][palabra.size()+y]+32;
		 		}
		 		else
		 		{
		 			poner=mat[0][palabra.size()+y];
		 		}
		 		if(mat[0][y]<'a')
		 		{
		 			quitar=mat[0][y]+32;
		 		}
		 		else
		 		{
		 			quitar=mat[0][y];
		 		}
		 		cout<<" has anterior: "<<cambia<<"  pone: "<<poner<<"  quita: "<<quitar<<endl;
		 		cambia=busca(cambia,poner,quitar,pot);
		 		if(cambia==normal)
		 		{
		 			cout<<"  Se encontro: "<<y<<endl;
		 			break;
		 		}
		 	}
		 	cout<<"no se encontro"<<endl;
		}
		cout<<"  Se encontro: 1"<<endl;

		
 		
 	}
 	return 0;
}