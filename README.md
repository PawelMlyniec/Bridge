
# Graph algorithms project

*Bridge* in our case we call edge in connected graph which deleting (by deleting verices and all edges connected to those vertices) will cause unnconection of these graph.

1.Program reads grapf redirected from standard input
2.Program finds and prints all *bridges*



## excample of input

    >./program < plik_z_opisem_grafu

## input format
in first line ther is positive number idicating number of all nodes in graph. Below for evey edge there is line with vertices constructing it. Numeration starts from 0. Numbers in each line are seperated by space. Corectness of input could be assumed.


## Exaple 1

graf.txt:

    3
    0 1
    1 2
    2 0

output:

    >./program < graf.txt
    >

## Excample 2

graf.txt:

    4
    0 1
    1 2
    2 3
    3 0
    0 2

output:

    >./program < graf.txt
    0 2
    >

lub:

    >./program < graf.txt
    2 0
    >

