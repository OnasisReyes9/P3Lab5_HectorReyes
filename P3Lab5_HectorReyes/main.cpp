/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 13 de noviembre de 2020, 01:18 PM
 */

#include <cstdlib>

#include <ctime>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using std::endl;
using std::cin;
using std::cout;

using namespace std;

//void suma_Matrices(int**&, int**&, int, int, int, int);
void inicializarMatriz(int, int, int**&);
void ingresar_Matriz(int, int, int**&);
void generarMatrizRandom(int**&, int, int);
void imprimirMatriz(int**&, int, int);
int** sumaMatriz(int**&, int**&, int);
int** restaMatriz(int**&, int**&, int);
int** multiplicacionMatriz(int**&, int**&, int, int, int, int);
void imprimirMatriz(int**&, int, int);

    /*
     * 
     */

    vector <int**> listaVectores;
    vector <int> listaFilas;
    vector <int> listaColumnas; //*/

    int main(int argc, char** argv) {
        bool continuar = true;
        int opcion = 0;
        while (continuar) {
            cout << "Menú\n"
                    "0. Salir\n"
                    "1. Ingresar matriz\n"
                    "2. Generar matriz\n"
                    "3. Realizar operación entre matrices\n"
                    "-> Escoja su opción: ";
            cin >> opcion;
            cout << "\n";
            switch (opcion) {
                case 1:
                {
                    int filas = 0, columnas = 0;
                    while (filas < 1) {
                        cout << "Ingrese cantidad de filas mayor que 0: ";
                        cin >> filas;
                    }
                    listaFilas.push_back(filas);
                    while (columnas < 1) {
                        cout << "Ingrese cantidad de columnas mayor que 0: ";
                        cin >> columnas;
                    }
                    listaColumnas.push_back(columnas);
                    cout << endl;
                    int** matrizNueva = new int*[filas];
                    inicializarMatriz(filas, columnas, matrizNueva);
                    ingresar_Matriz(filas, columnas, matrizNueva);
                    listaVectores.push_back(matrizNueva);
                    cout << "Matriz Generada";
                    imprimirMatriz(listaVectores[listaVectores.size()], filas, columnas);
                    break;
                }
                case 2:
                {
                    int filas = 0, columnas = 0;
                    while (filas < 1) {
                        cout << "Ingrese cantidad de filas mayor que 0: ";
                        cin >> filas;
                    }
                    listaFilas.push_back(filas);
                    while (columnas < 1) {
                        cout << "Ingrese cantidad de columnas mayor que 0: ";
                        cin >> columnas;
                    }
                    listaColumnas.push_back(columnas);
                    cout << endl;
                    int** matrizNueva = new int*[filas];
                    inicializarMatriz(filas, columnas, matrizNueva);
                    listaVectores.push_back(matrizNueva);
                    cout << "Matriz Generada";
                    imprimirMatriz(listaVectores[listaVectores.size()], filas, columnas);
                    break;
                }
                case 3:
                {
                    if (listaVectores.size() < 0) {
                        string operacion = "";
                        cout << "Ingrese la operación a realizar: ";
                        cin >> operacion;
                    }
                    break;
                }
                case 0:
                {
                    cout << "Fin de la ejecucion.\n";
                    continuar = false;
                    break;
                }
                default:
                {
                    cout << "Opción inexistente.\n";
                }
            }
            cout << "\n";
        }//fin while
        return 0;
    }//fin main

    void ingresar_Matriz(int filas, int columnas, int**& matrizNueva) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Ingrese número para la posición de la matriz[" << i << "][" << j << "]: ";
                cin >> matrizNueva[i][j];
            }
        }
    }

    void inicializarMatriz(int filas, int columnas, int**& matrizNueva) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matrizNueva[i] = new int[columnas];
            }//fin for
        }//fin for
    }//fin método

    void inicializarMatriz(int size, int**& matrizNueva) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrizNueva[i] = new int[size];
            }//fin for
        }//fin for
    }//fin método

    void generarMatrizRandom(int**& matriz_A, int filas, int columnas) {
        srand(time(0));
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz_A[i][j] = 1 + (rand() % 101 - 49);
            }//fin for
        }//fin for
    }//fin método

    void imprimirMatriz(int**& matriz, int filas, int columnas) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "[" << matriz[i][j] << "] ";
            }//fin for
            cout << endl;
        }//fin for
        cout << endl;
    }//fin método

    int** sumaMatriz(int**& matrizA, int**& matrizB, int size) {
        int** matrizResultante = new int*[size];
        inicializarMatriz(size, matrizResultante);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrizResultante[i][j] = matrizA[i][j] + matrizB[i][j];
            }//fin for
        }//fin for
        return matrizResultante;
    }//fin método

    int** restaMatriz(int**& matrizA, int**& matrizB, int size) {
        int** matrizResultante = new int*[size];
        inicializarMatriz(size, matrizResultante);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrizResultante[i][j] = matrizA[i][j] - matrizB[i][j];
            }//fin for
        }//fin for
        return matrizResultante;
    }//fin método

    int** multiplicacionMatriz(int**& matrizA, int**& matrizB, int filasA, int columnasA, int columnasB, int filasB) {
        int** matrizResultante = new int*[filasA];
        inicializarMatriz(filasA, columnasB, matrizResultante);
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < columnasA; j++) {
                for (int k = 0; k < columnasB; k++) {
                    for (int f = 0; f < filasB; f++) {
                        matrizResultante[i][k] += (matrizA[i][j] * matrizB[f][k]);
                    }//fin for
                }//fin for
            }//fin for
        }//fin for
        return matrizResultante;
    }//fin método

    void operaciones(string operacion) {
        int** matrizResultante = new int*[listaFilas[0]];
        inicializarMatriz(listaFilas[0], matrizResultante); //
        for (int i = 0; i < listaFilas[0]; i++) {
            for (int j = 0; j < listaColumnas[0]; j++) {
                matrizResultante[i][j] = 0;
            }
        }
        string pos_Matriz1 = "", pos_Matriz2 = "";
        bool operacionValida = true;
        for (int i = 0; i < operacion.length(); i++) {
            //este if agarra los numeros despues de cada signo
            if (operacion[i] >= 48 && operacion[i] <= 57) {
                pos_Matriz1 += operacion[i];
            } else {
                //este if agarra los numeros despues de un asterisco
                if (operacion[i] == 42) {
                    for (int j = i + 1; j < operacion.length(); j++) {
                        if (operacion[j] >= 48 && operacion[j] <= 57) {
                            pos_Matriz2 += operacion[j];
                        } else {
                            //multiplica
                        }
                    }//fin for
                } else if (operacion[i] == 43) {
                    for (int j = i + 1; j < operacion.length(); j++) {
                        if (operacion[j] >= 48 && operacion[j] <= 57) {
                            pos_Matriz2 += operacion[j];
                        } else {
                            if (listaFilas[stoi(pos_Matriz1)] == listaFilas[stoi(pos_Matriz2)] &&
                                    listaColumnas[stoi(pos_Matriz1)] == listaColumnas[stoi(pos_Matriz2)]) {
                                matrizResultante =
                                        sumaMatriz(listaVectores[stoi(pos_Matriz1)],
                                        listaVectores[stoi(pos_Matriz2)], listaFilas[stoi(pos_Matriz1)]);
                            } else {
                                operacionValida = false;
                            }
                        }
                    }//fin for
                } else if (operacion[i] == 45) {
                    for (int j = i + 1; j < operacion.length(); j++) {
                        if (operacion[j] >= 48 && operacion[j] <= 57) {
                            pos_Matriz2 += operacion[j];
                        } else {
                            if (listaFilas[stoi(pos_Matriz1)] == listaFilas[stoi(pos_Matriz2)]
                                    &&
                                    listaColumnas[stoi(pos_Matriz1)] == listaColumnas[stoi(pos_Matriz2)]) {
                                matrizResultante =
                                        restaMatriz(listaVectores[stoi(pos_Matriz1)],
                                        listaVectores[stoi(pos_Matriz2)], listaFilas[stoi(pos_Matriz1)]);
                            } else {
                                operacionValida = false;
                            }//
                        }
                    }//fin for
                }//fin else if
                pos_Matriz1 = "";
                pos_Matriz2 = "";
            }//fin else
        }//fin for
    }//*/