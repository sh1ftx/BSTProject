// $ Cabeçalho geral do projeto, onde declararemos funções, structs, classes e
// constantes. $ Ele serve para separar interface (o "o que faz") da
// implementação (o "como faz") $ Ajuda a evitar repetições e facilitar a
// reutilização de código $ Ajudar na compilação modular (compilar por partes,
// não tudo junto) $ Desenvolvido por Kayki Ivan

// ------------------ Includes -----------------

#ifndef BST_H
#define BST_H
#include <vector>

// ------------------ Struct Node -----------------
// ! Criando o struct Node que representa a unidade basica
// da estrutura da arvore
struct Node {
  int data;    // *** Dadoo que o Node armazena
  Node *left;  // *** Ponteiro que aponta pro filho esquerdo ( subavaro menor )
  Node *right; // *** Ponteiro que aponta pro filho direito ( subavaro maior )
};

// ------------------ Funcoes da Arvore -----------------
Node *insert(Node *root, int data);     // *** Insere um novo valor na arvore
Node *search(Node *root, int data);     // *** Busca por um valor na arvore
Node *removeNode(Node *root, int data); // *** Remove um nó específico da árvore
void inorder(Node *root);   // *** Imprime os elementos em ordem crescente
void preorder(Node *root);  // *** Visita a raiz antes dos filhos.
void postorder(Node *root); // *** Visita a raiz por último
int countLeaves(
    Node *root); // *** Conta quantos nós folha existem (nós que não têm filhos)
int sumNodes(
    Node *root); // *** Retorna a soma de todos os valores dos nós da árvore
int height(Node *root); // *** Retorna a altura da árvore (maior distância da
                        // raiz até uma folha).
bool isBalanced(Node *root); // *** Verifica se a árvore está balanceada:
bool printPath(Node *root, int start,
               int end); // *** Mostra o caminho entre dois nós start e end. Ex:
                         // Caminho entre 3 e 15: 3 -> 5 -> 10 -> 15
void toSortedList(
    Node *root,
    std::vector<int> &list); // *** Preenche o vector com os elementos ordenados
                             // (via in-order traversal)

#endif // BST_H
