
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include "SelectionSort.h"
#include "SortedLinkedList.h"
#include "BubbleSort.h"
#include "BST.h"
#include "MergeSort.h"
#include <chrono>
#include <random>
using namespace std;

//para los de ordenamiento
template<typename Func>
double measureEXCTime(Func func, vector<int>& vec) {
    auto start = chrono::high_resolution_clock::now();
    func(vec);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}
//para la linkedlist
template<typename Func>
double measureEXCtime(Func f) {
    auto start = chrono::high_resolution_clock::now();
    f();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

template <typename T>
double measureEXCTimeBST(BST<T>& bst, const vector<T>& data) {
    auto start = chrono::high_resolution_clock::now();
    for (const T& key : data) {
        bst.insert(key);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

void generateWCBubble(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        vec[i] = n - i;
    }
}
void generateBCBubble(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        vec[i] = i + 1;
    }
}
void generateAVBubble(vector<int>& vec) {
    random_device rd;
    mt19937 rng(rd());
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
        vec[i] = i + 1;
    }
    shuffle(vec.begin(), vec.end(), rng);
}

void generateWCLL(SortedLinkedList& list, int N) {
    list.clear();
    for (int i = 0; i < N; ++i) {
        list.insert(i);
    }
}
void generateBCLL(SortedLinkedList& list, int N) {
    list.clear();
    for (int i = 0; i < N; ++i) {
        list.insert(i);
    }
}
void generateAVLL(SortedLinkedList& list, int N) {
    list.clear();
    vector<int> elements(N);
    for (int i = 0; i < N; ++i) {
        elements[i] = i;
    }
    random_shuffle(elements.begin(), elements.end());
    for (int i : elements) {
        list.insert(i);
    }
}
template <typename T>
void generateWCBST(vector<T>& elements) {
    for (T i = 1; i <= elements.size(); ++i) {
        elements[i - 1] = i;
    }
}
template <typename T>
void generateBCBST(vector<T>& elements) {
    random_device rd;
    mt19937 g(rd());
    for (T i = 1; i <= elements.size(); ++i) {
        elements[i - 1] = i;
    }
    shuffle(elements.begin(), elements.end(), g);
}
template <typename T>
void generateAVBST(vector<T>& elements) {
    generateBCBST(elements); // Reutilizamos el generador aleatorio
}



int main() {
    int algorithm;
    int cases;
    const int SIZE = 6;
    int sizes[SIZE];
    int searchNumber;
    SortedLinkedList list;
    BST<int> bst;

    //verifica el input de cual algoritmo es
    while (true) {
        cout << "Elija un algoritmo/operacion:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. All Sorted LinkedList Search" << endl;
        cout << "5. Binary Search Tree Insert" << endl;

        cin >> algorithm;

        if (algorithm < 1 || algorithm > 5) {
            cerr << "Opcion invalida. Elija entre las opciones propuestas." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    //esto tampoco se usa de nada
    // Si el usuario selecciona LinkedList, pregunta el número a buscar
    if (algorithm == 4) {
        cout << "Ingrese el numero que desea buscar en la lista enlazada: ";
        cin >> searchNumber;

        if (cin.fail()) {
            cerr << "Entrada invalida. Se requiere un numero entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    //esto no sirve de absolutamente nada
    //verifica el input del caso que se quiere probar
    while (true) {
        std::cout << "Elija el caso que quiere probar:" << endl;
        std::cout << "1. Peor Caso" << endl;
        std::cout << "2. Mejor Caso" << endl;
        std::cout << "3. Caso Promedio" << endl;

        std::cin >> cases;

        if (cases < 1 || cases > 3) {
            cerr << "Opcion invalida. Elija entre las opciones propuestas." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // tamaños para hacer la grafica (diferentes Ns)
    cout << "Elige 6 tamaños que quieras probar" << endl;

    for (int i = 0; i < SIZE; ++i) {
        int size;
        std::cin >> size;

        if (size > 1000000) {
            std::cerr << "El tamaño max es 1000000" << endl;
            --i;
            continue;
        }

        sizes[i] = size;
    }

    for (int size : sizes) {
        vector<int> elements(size);

        switch (algorithm) {
            case 1: //el del bubble sort
                for(int caseType : {1, 2, 3}) {
                    if (caseType == 1) generateWCBubble(elements);
                    else if (caseType == 2) generateBCBubble(elements);
                    else if (caseType == 3) generateAVBubble(elements);


                    double time = measureEXCTime(BubbleSort::sort, elements);
                    cout << time << " sec" << endl;
                }
                break;

            case 2: // el de insertion sort
                for (int caseType : {1, 2, 3}) { // Worst, Best, Average
                    if (caseType == 1) generateWCBubble(elements);
                    else if (caseType == 2) generateBCBubble(elements);
                    else if (caseType == 3) generateAVBubble(elements);

                    double time = measureEXCTime(SelectionSort::sort, elements);
                    cout << time << " sec" << endl;
                }
                break;

            case 3: // Merge Sort
                for (int caseType : {1, 2, 3}) {
                    if (caseType == 1) generateWCBubble(elements);
                    else if (caseType == 2) generateBCBubble(elements);
                    else if (caseType == 3) generateAVBubble(elements);

                    double time = measureEXCTime(MergeSort::sort, elements);
                    cout << time << " sec" << endl;
                }
                break;

            case 4: // LinkedList Search
                for (int caseType : {1, 2, 3}) {
                    if (caseType == 1) generateWCLL(list, size);
                    else if (caseType == 2) generateBCLL(list, size);
                    else if (caseType == 3) generateAVLL(list, size);

                    double time = measureEXCtime([&]() {
                        list.search(searchNumber);
                    });
                    cout << "N = " << size << ", Tiempo: " << time << " sec" << endl;
                }
                break;

            case 5: { // Binary Search Tree Insert
                BST<int> bst;  // Utilizando BST genérico
                for (int caseType : {1, 2, 3}) {
                    if (caseType == 1) generateWCBST(elements);  // Peor caso
                    else if (caseType == 2) generateBCBST(elements); // Mejor caso
                    else if (caseType == 3) generateAVBST(elements); // Caso promedio

                    bst = BST<int>(); // Reiniciar el árbol para cada caso
                    double time = measureEXCTimeBST(bst, elements);
                    cout << "N = " << size << ", Tiempo para el caso " << caseType << ": " << time << " sec" << endl;
                }
                break;

            }

        }

    }
    return 0;
}
