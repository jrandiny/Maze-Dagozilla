# Maze-Dagozilla

Program untuk menyelesaikan maze dengan algoritma A* sederhana.

## Maze

Maze yang dimaksud disini adalah labirin yang punya 1 titik start dan 1 titik tujuan.

## Compile

Untuk *mengcompile* program ini tidak butuh *library* khusus, yang perlu diperhatikan hanyalah menggunakan standard c++ 2011
```
g++ -std=c++11 -o maze *.cpp
```

## Pemakaian

Untuk memakai tinggal menjalankan program dan nanti akan ditanya input baik manual maupun dari file.

Program ini berisi logging yang sangat *verbose*, untuk mematikan ini bisa dengan mengalihkan logging ke file eksternal.
```
./maze 2>maze.log
```
