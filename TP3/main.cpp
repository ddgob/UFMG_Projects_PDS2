#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '5'.
    int q1 = 5;
    
    // 2) Declare um vetor de inteiros e inicialize com valores de 0 a 9.
    int q2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 3) Declare um ponteiro para inteiros e inicialize com valor nulo.
    int *q3 = nullptr;

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &q1 << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << q1 << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &q2 << endl;

    // 7) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &q3 << endl;
    
    // 8) Imprima o VALOR da variável declarada em (3)
    cout << q3 << endl;

    // 9) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (3)
    q3 = &q1;

    // 10) Imprima o VALOR da variável declarada em (3)
    cout << q3 << endl;

    // 11) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    cout << *q3 << endl;

    // 12) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (3)
    cout << (&q1 == q3) << endl;

    // 13) Coloque o VALOR '10' no ENDEREÇO apontado por (3)
    *q3 = 10;

    // 14) Imprima o VALOR da variável declarada em (1)
    cout << q1 << endl;

    // 15) Atribua o ENDEREÇO da variável (2) à variável declarada em (3)
    q3 = q2;

    // 16) Imprima o VALOR da variável declarada em (3)
    cout << q3 << endl;

    // 17) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    cout << *q3 << endl;

    // 18) Atribua o ENDEREÇO da primeira posição de (2) à variável declarada em (3)
    q3 = &q2[0];

    // 19) Imprima o VALOR da variável declarada em (3)
    cout << q3 << endl;

    // 20) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    cout << *q3 << endl;

    // 21) Multiplique todos os valores do vetor declarado em (2) por '10', porém manipulando apenas a variável (3)
    for(int i = 0 ; i < 10; i++) {
        *q3 = *q3 * 10;
        q3++;
    }

    // 22) Imprima os elementos de (2) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i = 0; i < 10; i++) {
        cout << q2[i] << " "; 
    }
    cout << endl;

    // 23) Imprima os elementos de (2) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for(int i = 0; i < 10; i++) {
        cout << *(q2+i) << " ";
    }
    cout << endl;

    // 24) Imprima os elementos de (2) manipulando apenas a variável (3)
    for(int i = 0; i < 10; i++) {
       q3--;
    }
    for(int i = 0; i < 10; i++) {
        cout << *q3 << " ";
        q3++;
    }
    cout << endl;
    
    // 25) Imprima o resultado da comparação do VALORES armazenado na quinta posição de (2) e no ponteiro (3) incrementado de 4
    for(int i = 0; i < 10; i++) {
        q3--;
    }
    cout << (q2[4] == *(q3+4)) << endl;

    // 26) Atribua o ENDEREÇO da quinta posição de (2) à variável declarada em (3)
    q3 = &q2[4];

    // 27) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    cout << *q3 << endl;

    // 28) Imprima o VALOR guardado no ENDEREÇO do ponteiro (3) decrementado de 4
    cout << *(q3-4) << endl;
    
    return 0;
}