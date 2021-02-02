Добавляем к первой таске в цикл это
``` JAVA
if (i == n - 1) {
    i = 2;
    while (!graph[answer[0]][answer[i]]) {
        i++;
    }
}
```