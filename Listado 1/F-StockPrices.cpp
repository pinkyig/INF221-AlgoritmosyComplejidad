#include "iostream"
#include "vector"
#include "string"
#include "sstream"
#include "queue"

using namespace std;



void stocksharesPrices (){
        int ordersNumber;
        cin >> ordersNumber;

		priority_queue<int, vector<int>, less<int> > preciosVenta;
		priority_queue<int, vector<int>, greater<int> > preciosCompra;

		string operation, order;
		int sharesCount, sharesPrice;
		int ultimoPrecioAcordado = 0;

        cin.ignore();
       
		while (ordersNumber--) {
            getline(cin, operation);
            istringstream iss(operation);
            iss >> order >> sharesCount;

            iss.ignore(10); // Ignoramos 10 espacios por  la longitud de "shares at"

            iss >> sharesPrice;


			if (order == "buy") {
				while (sharesCount--) preciosVenta.push(sharesPrice);
			} else {
				while (sharesCount--) preciosCompra.push(sharesPrice);
			}

			while (preciosCompra.size() && preciosVenta.size() && preciosCompra.top() <= preciosVenta.top()) {
				ultimoPrecioAcordado = preciosCompra.top();
				preciosCompra.pop();
				preciosVenta.pop();
			}


            //Impriminedo el precio de la orden de compra y venta

            if (preciosCompra.empty()){
                cout << "- ";
            }else{
                cout << preciosCompra.top() << " ";
            }                

            if (preciosVenta.empty()){
                cout << "- ";
            }else{
                cout << preciosVenta.top() << " ";
            }        


			if (ultimoPrecioAcordado == 0) {
                cout << "-" << endl;
			} else {
				cout << ultimoPrecioAcordado << endl;
			}

		}
	}


int main(){

    int casosPrueba;
    cin >> casosPrueba;

    while (casosPrueba > 0){
        stocksharesPrices();
        casosPrueba--;
    }

    return 0;
}