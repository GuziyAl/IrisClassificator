#include <iostream>
#include <string>
#include "networking.h"
#include "matrix_operations.h"

using namespace std;

int main()
{
    cout << ">>> Iris classifacator started <<<" << endl;

    double hidden_out [4];
    double **hidden = crtLayer(4,4);

    hidden [0][0] = 4.56824;
    hidden [0][1] = 11.4497;
    hidden [0][2] = -18.0741;
    hidden [0][3] = -8.75654;

    hidden [1][0] = 3.3438;
    hidden [1][1] = -54.1316;
    hidden [1][2] = 25.0505;
    hidden [1][3] = 15.1561;

    hidden [2][0] = 51.4807;
    hidden [2][1] = -17.0333;
    hidden [2][2] = -48.7079;
    hidden [2][3] = -27.1736;

    hidden [3][0] = -3.84527;
    hidden [3][1] = -3.65406;
    hidden [3][2] = 8.0503;
    hidden [3][3] = 9.4609;

    double outer_out [3];
    double **outer = crtLayer(3,4);

    outer [0][0] = 9.0802;
    outer [0][1] = -7.82366;
    outer [0][2] = -0.287019;
    outer [0][3] = -8.88968;

    outer [1][0] = -34.2197;
    outer [1][1] = -24.0593;
    outer [1][2] = 27.4651;
    outer [1][3] = 11.9295;

    outer [2][0] = -5.97814;
    outer [2][1] = 25.8681;
    outer [2][2] = -30.1964;
    outer [2][3] = -12.2914;

    string command_char;
    while (true) {
        cout << "Enter comand: ";
        cin >> command_char;
        if (command_char == "exit") {
            break;
        }
        else if (command_char == "menu") {
            cout << endl;
            cout << "* Enter exit to quit programm" << endl;
            cout << "* Enter new to classificate new iris by its parametrs" << endl;
            cout << "* Enter menu to quit see this message" << endl;
            cout << endl;
        }
        else if (command_char == "new"){
            // initialization and normalization of input signals vector
            cout << endl;
            cout << ">>> Enter iris parameters <<<" << endl;
            double input_signals [4];
            for (int i = 0; i < 4; ++i) {
                cout << "Signal #" << i + 1 << ": ";
                cin >> input_signals[i];
            }
            normalization(input_signals);

            double *hidden_net = matrixAndVectorMultiplication(hidden, 4, 4, input_signals);
            for (int i = 0; i < 4; ++i) {
                hidden_out[i] = activationFunction(hidden_net[i]);
            }
            delete [] hidden_net;

            double *outer_net = matrixAndVectorMultiplication(outer, 3, 4, hidden_out);
            for (int i = 0; i < 3; ++i) {
                outer_out[i] = activationFunction(outer_net[i]);
            }
            delete [] outer_net;

            if (outer_out[0] > outer_out[1] &&
                outer_out[0] > outer_out[2]) {
                cout << endl;
                cout << "Iris Setosa" << endl;
                cout << endl;
            }
            else if (outer_out[1] > outer_out[0] &&
                     outer_out[1] > outer_out[2]) {
                     cout << endl;
                     cout << "Iris Versicolor" << endl;
                     cout << endl;
            }
            else if (outer_out[2] > outer_out[1] &&
                     outer_out[2] > outer_out[0]) {
                     cout << endl;
                     cout << "Iris Viriginica" << endl;
                     cout << endl;
            }
        }
    }

    return 0;
}
