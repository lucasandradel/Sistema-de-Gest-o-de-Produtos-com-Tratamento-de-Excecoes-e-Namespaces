#include "produto.h"


// Construtor padrão
Cadastro::Produto::Produto() : codigo(""), nome(""),preco(0.0),  quantidade(0)  {}
// Construtor com parâmetros
Cadastro::Produto::Produto(const string& cod, double pr, const string& nm, int qtd) : codigo(cod), nome(nm),preco(pr),  quantidade(qtd) {}

void Cadastro::Produto:: setCodigo(const string& cod) {
    if(cod.empty ()){

        //Bloco que compreende a parte que detecta o erro, lançando-o
        throw invalid_argument("\n\tCódigo Inválido, o código deve conter caracters! \n");
    }
    codigo = cod;
    
}
void Cadastro::Produto:: setNome(const string &nm) {
    if(nm.empty ()){

        //Bloco que compreende a parte que detecta o erro, lançando-o
        throw invalid_argument("\n\tCódigo Inválido, o código deve conter caracters! \n");
    }
    nome = nm;
}

void Cadastro:: Produto:: setPreco(double pr ){
    preco = pr;
}

void Cadastro:: Produto:: setQuantidade(int qtd){
    quantidade = qtd;
}

string Cadastro:: Produto:: getCodigo() const{
    return codigo;
}
string Cadastro:: Produto::getNome()const{
    return nome;
}
double Cadastro:: Produto::getPreco()const{
    return preco;
}
int Cadastro:: Produto::getQuantidade()const{
    return quantidade;
}


//método para cadastrar um produto
void Cadastro::Produto::CadastrarProduto(const string &codigo, const string&nome, double preco, int quantidade){
    setCodigo(codigo);
    setNome(nome);    
    setPreco(preco);
    setQuantidade(quantidade);
    
}


Cadastro::Produto Consulta::buscarProduto(const vector<Cadastro::Produto>& produtos, const string& codigo) {
    for (const auto& produto : produtos) { // Percorre todos os produtos no vetor 'produtos'
        if (produto.getCodigo() == codigo) { // Verifica se o código do produto é o procurado
            return produto; // Retorna o produto encontrado
        }
    }
    throw std::out_of_range("Produto com o codigo especificado nao encontrado.");
}
