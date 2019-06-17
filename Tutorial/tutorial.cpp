#include <bits/stdc++.h>

#define FILE_NAME "bank.dat"

using namespace std;

int main(void){
    //como escrever em arquivo binário
    fstream file;
	file.open("bank.dat",ios::out|ios::binary);//abrir arquivo para escrita
	if(!file){
		cout<<"Error in creating file...\n";
		return -1;
	}
    string men = "CATESTESTES";
    file.write(men.c_str(),men.size());
    file.close();


    //Como ler a partir de arquivo binário
    char x;
    file.open("bank.dat", ios::in | ios::binary);// abrir arquivo para leitura
    file.seekp(5, ios::beg); // movimentação dentro do arquivo
    file.seekp(3, ios::beg);
    file.seekp(1, ios::beg);
    file.read(&x,sizeof(char));
    cout << x;
    file.close();
    return 0;
}