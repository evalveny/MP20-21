#include <iostream>
using namespace std;

int main()
{
    const char CLIENT_BASIC = 'B', CLIENT_STANDARD = 'S', CLIENT_PREMIUM = 'P';
    const float LLINDAR_1 = 100.0, LLINDAR_2 = 1000.0, LLINDAR_3 = 10000.0;

	float import, importFinal;
    char tipusClient;
    float descompte = 0.0;
    bool error = false;

	cout << "Valor de compra: " << endl;
	cin >> import;
    cout << "Tipus de client: " << endl;
    cin >> tipusClient;

    switch (tipusClient)
    {
        case CLIENT_BASIC:
            break;
        case CLIENT_STANDARD:
            if (import > LLINDAR_3)
                descompte = 0.05;
            break;
        case CLIENT_PREMIUM:
            if (import >= LLINDAR_3)
                descompte = 0.2;
            else
                if (import >= LLINDAR_2)
                    descompte = 0.1;
                else 
                    if (import > LLINDAR_1)
                        descompte = 0.05;
            break;
        default:
            error = true;
    }

	if (!error)
	{
		importFinal = import * (1 - descompte);
		cout << "Import final a pagar: " << importFinal << endl;
	}
	else
		cout << "ERROR" << endl;

	return 0;
}