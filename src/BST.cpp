// $ Implementação da estrutura de dados Árvore Binária de Busca (BST)
// $ Contém a implementação das funções declaradas em BST.h
// $ Aqui definimos o "como faz", separando da interface (o "o que faz")
// $ Facilita a manutenção, leitura e modularização do projeto
// $ Parte do projeto de Estrutura de Dados II
// $ Desenvolvido por Kayki Ivan

// ------------------ INCLUDEs -----------------

#include "../include/BST.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// ------------------ SCRIPT PRINCIPAL -----------------

// ! Função para criar um novo nó com o valor fornecido
Node *createNode(int data) {
  Node *newNode = new Node; // *** Aloca memória para um novo nó
  newNode->data = data;     // *** Atribui o valor ao nó
  newNode->left = nullptr;  // *** Inicializa o ponteiro esquerdo como nulo
  newNode->right = nullptr; // *** Inicializa o ponteiro direito como nulo
  return newNode;           // *** Retorna o novo nó criado
}

// ! Insere um valor na BST
Node *insert(Node *root, int data) {
  if (root == nullptr)
    return createNode(data); // *** Se a árvore estiver vazia, cria o nó raiz
  if (data < root->data)     // *** Se o valor for menor que o nó atual
    root->left = insert(root->left, data);   // *** Insere no lado esquerdo
  else if (data > root->data)                // *** Se o valor for maior
    root->right = insert(root->right, data); // *** Insere no lado direito
  return root; //*** Retorna o ponteiro para manter a árvore conectada
}

// ! Impressão em ordem (esquerda -> raiz -> direita)
void inorder(Node *root) {
  if (root != nullptr) {
    inorder(root->left);       // *** Percorre a subárvore esquerda
    cout << root->data << " "; // *** Imprime o valor do nó
    inorder(root->right);      // *** Percorre a subárvore direita
  }
}

// ! Impressão pré-ordem (raiz -> esquerda -> direita)
void preorder(Node *root) {
  if (root != nullptr) {
    cout << root->data << " "; // *** Imprime o valor do nó
    preorder(root->left);      // *** Percorre a subárvore esquerda
    preorder(root->right);     // *** Percorre a subárvore direita
  }
}

// ! Impressão pós-ordem (esquerda -> direita -> raiz)
void postorder(Node *root) {
  if (root != nullptr) {
    postorder(root->left);     // *** Percorre a subárvore esquerda
    postorder(root->right);    // *** Percorre a subárvore direita
    cout << root->data << " "; // *** Imprime o valor do nó
  }
}

// ! Busca por um valor específico na árvore
Node *search(Node *root, int data) {
  if (root == nullptr || root->data == data)
    return root; // *** Se encontrou ou chegou ao fim
  if (data < root->data)
    return search(root->left, data); // *** Busca na esquerda
  else
    return search(root->right, data); // *** Busca na direita
}

// ! Encontra o menor valor em uma subárvore (usado na remoção)
Node *findMin(Node *root) {
  while (root->left != nullptr)
    root = root->left; // *** Vai até o nó mais à esquerda
  return root;
}

// ! Remove um valor da árvore
Node *removeNode(Node *root, int data) {
  if (root == nullptr)
    return nullptr; // *** Valor não encontrado

  if (data < root->data) // *** Valor está à esquerda
    root->left = removeNode(root->left, data);
  else if (data > root->data) // *** Valor está à direita
    root->right = removeNode(root->right, data);
  else {
    // ?? Nó com apenas um filho ou nenhum
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // ! Nó com dois filhos: substitui pelo menor valor da subárvore direita
    Node *temp = findMin(root->right);
    root->data = temp->data;                           // *** Copia o valor
    root->right = removeNode(root->right, temp->data); // *** Remove o duplicado
  }
  return root;
}

// ! Conta quantos nós folha existem (nós sem filhos)
int countLeaves(Node *root) {
  if (root == nullptr)
    return 0;
  if (root->left == nullptr && root->right == nullptr)
    return 1;
  return countLeaves(root->left) + countLeaves(root->right);
}

// ! Soma de todos os valores da árvore
int sumNodes(Node *root) {
  if (root == nullptr)
    return 0;
  return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// ! Calcula a altura da árvore
int height(Node *root) {
  if (root == nullptr)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

// ! Verifica se a árvore está balanceada
bool isBalanced(Node *root) {
  if (root == nullptr)
    return true;
  int lh = height(root->left);  // *** Altura da subárvore esquerda
  int rh = height(root->right); // *** Altura da subárvore direita
  return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

// ! Função auxiliar: encontra o caminho do root até um nó e armazena no vetor
// path
bool findPath(Node *root, int target, vector<int> &path) {
  if (root == nullptr)
    return false;
  path.push_back(root->data); // *** Adiciona o nó atual ao caminho

  if (root->data == target)
    return true; // *** Se encontrou o alvo
  if ((root->left && findPath(root->left, target, path)) ||
      (root->right && findPath(root->right, target, path)))
    return true;

  path.pop_back(); // *** Remove se o caminho não levar ao alvo
  return false;
}

// ! Imprime o caminho entre dois nós
bool printPath(Node *root, int start, int end) {
  vector<int> path1, path2;
  if (!findPath(root, start, path1) || !findPath(root, end, path2))
    return false;

  // ! Encontra o ponto de separação (menor ancestral comum)
  int i = 0;
  while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
    i++;

  // ! Imprime o caminho completo
  cout << "Caminho entre " << start << " e " << end << ": ";
  for (int j = path1.size() - 1; j >= i; --j)
    cout << path1[j] << " -> ";
  for (int j = i; j < path2.size(); ++j)
    cout << path2[j] << (j == path2.size() - 1 ? "" : " -> ");
  cout << endl;
  return true;
}

// ! Converte a árvore em uma lista ordenada (in-order)
void toSortedList(Node *root, vector<int> &list) {
  if (root == nullptr)
    return;
  toSortedList(root->left, list);
  list.push_back(root->data);
  toSortedList(root->right, list);
}
