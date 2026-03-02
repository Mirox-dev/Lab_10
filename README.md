# Lab_10 — Шаблонный конвейер (Pipeline)

*[Русский](#ru) | [English](#en)*

---

<a name="ru"></a>

## Описание

Учебная программа на **C++17**, демонстрирующая шаблонный класс конвейера `MyPipeLine<T>`. Конвейер позволяет последовательно применять цепочку именованных операций к значению произвольного типа.

## Возможности `MyPipeLine<T>`

| Метод | Описание |
|---|---|
| `addStep(name, func)` | Добавить шаг с именем и функцией `T(T)` |
| `removeStep(index)` | Удалить шаг по индексу |
| `run(value)` | Запустить конвейер и вернуть итоговое значение |
| `trace(value)` | Вернуть вектор промежуточных результатов каждого шага |
| `size() / empty() / clear()` | Информация и управление |
| `operator<<` | Вывод списка шагов в поток |

## Примеры из программы

**Целочисленный конвейер** (вход: 8):
1. Число Фибоначчи → `21`
2. Возведение в квадрат → `441`
3. Остаток от деления на 16 → `9`

**Строковый конвейер** (вход: `"Abracadabra"`):
1. Учетверение строки
2. Удаление символов `A/a`
3. Перевод в верхний регистр

## Требования

- Компилятор с поддержкой **C++17**

## Сборка и запуск

```bash
g++ -std=c++17 main.cpp -o pipeline
./pipeline
```

---

<a name="en"></a>

## Description

An educational **C++17** program demonstrating a generic pipeline class `MyPipeLine<T>`. The pipeline applies a chain of named operations to a value of any type.

## `MyPipeLine<T>` API

| Method | Description |
|---|---|
| `addStep(name, func)` | Add a step with a name and a `T(T)` function |
| `removeStep(index)` | Remove a step by index |
| `run(value)` | Execute the pipeline and return the final value |
| `trace(value)` | Return a vector of intermediate results after each step |
| `size() / empty() / clear()` | Inspection and control |
| `operator<<` | Print the step list to a stream |

## Examples from the program

**Integer pipeline** (input: 8):
1. Fibonacci number → `21`
2. Square → `441`
3. Modulo 16 → `9`

**String pipeline** (input: `"Abracadabra"`):
1. Quadruple the string
2. Remove all `A/a` characters
3. Convert to uppercase

## Requirements

- Compiler with **C++17** support

## Build & Run

```bash
g++ -std=c++17 main.cpp -o pipeline
./pipeline
```
