#ifndef VALIDARDADOS_H_INCLUDED
#define VALIDARDADOS_H_INCLUDED
#endif // VALIDARDADOS_H_INCLUDED

#include <stdio.h> //para entradas e saidas
#include <string.h>

// funcao que calcula se o ano e' bissexto
int AnoBissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// funcao para validar a data por dia, mes e ano separadamente
int DataValida(int dia, int mes, int ano)
{
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1)
    {
        return 0;
    }

    // define o numero maximo de dias que um mes pode ter
    int maxDias = 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        maxDias = 30;
    }
    else if (mes == 2)
    {

        if (AnoBissexto(ano) == 29)
        {
            maxDias = 29;
        }
        else if (AnoBissexto(ano) == 28)
        {
            maxDias = 28;
        }
    }

    if (dia <= maxDias)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// FUNCAO PARA VALIDAR A HORA

/*funcao que checa posicao por posicao para que
  o usuario nao entre com a hora errada.
*/
int validarHora(char hora[])
{
    if ((hora[0] >= '0' && hora[0] <= '2' && hora[1] >= '0' && hora[1] <= '9') &&
        ((hora[0] < '2' || (hora[0] == '2' && hora[1] <= '3')) || (hora[0] == '2' && hora[1] == '3' && hora[3] == '0' && hora[4] == '0')) &&
        hora[2] == ':' &&
        hora[3] >= '0' && hora[3] <= '5' &&
        hora[4] >= '0' && hora[4] <= '9')
    {
        return 1; // Hora válida
    }
    else
    {
        return 0; // Hora inválida
    }
}

// valida as siglas dos aeroportos
int validarAero(char aeroporto[])
{
    if (((aeroporto[0] >= 'a' && aeroporto[0] <= 'z' || aeroporto[0] >= 'A' && aeroporto[0] <= 'Z') &&
         (aeroporto[1] >= 'a' && aeroporto[1] <= 'z' || aeroporto[1] >= 'A' && aeroporto[1] <= 'Z') &&
         (aeroporto[2] >= 'a' && aeroporto[2] <= 'z' || aeroporto[2] >= 'A' && aeroporto[2] <= 'Z')))
    {
        return 1; // Aeroporto válid
    }
    else
    {
        return 0; // Aeroporto inválido
    }
}

// valida se a cidade tem apenas letras
int validarCidade(char cidade[])
{
    for (int i = 0; i < strlen(cidade); i++)
    {
        if (cidade[i] >= 'a' && cidade[i] <= 'z' || cidade[i] >= 'A' && cidade[i] <= 'Z')
        {
                }
        else
        {
            return 0;
        }
    }
}