int functionfibonacci(int num){

    int resultado = num;

    if (num == 0 )
        return 0;
    else if (num == 1)
        return 1;
    else
        do {
            resultado = resultado*(num-1);
            num--;
        }
        while (num > 1);
    
    return resultado;

}