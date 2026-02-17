# Atividade – Árvores e Grafos – Semana 2

## Descrição
Implementação dos algoritmos Bubble Sort e Selection Sort,
com medição de tempo, comparações e movimentações.

## Análise dos Resultados

Os testes foram realizados com vetores em ordem decrescente, representando o pior caso para ambos os algoritmos.

Observou-se que:
	•	Tanto o Bubble Sort quanto o Selection Sort apresentaram o mesmo número de comparações, crescendo proporcionalmente a n^2, confirmando a complexidade O(n²).
	•	Entretanto, o Bubble Sort realizou um número muito maior de movimentações, pois realiza trocas a cada inversão encontrada.
	•	Já o Selection Sort realiza apenas uma troca por iteração externa, resultando em muito menos movimentações.

Nos testes com 10.000 elementos:
	•	Bubble Sort
	•	Tempo: 164 ms
	•	Movimentações: 149.985.000
	•	Selection Sort
	•	Tempo: 65 ms
	•	Movimentações: 15.000

## Conclusão

Apesar de ambos os algoritmos possuírem complexidade O(n²), o Selection Sort apresentou melhor desempenho nos testes realizados, principalmente devido ao número significativamente menor de movimentações, o que impactou diretamente no tempo de execução.
