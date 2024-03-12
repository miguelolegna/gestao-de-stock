#include <iostream>
#include <string>
#include <iomanip> // Para formatação de saída

using namespace std;

// Classe para representar um produto
class Product {
public:
    string name;
    double purchasePrice;
    double sellingPrice;

    // Calcula o lucro com base nos preços de compra e venda
    double calculateProfit() {
        return sellingPrice - purchasePrice;
    }
};

int main() {
    const int numProducts = 5; // Número de produtos na tabela
    Product products[numProducts];

    // Preencha os detalhes dos produtos
    products[0] = {"Caderno", 5.0, 7.0};
    products[1] = {"Lápis", 1.0, 2.0};
    products[2] = {"Borracha", 0.5, 1.0};
    products[3] = {"Corretor", 1.0, 3.0};
    products[4] = {"Caneta", 0.7, 1.5}; // Adicionei a Caneta

    // Imprima a tabela
    cout << setw(20) << left << "Nome do Produto"
         << setw(15) << right << "Preço de Compra (€)"
         << setw(15) << right << "Preço de Venda (€)"
         << setw(15) << right << "Lucro (€)" << endl;

    double totalProfit = 0.0;
    for (int i = 0; i < numProducts; ++i) {
        double profit = products[i].calculateProfit();
        totalProfit += profit;

        cout << setw(20) << left << products[i].name
             << setw(15) << right << fixed << setprecision(2) << products[i].purchasePrice
             << setw(15) << right << fixed << setprecision(2) << products[i].sellingPrice
             << setw(15) << right << fixed << setprecision(2) << profit << endl;
    }

using namespace std;

// Classe para representar um cliente
class Customer {
public:
    string name;
    double totalPurchase;
    double amountPaid;

    // Calcula o troco com base no valor pago e total da compra
    double calculateChange() {
        return amountPaid - totalPurchase;
    }
};


    const int numCustomers = 5; // Número de clientes
    Customer customers[numCustomers];

    // Preencha os detalhes dos clientes e suas compras
    customers[0] = {"Maria", 7.0, 10.0};
    customers[1] = {"João", 8.0, 20.0};
    customers[2] = {"Manuel", 11.5, 15.0};
    customers[3] = {"Jacline", 3.5, 5.0};
    customers[4] = {"Zé da Pipa", 22.0, 30.0};

    // Imprima a tabela
    cout << setw(20) << left << "Nome do Cliente"
         << setw(15) << right << "Total da Compra (€)"
         << setw(15) << right << "Valor Pago (€)"
         << setw(15) << right << "Troco (€)" << endl;

    for (int i = 0; i < numCustomers; ++i) {
        double change = customers[i].calculateChange();

        cout << setw(20) << left << customers[i].name
             << setw(15) << right << fixed << setprecision(2) << customers[i].totalPurchase
             << setw(15) << right << fixed << setprecision(2) << customers[i].amountPaid
             << setw(15) << right << fixed << setprecision(2) << change << endl;
    }

    return 0;


}