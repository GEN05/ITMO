#   Лабораторная работа №2
##  Весёлый канонир
### Описание
Вы - часть команды небольшого парусного судна, вооружённого двумя пушками,
каждая из которых обороняет сой борт.
К сожалению, в данный момент все вы попали в переделку,
столкнувшись с несколькими вражескими кораблями.
В бою Вашей задачей является координировать действия артиллеристов,
указывая с какого борта и под каким углом к направлению движения вашего судна,
с поправкой на наклон, требуется произвести залп, чтобы потопить вражеский корабль.  

Считаем, что пушки можно поворачивать на угол b вправо или влево от нормали к борту, -60 < b < 60.
Положительный угол отсчитывается в направлении движения корабля.
Если требуется повернуть на угол, больший чем 60, считаем, что ориентация корабля не позволяет сделать выстрел.
#### Входные данные
1.  Радиус-вектор v определяющий положение вашего корабля;
1.  Вектор a определяющий ориентацию киля вашего судна;
1.  Направление мачты m;
1.  Радиус-вектор w определяющий положение вражеских кораблей;
#### Выходные данные
1.  Борт корабля. 1 если борт левый, -1 если правый, 0 если ориентация коробля не позволяет сделать выстрел;
1.  Угол b, отсчитываемый от нормали к борту и плоскости моря -60 < b < 60;
1.  Угол y наклона мачты, отсчитываемый от вертикали, -60 <= y <= 60;
1.  Любое прощальное слово;