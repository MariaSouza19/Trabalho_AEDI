#include <stdio.h>  //para entradas e saidas

//funcao que calcula se o ano e' bissexto
int AnoBissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

//funcao para validar a data por dia, mes e ano separadamente
int DataValida(int dia, int mes, int ano)
{
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1)
    {
        return 0;
    }

    //define o numero maximo de dias que um mes pode ter
    int maxDias = 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        maxDias = 30;
    }
    else if (mes == 2)
    {
        maxDias = AnoBissexto(ano) ? 29 : 28;
    }

    return dia <= maxDias;
}