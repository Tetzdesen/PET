# 🚍 Problema de Escalonamento de Tripulações (PET)

Este projeto aborda o **Problema de Escalonamento de Tripulações (PET)** no contexto do transporte rodoviário urbano. O objetivo é atribuir tarefas (trechos de viagens) a tripulações (motoristas) de modo a minimizar o custo associado ao uso de recursos humanos.

---

## 🧠 Descrição do Problema

O PET consiste na alocação de tarefas diárias a tripulantes de ônibus urbano, buscando:

- **Minimizar** horas extras, tempo ocioso, tempo de sobreposição e tempo excedente.
- **Eliminar** situações de sobreposição de tarefas e excessos de jornada.

A função objetivo do problema é definida por:

```
f(s) = ∑(w1 * HEj + w2 * TOj + w3 * TSj + w4 * TEj)
```

Onde:
- `HEj`: horas extras da tripulação *j*
- `TOj`: tempo ocioso
- `TSj`: tempo de sobreposição
- `TEj`: tempo excessivo
- `w = {1, 1, 100, 100}`: vetor de penalização (ajustável)

---

## 📥 Instâncias de Entrada

O problema será testado com 5 instâncias distintas, contendo:
- 25 tarefas
- 50 tarefas
- 100 tarefas
- 250 tarefas
- 500 tarefas

Cada tarefa representa um trecho de viagem com informações de tempo, e os dados estão expressos em minutos.

---

## 🛠️ Estrutura do Projeto

O código deve ser implementado em **C ou C++**, contendo:

- Leitura e armazenamento de instâncias
- Geração de uma solução inicial (heurística construtiva)
- Cálculo da função objetivo
- Armazenamento e clonagem de múltiplas soluções
- Impressão detalhada das soluções (tela e arquivo)

---

## ✅ Requisitos Funcionais

- Definir um número estimado de tripulações `m` (ex: `m = tarefas / 2`)
- Assegurar que **todas** as tarefas sejam atribuídas a **alguma** tripulação
- Gerar soluções viáveis, com foco em minimizar a função objetivo

---

## 📄 Saída Esperada

O programa deve fornecer, para cada solução:
- Horas extras (HE) por tripulação
- Tempo ocioso (TO)
- Tempo de sobreposição (TS)
- Tempo excedente (TE)
- Valor total da função objetivo
- Escala de trabalho por tripulação

---

## 🧪 Exemplos e Testes

> ⚠️ As instâncias de teste devem ser disponibilizadas na pasta `instancias/` (não incluídas neste repositório por padrão).

---

## 💡 Autores e Disciplina

Autor: Gabriel Tetzner Menegueti

Este projeto foi desenvolvido para a disciplina **COM10393 – Métodos de Otimização** do curso de Computação da **Universidade Federal do Espírito Santo (UFES)**.
