#include <iostream>
#include <string>
#include <iomanip> // Para formatação de saída
#include <vector> // Para usar vector

using namespace std;

// Classe para representar um produto
class Product {
public:
    string name;
    double purchasePrice;
    double sellingPrice;
    int maxStock; // Estoque máximo
    int currentStock; // Estoque atual

    // Construtor para inicializar os atributos do produto
    Product(string name, double purchasePrice, double sellingPrice, int maxStock, int currentStock) 
        : name(name), purchasePrice(purchasePrice), sellingPrice(sellingPrice), maxStock(maxStock), currentStock(currentStock) {}

    // Calcula o lucro com base nos preços de compra e venda
    double calculateProfit() {
        return sellingPrice - purchasePrice;
    }
};

// Classe para representar um cliente
class Customer {
public:
    string name;
    double totalPurchase;
    double amountPaid;
    vector<pair<Product, int>> productsBought; // Vector de produtos comprados e suas quantidades

    // Construtor para inicializar o nome do cliente, total da compra e valor pago
    Customer(string name, double totalPurchase, double amountPaid, vector<pair<Product, int>> productsBought) 
        : name(name), totalPurchase(totalPurchase), amountPaid(amountPaid), productsBought(productsBought) {}

    // Calcula o troco com base no valor pago e total da compra
    double calculateChange() {
        return amountPaid - totalPurchase;
    }
};

int main() {
    const int numProducts = 5; // Número de produtos na tabela
    Product products[numProducts] = {
        Product("Caderno", 5.0, 7.0, 28, 25),
        Product("Lápis", 1.0, 2.0, 16, 13),
        Product("Borracha", 0.5, 1.0, 20, 16),
        Product("Corretor", 1.0, 3.0, 16, 14),
        Product("Caneta", 0.7, 1.5, 20, 15)
    };

    // Imprima a tabela de produtos
    cout << "Nome do Produto     Preço de Compra (€)  Preço de Venda (€)  Lucro (€)  Estoque Máximo  Estoque Atual" << endl;
    for (int i = 0; i < numProducts; ++i) {
        double profit = products[i].calculateProfit();
        cout << setw(20) << left << products[i].name
             << setw(20) << right << fixed << setprecision(2) << products[i].purchasePrice
             << setw(20) << right << fixed << setprecision(2) << products[i].sellingPrice
             << setw(10) << right << fixed << setprecision(2) << profit
             << setw(15) << right << products[i].maxStock
             << setw(15) << right << products[i].currentStock << endl;
    }

    // Declaração dos clientes com seus detalhes de compra
    Customer customers[numProducts] = {
        Customer("Maria", 7.0, 10.0, {{products[1], 1}, {products[3], 1}, {products[2], 2}}),
        Customer("João", 8.0, 20.0, {{products[3], 2}, {products[1], 1}}),
        Customer("Manuel", 11.5, 15.0, {{products[4], 3}, {products[0], 1}}),
        Customer("Jacline", 3.5, 5.0, {{products[2], 2}, {products[4], 1}}),
        Customer("Zé da Pipa", 22.0, 30.0, {{products[0], 2}, {products[1], 1}, {products[4], 2}, {products[3], 1}})
    };

    // Imprima a tabela de clientes
    cout << "\nTabela de Clientes:" << endl;
    cout << setw(20) << left << "Nome do Cliente"
         << setw(20) << right << "Total da Compra (€)"
         << setw(20) << right << "Valor Pago (€)"
         << setw(15) << right << "Troco (€)" << endl;

    for (int i = 0; i < numProducts; ++i) {
        double change = customers[i].calculateChange();
        cout << setw(20) << left << customers[i].name
             << setw(20) << right << fixed << setprecision(2) << customers[i].totalPurchase
             << setw(20) << right << fixed << setprecision(2) << customers[i].amountPaid
             << setw(15) << right << fixed << setprecision(2) << change << endl;
    }

    // Imprima a tabela de compras de cada cliente
    cout << "\nTabela de Compras de Clientes:" << endl;
    cout << setw(20) << left << "Nome do Cliente"
         << setw(20) << left << "Item"
         << setw(15) << right << "Quantidade" << endl;

    for (int i = 0; i < numProducts; ++i) {
        cout << "Cliente: " << customers[i].name << endl;
        for (const auto& pair : customers[i].productsBought) {
            cout << setw(20) << left << "" // Espaço para o nome do cliente
                 << setw(20) << left << pair.first.name
                 << setw(15) << right << pair.second << endl;
        }
        cout << endl;
    }

    return 0;
}
