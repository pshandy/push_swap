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
```
# Решение

## 1. Индексация

Каждому последующему ближайшему большему присваивается индекс, начиная с 0 пока не закончатся элементы стека.

| Число         |    Индекс   |
|:-------------:|-------------|
| -2147483648   | 0 |
| 2100          | 4 |
| 220010        | 6 |
| -1            | 1 |
| 7             | 2 |
| 210815        | 5 |
| 121           | 3 |

## 2. Метки

Каждому элементу стека присваивается метка: оставить ли его в стеке а или переместить.

Начиная с выбранного элемента каждый элемент должен быть больше предыдущего. 
Элементы, не удовлетворяющие этому утверждению, будут перемещены в стек b.

| Число         | Индекс | Оставить в стеке |
|:-------------:|--------|-------------|
| -2147483648   | 0 | true |
| 2100          | 4 | true |
| 220010        | 6 | true |
| -1            | 1 | false |
| 7             | 2 | false |
| 210815        | 5 | false |
| 121           | 3 | false |

## 3. Переещение из стека А в стек B

Псевдокод:
```
ПОКА в стеке A есть элементы с меткой "false"
      ЕСЛИ sa (swap a) необходимо
            выполнить sa (swap a)
            обновить метки
      ИНАЧЕ ЕСЛИ элемент на вершине стека А имеет метку "false"
            выполнить pb (push b)
      ИНАЧЕ
            выполнить ra (rotate a)
```
Проверить необходимость sa можно переместив элемент, изменив разметку и посмотрев стало ли элементов с  "true" больше или нет, вернуть элементы на место.

## 4. Перемещение из стека B в стек A

```
ПОКА стек B не пуст
      выбрать элемент для перемещения из стека В в стек А
      вращать один или оба стека для подготовки к перемещению элемента в нужное место
      выполнить pa (push a)
```
