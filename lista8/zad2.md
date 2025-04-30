Analiza sturktury str2:
Z pierwszych dwóch linijek możemy wywnioskować że układ str2 w pamięci wygląda jakoś tak:

| rzecz    | zajmowana przestrzen (w byte'ach) |
|  ------  | --------------------------------- |
| array[B] | B                                 |
| padding  | a0                                |
| t        | 4                                 |
| s[A]     | 2A                                |
| padding  | a1                                |
| u        | 8                                 |


Możemy zaważyć pewne warunki, otóż

1. a0 < 4
2. a1 < 8
2. 12 + 2A + a1 = 32 => 2A + a1 = 20 => A = 10 - (1/2)a1, czyli 6 <= A <= 10
3. B + a0 = 8, czyli 4 <= B <= 8

Teraz ze str2 wyciągamy informacje

| rzecz    | zajmowana przestrzen (w byte'ach) |
|  ------  | --------------------------------- |
| x[A]B    | 4 * A * B                         |
| padding  | a2                                |
| y        | 8                                 |

Informacje:

1. a2 < 8
2. 4AB + a2 = 184 => AB = 46 - (1/4)a_2 => czyli 44 <= AB <= 45

Pary liczb  A*B=44:
(1, 44), (2, 22), (4, 11)

Pary liczb A*B=45:
(1,45), (3, 15), (5, 9)

Jak widać jedyne sensowne rozwiązanie to
B = 5
A = 9
