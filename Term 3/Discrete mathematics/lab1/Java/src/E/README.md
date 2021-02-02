Кодирование Прюфера переводит помеченные деревья порядка n в последовательность чисел от 1 до n по алгоритму:  
Пока количество вершин больше двух:

1. Выбирается лист v с минимальным номером.
1. В код Прюфера добавляется номер вершины, смежной с v.
1. Вершина v и инцидентное ей ребро удаляются из дерева.

Полученная последовательность называется кодом Прюфера (англ. Prüfer code) для заданного дерева.

#### Ошибки

| Описание               | Тип                              | Номер теста|
|:----------------------:|:--------------------------------:|:----------:|
| Поиск листьев за линию | Превышено ограничение по времени | 8          |
| избавиться от `remove` | Превышено ограничение по времени | 13         |