// $ Ponto de entrada do programa para a Árvore Binária de Busca (BST)
// $ Utiliza as funções definidas em BST.h e implementadas em BST.cpp
// $ Responsável por criar a árvore, inserir dados, buscar, imprimir e demonstrar funcionalidades
// $ Apresenta resultados de forma clara e organizada para o usuário
// $ Facilita testes e demonstrações das operações da BST
// $ Parte do projeto de Estrutura de Dados II
// $ Desenvolvido por Kayki Ivan

#include "include/BST.h"
#include <iostream>

int main() {
  Node *root = nullptr;

  // Inserção
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 3);
  root = insert(root, 7);
  using namespace std;

  // Impressão in-order
  cout << "Inorder: ";
  inorder(root);
  cout << "\n";

  // Buscar
  Node *found = search(root, 7);
  cout << "Busca por 7: " << (found ? "Encontrado" : "Não encontrado") << "\n";

  // Altura
  cout << "Altura: " << height(root) << "\n";

  // Soma
  cout << "Soma dos nós: " << sumNodes(root) << "\n";

  // Contagem de folhas
  cout << "Nós folha: " << countLeaves(root) << "\n";

  // Caminho entre dois nós
  cout << "Caminho entre 3 e 15: ";
  printPath(root, 3, 15);

  // Lista ordenada
  vector<int> lista;
  toSortedList(root, lista);
  cout << "Lista ordenada: ";
  for (int val : lista)
    cout << val << " ";
  cout << "\n";

  return 0;
}
