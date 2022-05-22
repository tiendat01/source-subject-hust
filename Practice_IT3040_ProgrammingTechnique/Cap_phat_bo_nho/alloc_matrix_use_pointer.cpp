#include <stdio.h>

void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}


void input(int **mt, int m, int n){
    //#Input elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/ 
    
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}