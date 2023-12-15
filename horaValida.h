/*funcao que checa posicao por posicao para que
  o usuario nao entre com a hora errada.
*/
int validarHora(char hora[]) {
    if ((hora[0] >= '0' && hora[0] <= '2' && hora[1] >= '0' && hora[1] <= '9') &&
        ((hora[0] < '2' || (hora[0] == '2' && hora[1] <= '3')) || (hora[0] == '2' && hora[1] == '3' && hora[3] == '0' && hora[4] == '0')) &&
        hora[2] == ':' &&
        hora[3] >= '0' && hora[3] <= '5' &&
        hora[4] >= '0' && hora[4] <= '9') {
        return 1; // Hora válida
    } else {
        return 0; // Hora inválida
    }
}