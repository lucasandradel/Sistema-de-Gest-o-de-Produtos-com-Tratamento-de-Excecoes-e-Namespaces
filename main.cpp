#include <iostream>
#include <vector>
#include "produto.h"

using namespace std;
using namespace Cadastro;
using namespace Consulta;

int main() {
    vector<Produto> produtos; // Lista para armazenar os produtos cadastrados
    int opcao; // Variável para armazenar a opção do usuário

    do {
        cout << "================= Sistema de Gestao de Produtos =================" << endl;
        cout << "1. Cadastrar Produto" << endl;
        cout << "2. Buscar Produto" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: { // Cadastrar Produto
                string codigo, nome;
                double preco;
                int quantidade;
                
                cout << "Digite o codigo do produto: ";
                cin >> codigo;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                cout << "Digite o preco do produto: ";
                cin >> preco;
                cout << "Digite a quantidade do produto: ";
                cin >> quantidade;
                
                try {
                    Produto novoProduto; // Cria um objeto Produto
                    novoProduto.CadastrarProduto(codigo, nome, preco, quantidade); // Cadastra o produto
                    produtos.push_back(novoProduto); // Adiciona o produto à lista
                    cout << "Produto cadastrado com sucesso!" << endl;
                } catch (const invalid_argument& e) {
                    cout << "Erro: " << e.what() << endl;
                }

                break;
            }
            case 2: { // Buscar Produto
                string codigo;
                cout << "Digite o codigo do produto que deseja buscar: ";
                cin >> codigo;

                try {
                    Produto encontrado = buscarProduto(produtos, codigo); // Busca o produto
                    cout << "Produto encontrado!" << endl;
                    cout << "Codigo: " << encontrado.getCodigo() << endl;
                    cout << "Nome: " << encontrado.getNome() << endl;
                    cout << "Preco: " << encontrado.getPreco() << endl;
                    cout << "Quantidade: " << encontrado.getQuantidade() << endl;
                } catch (const out_of_range& e) {
                    cout << "Erro: " << e.what() << endl;
                }

                break;
            }
            case 3: // Sair
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
        
        cout << endl;
    } while (opcao != 3); // Loop até o usuário escolher sair

    return 0;
}
