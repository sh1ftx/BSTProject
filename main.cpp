#include "include/BST.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Função pra inserir múltiplos valores separados por espaço
Node *insertMultiple(Node *root) {
  cout << "Digite os valores para inserir, separados por espaço: ";
  cin.ignore(); // Limpa o buffer do teclado
  string line;
  getline(cin, line);
  istringstream iss(line);
  int val;
  while (iss >> val) {
    root = insert(root, val);
    cout << "Inserido: " << val << endl;
  }
  return root;
}

int main() {
  Node *root = nullptr;
  int choice;

  do {
    cout << "\n===== MENU Árvore Binária de Busca (BST) =====\n";
    cout << "1. Inserir elemento único\n";
    cout << "2. Inserir múltiplos elementos\n";
    cout << "3. Imprimir árvore (in-order)\n";
    cout << "4. Buscar elemento\n";
    cout << "5. Remover elemento\n";
    cout << "6. Contar nós folha\n";
    cout << "7. Calcular soma de todos os nós\n";
    cout << "8. Mostrar altura da árvore\n";
    cout << "9. Verificar balanceamento\n";
    cout << "10. Mostrar caminho entre dois nós\n";
    cout << "11. Mostrar lista ordenada\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int val;
      cout << "Digite o valor para inserir: ";
      cin >> val;
      root = insert(root, val);
      cout << "Valor " << val << " inserido com sucesso!\n";
      break;
    }
    case 2:
      root = insertMultiple(root);
      break;

    case 3:
      cout << "Árvore em ordem (in-order): ";
      inorder(root);
      cout << "\n";
      break;

    case 4: {
      int val;
      cout << "Digite o valor para buscar: ";
      cin >> val;
      if (search(root, val))
        cout << "Valor " << val << " encontrado na árvore!\n";
      else
        cout << "Valor " << val << " não encontrado.\n";
      break;
    }
    case 5: {
      int val;
      cout << "Digite o valor para remover: ";
      cin >> val;
      root = removeNode(root, val);
      cout << "Valor " << val << " removido (se estava presente).\n";
      break;
    }
    case 6:
      cout << "Número de nós folha: " << countLeaves(root) << "\n";
      break;

    case 7:
      cout << "Soma total dos valores dos nós: " << sumNodes(root) << "\n";
      break;

    case 8:
      cout << "Altura da árvore: " << height(root) << "\n";
      break;

    case 9:
      if (isBalanced(root))
        cout << "A árvore está balanceada.\n";
      else
        cout << "A árvore NÃO está balanceada.\n";
      break;

    case 10: {
      int start, end;
      cout << "Digite o nó inicial: ";
      cin >> start;
      cout << "Digite o nó final: ";
      cin >> end;
      if (!printPath(root, start, end))
        cout << "Caminho entre " << start << " e " << end
             << " não encontrado.\n";
      break;
    }

    case 11: {
      vector<int> sortedList;
      toSortedList(root, sortedList);
      cout << "Lista ordenada da árvore: ";
      for (int v : sortedList)
        cout << v << " ";
      cout << "\n";
      break;
    }

    case 0:
      cout << "Encerrando o programa. Valeu!\n";
      break;

    default:
      cout << "Opção inválida! Tente novamente.\n";
    }

  } while (choice != 0);

  return 0;
}
