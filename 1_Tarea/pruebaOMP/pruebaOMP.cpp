// pruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <omp.h>

// N: Number of elements to handle in the arrays
#define N 100
// chunk: Size of the array chunks for each thread to process
#define chunk 10
// mostrar: Controls how many elements to print
#define mostrar 5

// Function declaration to print an array
void imprimeArreglo(float* d);

int main() {

    // Inform the user about the operation
    std::cout << "Sumando Arreglos en Paralelo!!!\n\n\n";

    // Declare arrays and variables
    // a and b will store values; c will store the sum of corresponding elements from a and b
    float a[N], b[N], c[N];
    int i;

    // Initialize arrays a and b with calculated values
    for (i = 0; i < N; i++) {
        a[i] = i * 5;            // Fill array a with values based on a linear calculation
        b[i] = (i + 2) * 2;     // Fill array b with values based on a linear calculation
    }

    // Define the chunk size for parallel processing
    int pedazos = chunk;

    // Perform parallel addition of arrays a and b into array c
#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];  // Calculate the sum for each element
    }

    // Print the first 'mostrar' elements of each array
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);  // Print array a
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);  // Print array b
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);  // Print array c
}

// Function to print the first 'mostrar' elements of a given array
void imprimeArreglo(float* d) {

    for (int x = 0; x < mostrar; x++) {
        std::cout << d[x] << " - ";
    }

    std::cout << std::endl;
}