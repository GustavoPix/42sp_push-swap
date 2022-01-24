# Push_swap

Primeiro projeto da segunda fase da 42sp. Utilizando apenas duas stacks, o objetivo deste projeto é ordenar os números recebidos como parâmetro e imprimir os movimentos utilizados.

## Execução

`./push_swap N`

- `N` -> N números inteiros não repetíveis sendo MIN_INT ≤ N ≤ MAX_INT

## Saída

O programa irá imprimir os comandos utilizados para ordenar os números

## Movimentos

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Compilação

`make` compila o projeto (mandatório com 2 cmds)
`make clean` apaga os arquivos compilados
`make fclean` apaga os arquivos e o programa

## Checker

Para checar se o programa ordenou corretamente, pode ser utilizado o *checker*

`ARGS="5 4 2 1"; ./push_swap $ARGS | ./checker $ARGS`

## Pyviz

*pyviz* é um visualizador do push_swap criado por *o-reo*

`python3 pyviz.py \`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"\``

Para rodar o *pyviz*, é necessário possuir o python e o `tkinter`.

Para instalar o tkinter: `sudo apt-get install python3-tk`.
