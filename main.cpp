/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 ∗ UNIFAL − Universidade Federal de Alfenas .
 ∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
 ∗ Trabalho..: BuscaCar
 ∗ Disciplina: AEDS II
 ∗ Professor.: Paulo Alexandre Bressan
 ∗ Aluno.....: Gustavo Fidelis Camilo, Lucas Costa Lima Ferreira e Brandon Afonso de Souza
 * Matrículas: 2021.1.08.043, 2021.1.08.015 e 2021.1.08.045
 ∗ Data......: 03/11/2022
 ∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
// criando a estrutura para armazenar dados
typedef struct Tveiculo {
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia_do_motor;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
  float valor;

} Tveiculo;
// busca o endereco de memoria da placa
Tveiculo *busca(Tveiculo *bd[], int tam, string placa) {
  int i;
  for (i = 0; i < tam; i++) { // percorre todo vetor para encontrar a placa
    if (bd[i]->placa == placa) {
      return bd[i];
    }
  }
  if (i == tam) {
    return NULL;
  }
  return NULL;
}

int busca1(Tveiculo *bd[], int tam,
           string placa) { // busca o indice da posiçao do veiculo no vetor
  int i;
  for (i = 0; i < tam; i++) {
    if (bd[i]->placa == placa) {
      return i;
    }
  }
  if (i == tam) {
    // cout << "não há um carro com essa placa";
  }
  return -1;
}

int inserir(Tveiculo *bd[],
            int *tam) { // cria um novo veiculo para poder adicionar
  if (*tam < 50) {
    string dados;
    int dados_num;
    float dados_numF;
    char conv[2]; // para converter letras em numeros
    cout << "Digite qual a placa do automovel: ";
    cin >> dados;
    int p = busca1(bd, *tam, dados);
    if (p == -1) { // verifica o retorno caso seja -1 o veiculo não existe,
                   // assim é possivel adicionar
      bd[*tam] = new Tveiculo;
      bd[*tam]->placa = dados;
      cout << "Digite o modelo do automovel: ";
      cin >> dados;
      bd[*tam]->modelo = dados;
      cout << "Digite a marca do automovel: ";
      cin >> dados;
      bd[*tam]->marca = dados;
      cout << "Digite o tipo do automovel: ";
      cin >> dados;
      bd[*tam]->tipo = dados;
      cout << "Digite o ano do automovel: ";
      cin >> conv;
      dados_num = atoi(conv);
      bd[*tam]->ano = dados_num;
      cout << "Digite o km do automovel: ";
      cin >> conv;
      dados_num = atoi(conv);
      bd[*tam]->km = dados_num;
      cout << "Digite a potencia do motor do automovel: ";
      cin >> conv;
      dados_numF = atoi(conv);
      bd[*tam]->potencia_do_motor = dados_numF;
      cout << "Digite o tipo combustivel: ";
      cin >> dados;
      bd[*tam]->combustivel = dados;
      cout << "Digite qual o cambio do automovel: ";
      cin >> dados;
      bd[*tam]->cambio = dados;
      cout << "Digite o tipo de direcao do automovel: ";
      cin >> dados;
      bd[*tam]->direcao = dados;
      cout << "Digite qual a cor do automovel: ";
      cin >> dados;
      bd[*tam]->cor = dados;
      cout << "Digite qual numero de portas do automovel: ";
      cin >> conv;
      dados_num = atoi(conv);
      bd[*tam]->portas = dados_num;
      cout << "Digite qual o valor do automovel: ";
      cin >> conv;
      dados_numF = atoi(conv);
      bd[*tam]->valor = dados_numF;
      *tam = *tam + 1;
      return 1;
    } else {
      cout
          << "Nao foi possivel adicionar pois ja existe um carro com essa placa"
          << endl;
      return 0;
    }
  } else {
    cout << "Não foi possivel adicionar o veiculo pois a lista está cheia"
         << endl;
    return 0;
  }
}

int remover(
    Tveiculo *bd[], int *tam,
    string placa) { // empurra todos as posições do vetor para trás, para assim
                    // retirar um sem deixar espaços em branco
  Tveiculo *p = busca(bd, *tam, placa);
  int i = busca1(bd, *tam, placa); // retorna indice
  if (p !=
      NULL) { // se não for NULL o veiculo existe e pode ser removido, assim a
              // partir da posição encontrada sobreescreve o que tava antes.
    for (; i < *tam - 1; i++) {
      bd[i] = bd[i + 1];
    }
    delete (bd[*tam]); // deleta o que estava na ultima posição
    bd[*tam] = NULL;   // aponta para NULL a ultima posicao
    *tam = *tam - 1;
    cout << "Veiculo com a placa  " << placa << " removido." << endl;
    return 1;
  }
  cout << "Veiculo nao foi removido pois nao existe" << endl;
  return 0;
}

void imprime(Tveiculo *bd[], int tam, int min) {
  for (int i = min; i < tam; i++) {
    cout << bd[i]->modelo << " ";
    cout << bd[i]->marca << " ";
    cout << bd[i]->tipo << " ";
    cout << bd[i]->ano << " ";
    cout << bd[i]->km << " ";
    cout << bd[i]->potencia_do_motor << " ";
    cout << bd[i]->combustivel << " ";
    cout << bd[i]->cambio << " ";
    cout << bd[i]->direcao << " ";
    cout << bd[i]->cor << " ";
    cout << bd[i]->portas << " ";
    cout << bd[i]->placa << " ";
    cout << bd[i]->valor << endl;
  }
}

void ordena(Tveiculo *bd[], int tam) {
  Tveiculo *ord[50];

  int i = 0;
  Tveiculo *aux;
  for (; i < tam; i++) { // coloca as placas em outro vetor
    ord[i] = bd[i];
  }
  for (i = 0; i < tam ; i++) { // verifica se o que esta em j é maior no que
                                  // esta em i, trocando as posicoes em seguida
    for (int j = 0; j < i; j++) {
      if (ord[j]->placa > ord[i]->placa) {
        aux = ord[i];
        ord[i] = ord[j];
        ord[j] = aux;
      }
    }
  }
  imprime(ord, tam, 0);
  return;
}

void valoresProx(Tveiculo *bd[], int tam, float valor) {
  Tveiculo *valoresProx[tam];
  int valoresAbs[tam];
  int positions[tam];
//  float menor = abs(bd[0]->valor - valor);
//  float menorAnt = 0;
//  int indiceMenor = 0;
  int i, j;

  // populando o vetor com os valores absolutos
  for (i = 0; i < tam; i++) {
    valoresAbs[i] = abs(bd[i]->valor - valor);
    positions[i] = i;
  }

  // ordenando em ordem crescente os valores absolutos
  for (i = 0; i < tam - 1; i++) {
    for (j = 0; j < i; j++) {
      if (valoresAbs[j] > valoresAbs[i]) {
        int temp = valoresAbs[i];
        int temp2 = positions[i];
        valoresAbs[i] = valoresAbs[j];
        positions[i]  = positions[j]; 
        valoresAbs[j] = temp;
        positions[j]  = temp2;
      }
    }
  }
  
  for(i = 0; i < 10; i++) {
    int x = positions[i];
    cout << "-> R$ " << bd[x]->valor << "  ";
    cout << bd[x]->modelo << " ";
    cout << bd[x]->marca << " ";
    cout << bd[x]->tipo << " ";
    cout << bd[x]->ano << " ";
    cout << bd[x]->km << " ";
    cout << bd[x]->potencia_do_motor << " ";
    cout << bd[x]->combustivel << " ";
    cout << bd[x]->cambio << " ";
    cout << bd[x]->direcao << " ";
    cout << bd[x]->cor << " ";
    cout << bd[x]->portas << " ";
    cout << bd[x]->placa << endl; 
  }
}

void transfere(Tveiculo *bd[], int tam) { // escreve as alterações no txt
  ofstream myfile("BD_veiculos.txt");
  for (int i = 0; i < tam; i++) {
    myfile << bd[i]->modelo << " ";
    myfile << bd[i]->marca << " ";
    myfile << bd[i]->tipo << " ";
    myfile << bd[i]->ano << " ";
    myfile << bd[i]->km << " ";
    myfile << bd[i]->potencia_do_motor << " ";
    myfile << bd[i]->combustivel << " ";
    myfile << bd[i]->cambio << " ";
    myfile << bd[i]->direcao << " ";
    myfile << bd[i]->cor << " ";
    myfile << bd[i]->portas << " ";
    myfile << bd[i]->placa << " ";
    myfile << bd[i]->valor << " " << endl;
  }
  myfile.close();
}

int main(int argc, char **argv) {
  Tveiculo *bd[50];
  int tam = 0;
  char opc[2];
  string placa;
  int flag = 1;
  Tveiculo *p;
  string escolha;
  ifstream myfile("BD_veiculos.txt");
  if (myfile.is_open()) {
    while (!myfile.eof()) {
      bd[tam] = new Tveiculo;
      myfile >> bd[tam]->modelo;
      myfile >> bd[tam]->marca;
      myfile >> bd[tam]->tipo;
      myfile >> bd[tam]->ano;
      myfile >> bd[tam]->km;
      myfile >> bd[tam]->potencia_do_motor;
      myfile >> bd[tam]->combustivel;
      myfile >> bd[tam]->cambio;
      myfile >> bd[tam]->direcao;
      myfile >> bd[tam]->cor;
      myfile >> bd[tam]->portas;
      myfile >> bd[tam]->placa;
      myfile >> bd[tam]->valor;
      tam++;
    }
    myfile.close();
  } else{
    cout << "Unable to open file" << endl;
    flag = 0;
  }
  for (int i = tam; i < 50; i++) { // aponta para null nas posicoes que sobraram
    bd[i] = NULL;
  }
  tam--;
  
  while (flag) {
    cout << "_____________________________________________________" << endl;
    cout << "|  "
         << "(1) Inserir"
         << "                                      |" << endl;
    cout << "|  "
         << "(2) Buscar veículo por placa"
         << "                     |" << endl;
    cout << "|  "
         << "(3) Busca veículos por valor"
         << "                     |" << endl;
    cout << "|  "
         << "(4) Ordernar por placa"
         << "                           |" << endl;
    cout << "|  "
         << "(5) Listar"
         << "                                       |" << endl;
    cout << "|  "
         << "(6) Sair"
         << "                                         |" << endl;
    cout << "_____________________________________________________" << endl;
    cout << "Digite a opcao desejada:" << endl;
    cin >> opc;
    int opcn = atoi(opc);
    switch (opcn) {
    case 1:
      inserir(bd, &tam);
      break;


      
    case 2:
      cout << "Digite a placa do veiculo: ";
      cin >> placa;
      p = busca(bd, tam, placa);
      if (p != NULL) {
        cout << p->modelo << " ";
        cout << p->marca << " ";
        cout << p->tipo << " ";
        cout << p->ano << " ";
        cout << p->km << " ";
        cout << p->potencia_do_motor << " ";
        cout << p->combustivel << " ";
        cout << p->cambio << " ";
        cout << p->direcao << " ";
        cout << p->cor << " ";
        cout << p->portas << " ";
        cout << p->placa << " ";
        cout << p->valor << endl;

        do {
          cout << "Deseja remover o veiculo? \nDigite \"sim\" ou \"nao\": ";
          cin >> escolha;
        } while(escolha != "sim" && escolha != "nao");
        if(escolha == "sim") {
          remover(bd, &tam, p->placa);
        }
      } else {
        cout << "Veículo procurado não existe no banco de dados." << endl;
      }
      break;



      
    case 3:
      char valor[1];
      int valorN;

      cout << "Digite o valor que deseja procurar: ";
      cin >> valor;
      valorN = atoi(valor);

      while (valorN == 0) {
        cout << "Tente novamente! Digite o valor que deseja procurar: ";
        cin >> valor;
        valorN = atoi(valor);
      }
      valoresProx(bd, tam, valorN);
      break;


      
    case 4:
      ordena(bd, tam);
      break;



      
    case 5:
      imprime(bd, tam, 0);
      break;


      
    case 6:
      transfere(bd, tam);
      for (int i = 0; i < tam; i++)
        delete (bd[i]);
      flag = 0;
      break;
    default:
      cout << "Opcao invalida, digite uma entre as demais" << endl;
      break;
    }
  }
  return 0;
}