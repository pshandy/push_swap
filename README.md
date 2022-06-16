# push_swap
Поиск и реализация оптимальной сортировки стека.

# Задание
- Даны два стэка a и b
- Стек содержит a случайное количество отрицательных и/или положительных чисел.
- Стек b пуст
- Цель состоит в том, чтобы отсортировать числа в порядке возрастания в стеке a,используя следующие операции:

| Инструкции    |    Описание   |
|:-------------:|---------------|
| sa            | Поменять первые два элемента стека А местами |
| sb            | Поменять первые два элемента стека В местами |
| ss            | Применить sa и sb одновременно |
| pa            | Переместить первый элемент с вершины стека А в стек В |
| pb            | Переместить первый элемент с вершины стека В в стек А |
| ra            | Кольцевой сдвиг всех элементов стека А вверх на 1 позицию|
| rb            | Кольцевой сдвиг всех элементов стека В вверх на 1 позицию|
| rr            | Применить ra и rb одновременно |
| rra           | Кольцевой сдвиг всех элементов стека А вниз на 1 позицию|
| rrb           | Кольцевой сдвиг всех элементов стека В вниз на 1 позицию|
| rrr           | Применить rra и rrb одновременно |

# Пример выполнения

```
-------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b 
-------------------------------------------------------------------------------------------------------


# Решение

## 1. Индексация

By the task we know that given numbers cannot contain duplicates. So we can assign index for each number. It will help us in future steps.

The index 0 will be assigned to the smallest number. To the largest number will be assigned the count of numbers - 1 index.

| Число         |    Индекс   |
|:-------------:|-------------|
| -2147483648   | 0 |
| 2100          | 4 |
| 220010        | 6 |
| -1            | 1 |
| 7             | 2 |
| 210815        | 5 |
| 121           | 3 |
