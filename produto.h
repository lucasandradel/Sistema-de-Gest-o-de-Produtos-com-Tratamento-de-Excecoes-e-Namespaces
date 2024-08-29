#ifndef __PRODUTO_H__
#define __PRODUTO_H__


#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Cadastro{

    class Produto {
        
        private:
            string codigo;
            string nome;
            double preco;
            int quantidade;
        public:

            //construtor padrão sem parâmetros
            Produto();

            // Construtor com parâmetros
            Produto(const string& cod,double pr,const string& nm, int qtd);

            //método para cadastrar produto
            void CadastrarProduto(const string & codigo, const string&nome, double preco, int quantidade);      


            //setters
            void setCodigo(const string& );
            void setNome(const string& );
            void setPreco(double);
            void setQuantidade(int );

            //getters
            string getCodigo()const ;
            string getNome() const;
            double getPreco()const ;
            int getQuantidade()const ;


    };

}

namespace Consulta {
    Cadastro::Produto buscarProduto(const vector<Cadastro::Produto>& produtos, const std::string& codigo);
}


#endif

