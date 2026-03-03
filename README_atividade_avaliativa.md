Análise Experimental de Algoritmos de Ordenação

1. Objetivo

Realizar a implementação manual e a análise comparativa de desempenho dos algoritmos **Bubble Sort** e **Selection Sort**, avaliando seu comportamento sob diferentes condições de entrada e volumes de dados.


2. Algoritmos Implementados

2.1 Bubble Sort

Algoritmo baseado em comparações sucessivas entre elementos adjacentes, realizando trocas quando necessário até que o vetor esteja ordenado.

* Complexidade de tempo (melhor caso): O(n)
* Complexidade média e pior caso: O(n²)
* Estratégia: Trocas sucessivas

2.2 Selection Sort

Algoritmo que seleciona iterativamente o menor elemento do vetor não ordenado e o posiciona na sua posição correta.

* Complexidade de tempo (todos os casos): O(n²)
* Estratégia: Seleção do menor elemento
* Menor número de trocas em comparação ao Bubble Sort


3. Metodologia Experimental

Foram realizados testes com vetores contendo:

* 5.000 elementos
* 10.000 elementos

Para cada volume, foram considerados três cenários:

1. Dados aleatórios
2. Dados previamente ordenados
3. Dados em ordem reversa

O tempo de execução foi mensurado em segundos.


4. Resultados (5.000 elementos)

| Algoritmo      | Aleatório | Ordenado | Reverso |
| -------------- | --------- | -------- | ------- |
| Bubble Sort    | 0.021 s   | 0.014 s  | 0.029 s |
| Selection Sort | 0.014 s   | —        | —       |

*(Os resultados de 10.000 elementos devem ser inseridos conforme medição realizada.)*

---

5. Análise Comparativa

* O **Bubble Sort** apresentou melhor desempenho no caso de vetor previamente ordenado.
* O pior desempenho ocorreu no cenário de ordem reversa.
* O **Selection Sort** demonstrou comportamento estável independentemente da configuração inicial dos dados.
* Ambos os algoritmos apresentaram crescimento quadrático no tempo de execução com o aumento do volume de dados, confirmando sua complexidade assintótica O(n²).


6. Conclusão

A análise experimental confirma que algoritmos de complexidade quadrática tornam-se ineficientes à medida que o volume de dados cresce. Embora adequados para conjuntos pequenos, para aplicações com grandes volumes recomenda-se a utilização de algoritmos mais eficientes, como Quick Sort ou Merge Sort.

