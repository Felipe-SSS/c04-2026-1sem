// Antônio Vinícius Costa Alves Ferreira - 2282
// Felipe Soares dos Santos Silveira - 843
// Kauã de Oliveira Ribeiro - 777
// Lívia Vilela Ribeiro Guimarães - 797
// Luiz Henrique Azevedo de Carvalho - 813
// Vitor Nolasco Ynoguti - 818

#include<iostream>
#include <iomanip>
#include<string>

using namespace std;

struct palavra{
    string ficticio;
    string real;
};

void cadastrar()
{
    cout << "\nFuncionalidade em construcao" << endl;
}

void excluir()
{
    cout << "\nFuncionalidade em construcao" << endl;
}

void significado()
{
    cout << "\nFuncionalidade em construcao" << endl;
}

void sinonimos()
{
    cout << "\nFuncionalidade em construcao" << endl;
}

void similaridade()
{
    cout << "\nFuncionalidade em construcao" << endl;
}

void listarPorAlfabeto(){
    cout << "\nFuncionalidade em construcao" << endl;
}

void listarPorTamanho(){
    cout << "\nFuncionalidade em construcao" << endl;
}

// Funcao responsavel por exibir o menu principal
int menu() {
    int opcao;

    while (true) {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Cadastrar Palavra\n";
        cout << "2. Excluir Palavra\n";
        cout << "3. Significado\n";
        cout << "4. Sinonimos\n";
        cout << "5. Calcular Similaridade\n";
        cout << "6. Listar Palavras em Ordem Alfabetica\n";
        cout << "7. Listar Palavras por Tamanho\n";
        cout << "8. Sair\n";
        cout << "Escolha uma opcao: ";
        
        cin >> opcao;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }

        switch (opcao) {
            case 1:
                return 1;

            case 2:
                return 2;

            case 3:
                return 3;

            case 4:
                return 4;

            case 5:
                return 5;

            case 6:
                return 6;

            case 7:
                return 7;

            case 8:
                return 0;

            default:
                cout << "Opcao invalida.\n";
        }
    }
}

// Funcao para exibir o menu novamente ou encerrar o programa
bool exibirMenuNovamente() {
    int opcao;
    
    while (true) {
        cout << "\nDeseja realizar uma nova operacao?\n";
        cout << "1. Sim\n";
        cout << "0. Nao\n\n";

        cin >> opcao;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            continue;
        }
        
        switch (opcao) {
            case 0:
                cout << "\nEncerrando o programa...\n";
                return false;
            case 1:
                cout << "\nVoltando ao menu...\n";
                return true;
            default:
                cout << "Opcao invalida.\n";
        }
    }           
}

int main()
{
    // Variavel da escolha feita pelo usuario no menu
    int opcao;
    // Variavel que determina se o menu deve ser exibido ou nao
    bool exibirMenu = true;
    
    //Loop principal do codigo
    while (true) {
        if (exibirMenu) {
            opcao = menu();
        }
        else {
            break;
        }
        
        // Logica responsavel por chamar as diferentes funcoes do programa baseado nas opcoes escolhidas pelo usuario
        switch(opcao) {
            case 0:
                cout << "\nSaindo do programa...\n";
                return 0;

            case 1:
                cadastrar();
                break;
            case 2:
                excluir();
                break;
            case 3:
                significado();
                break;
            case 4:
                sinonimos();
                break;
            case 5:
                similaridade();
                break;
            case 6:
                listarPorAlfabeto();
                break;
            case 7:
                listarPorTamanho();
                break;
        }
        
        // Apos a execucao de uma opcao valida, o programa descobre se o usuario deseja realizar uma nova operacao ou se deseja sair, finalizando o programa
        exibirMenu = exibirMenuNovamente();
    }

    return 0;
}