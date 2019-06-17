#include <bits/stdc++.h>
#include "arvore.cpp"
#include "trie.cpp"
#include "dicion.h"


#define MAX 10000

using namespace std;

void gerar_arquivo(){
    int ID;
    string nomes[] = {"Alice","Miguel","Sophia","Arthur","Júlia","Davi","Laura","Pedro","Isabella","Bernardo","Manuela","Gabriel","Luiza","Lucas","Helena","Matheus","Valentina","Heitor","Giovanna","Rafael","Maria","Eduarda","Enzo","Beatriz","Nicolas","Maria","Clara","Lorenzo","Maria","Luiza","Guilherme","Heloísa","Samuel","Mariana","Theo","Lara","Felipe","Lívia","Gustavo","Lorena","Henrique","Ana","Clara","João","Pedro","Isadora","João","Lucas","Rafaela","Daniel","Sarah","Murilo","Yasmin","Vitor","Ana","Luiza","Pedro","Henrique","Letícia","Eduardo","Nicole","Leonardo","Gabriela","Pietro","Isabelly","Benjamin","Melissa","Isaac","Cecília","João","Esther","Joaquim","Ana","Júlia","Lucca","Emanuelly","Caio","Clara","Vinicius","Marina","Cauã","Rebeca","Bryan","Vitória","João","Miguel","Isis","Vicente","Lavínia","Francisco","Maria","Antônio","Bianca","Benício","Ana","Beatriz","João","Vitor","Larissa","Enzo","Gabriel","Maria","Fernanda","Davi","Lucas","Catarina","Davi","Lucca","Alícia","Thiago","Maria","Alice","Thomas","Amanda","Emanuel","Ana","Enrico"};
    string idade[] = {"18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50"};
    string genero_favorito[] = {"ação", "comedia","terror","drama","comedia_romantica","sci-fi","suspense"};
    string filme_favorito[] = {"Os Sete Samurais (1954)","Bonnie e Clyde – Uma Rajada de Balas (1967)","Cães de Aluguel (1992)","Apertem os Cintos… O Piloto Sumiu (1980)","O Labirinto do Fauno (2006)","Doutor Jivago (1965)","O Franco-Atirador (1978)","Contatos Imediatos de Terceiro Grau (1977)","Up – Altas Aventuras (2009)","Rocky, um Lutador (1976)","Amnésia (2000)","Coração Valente (1995)","Quem Quer Ser um Milionário? (2008)","Senhor dos Anéis: O Retorno do Rei (2003)","A Bela e a Fera (1991)","Seven – Os Sete Crimes Capitais (1995)","A Origem (2010)","Duro de Matar (1988)","Senhor dos Anéis: A Sociedade do Anel (2001)","Amadeus (1984)","Sindicato de Ladrões (1954)","Wall-E (2008)","12 Homens e uma Sentença (1957)","Os Caça-Fantasmas (1984)","O Segredo de Brokeback Mountain (2005)","A Ponte do Rio Kwai (1957)","Banzé no Oeste (1974)","Todos os Homens do Presidente (1976)","O Jovem Frankenstein (1974)","Quase Famosos (2000)","Um Corpo que Cai (1958)","Gladiador (2000)","Monty Python Em Busca do Cálice Sagrado (1975)","Avatar (2009)","O Rei Leão (1994)","Touro Indomável (1980)","Mary Poppins (1964)","Feitiço do Tempo (1993)","Intriga Internacional (1959)","Amor, Sublime Amor (1961)","O Fabuloso Destino de Amélie Poulain (2001)","Thelma & Louise (1991)","Crepúsculo dos Deuses (1950)","Batman: O Cavaleiro das Trevas (2008)","Brilho Eterno de uma Mente sem Lembranças (2004)","Taxi Driver – Motorista de Táxi (1976)","Butch Cassidy (1969)","Gênio Indomável (1997)","A Malvada (1950)","O Grande Lebowski (1998)","Jurassic Park: O Parque dos Dinossauros (1993)","Janela Indiscreta (1954)","Os Suspeitos (1995)","Quanto Mais Quente Melhor (1959)","O Resgate do Soldado Ryan (1998)","Titanic (1997)","Matrix (1999)","Toy Story (1995)","Alien, o Oitavo Passageiro (1979)","Psicose (1960)","Clube da Luta (1999)","O Iluminado (1980)","Harry e Sally – Feitos Um para o Outro (1989)","Dr. Fantástico (1964)","Curtindo a Vida Adoidado (1986)","Laranja Mecânica (1971)","Beleza Americana (1999)","Fargo (1996)","Star Wars: O Império Contra-Ataca (1980)","A Princesa Prometida (1987)","Um Estranho no Ninho (1975)","Blade Runner, o Caçador de Andróides (1982)","A Primeira Noite de um Homem (1967)","Clube dos Cinco (1985)","Cantando na Chuva (1952)","A Noviça Rebelde (1965)","Tubarão (1975)","Lawrence da Arábia (1962)","O Silêncio dos Inocentes (1991)","Chinatown (1974)","A Felicidade Não se Compra (1946)","Os Bons Companheiros (1990)","Noivo Neurótico, Noiva Nervosa (1977)","Apocalypse Now (1979)","O Sol é Para Todos (1962)","…E o Vento Levou (1939)","Forrest Gump: O Contador de Histórias (1994)","Indiana Jones e os Caçadores da Arca Perdida (1981)","De Volta Para o Futuro (1985)","Star Wars: Uma Nova Esperança (1977)","A Lista de Schindler (1993)","2001: Uma Odisséia no Espaço (1968)","E.T. – O Extraterrestre (1982)","O Poderoso Chefão: Parte II (1974)","Casablanca (1942)","Pulp Fiction – Tempo de Violência (1994)","Um Sonho de Liberdade (1994)","Cidadão Kane (1941)","O Mágico de Oz (1939)","O Poderoso Chefão (1972)"};
    string guilty_pleasure[] = {"Click","The Room","Independence Day","Road House","Dirty Dancing","Grease","Ghostbusters","Starship Troopers","Con Air","Armageddon","Point Break","The Lost Boys","Ace Ventura: Pet Detective","Spaceballs","Top Gun","Clue","The Karate Kid","Piratas do Caribe: Pérola Negra","Nationa Lampoon's Christmas Vacation","Face/Off","Rocky IV","Footloose","Smokey and the Bandit","The Naked Gun","Bill & Ted's excellent adventure","Willy wonka & the chocolate factory","Commando","Home alone","Indiana Jones and the Last crusade","The fast and the furious"};

    fstream file;
	file.open("bank.dat",ios::out|ios::binary);//abrir arquivo para escrita
	if(!file){//ver se foi possível criar aruqivo
		cout<<"Error in creating file...\n";
		return;
	}
    string men;

    file.write("\n",1);
    for(int x=0; x < MAX ; x++){
        men = nomes[rand() % nomes.size()];
        men += "  Idade  ";
        men += idade[rand() % 10];
        men += "  Genero Favorito  ";
        men += genero_favorito[rand() % 2];
        men += "  Filme Favorito  ";
        men += filme_favorito[rand() % 2];
        men += "  Guilty Pleasure  ";
        men += guilty_pleasure[rand() % 2];
        men += "\n";
        //file.write(to_string(x).c_str(), to_string(x).size() );  //Todas as categorias serão lidas como uma única descrição, inclusive as categorias.
        //file.write(":",1);
        file.write(men.c_str(),men.size());//escreve men no arquivo
        cout << (x*100)/MAX << "% COMPLETO" << endl;
        cout.flush();
    }
    cout << ">> ARQUIVO GERADO COM SUCESSO, SALVANDO DATA" << endl;
    file.close();
    return;
}


void alimenta_arvore_completa(/*arvore*/){

    fstream file;
    file.open("bank.dat", ios::in | ios::binary);// abrir arquivo para leitura

    char x;
    int aux_arv=0;
    int end=0;

    string entrada;
    for(int gps=1;true;gps++){
        file.seekp(gps, ios::beg);
        file.read(&x,sizeof(char));
        if(x=='\n'){
            end++;
            if(end==MAX) return;
        }


        string EID,Enome,Eidade,Egenero_favorito,Eguilty_pleasure,Efilme_favorito = "";
        if(x!=':' && x!='\n'){
            entrada += x;
        }
        else if(x==':' || x=='\n'){
            switch (aux_arv){
                case 0:
                    cout << entrada << " ";
                    EID = entrada;
                    break;
                case 1:
                    Enome = entrada;
                    break;
                case 2:
                    Eidade = entrada;
                    break;
                case 3:
                    Egenero_favorito = entrada;
                    break;
                case 4:
                    Efilme_favorito = entrada;
                    break;
                case 5:
                    Eguilty_pleasure = entrada;
                    break;
            }
            inserir(EID,Enome,Eidade,Egenero_favorito,Efilme_favorito,Eguilty_pleasure);
            if(aux_arv<5)aux_arv++;
            else aux_arv=0;
            entrada = "";
        }
    }
    file.read(&x,sizeof(char));
    cout << x;
    file.close();
    return;
}

void alimenta_arvore(/*arvore,*/int id){
    fstream file;
    file.open("bank.dat", ios::in | ios::binary);// abrir arquivo para leitura

    char x;
	
    string procura;
    for(int gps=0;true;gps++){
        procura = "";
        file.seekp(gps, ios::beg);
        file.read(&x,sizeof(char));
        if(x=='\n'){
            int tamanho = to_string(id).size();
            if( to_string(id).size()%10 != 0) tamanho++;
            for(int aux=1; aux <= tamanho ; aux++){
                file.seekp(gps+aux, ios::beg);
                file.read(&x,sizeof(char));
                procura+=x;
            }
            if(atoi(procura.c_str())==id){
                int aux_arv=0;

                string entrada;
                gps++;
                for(;true;gps++){
                    file.seekp(gps, ios::beg);
                    file.read(&x,sizeof(char));
                    if(x!=':' && x!='\n'){
                        entrada += x;
                    }
                    else if(x==':' || x=='\n'){
                        switch (aux_arv){
                            case 0:
                                cout << entrada << " ";
                                //arvore->ID = atoi(entrada); //atoi é pra transformar string em int
                                break;
                            case 1:
                                cout << entrada << " ";
                                //arvore->nome = entrada;
                                break;
                            case 2:
                                cout << entrada << " ";
                                //arvore->idade = entrada;
                                break;
                            case 3:
                                cout << entrada << " ";
                                //arvore->genero_favorito = entrada;
                                break;
                            case 4:
                                cout << entrada << " ";
                                //arvore->filme_favorito = entrada;
                                break;
                            case 5:
                                cout << entrada << " " << endl;
                                //arvore->guilty_pleasure = entrada;
                                return;
                        }
                        if(aux_arv<5)aux_arv++;
                        else aux_arv=0;
                        entrada = "";
                    }
                }
            }
        }
    }
}



// essa função não funciona, pelo menos tentamos :'(
// void deleta_do_arquivo(int id){
//     fstream file;
//     file.open("bank.dat", ios::in | ios::binary);

//     char x;

//     string procura;
//     for(int gps=0;true;gps++){
//         procura = "";
//         file.seekp(gps, ios::beg);
//         file.read(&x,sizeof(char));
//         if(x=='\n'){
//             int tamanho = to_string(id).size();
//             int aux;
//             for(aux=0; aux <= tamanho ; aux++){
//                 file.seekp(gps+aux, ios::beg);
//                 file.read(&x,sizeof(char));
//                 procura+=x;
//             }
//             if(atoi(procura.c_str())==id){
//                 gps++;
//                 for(int gps_f=0;true;gps_f++){
//                     file.seekp(gps+gps_f, ios::beg);
//                     file.read(&x,sizeof(char));
//                     if(x=='\n'){
//                         file.close();
//                         file.open("bank.dat",ios::out|ios::binary);
//                         //for(int aux = gps;gps<aux+gps_f;gps++){
//                         file.seekp(gps, ios::beg);
//                         file.put('\0');
//                         //}
//                         file.close();
//                         return;
//                     }
//                 }
//             }
//         }
//     }
// }
