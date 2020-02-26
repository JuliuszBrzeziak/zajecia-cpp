/* Napisz (albo odszukaj w archiwum zadań domowych z pierwszego roku studiów) program 
w C deklarujący tablicę int liczby[50] i wczytujący do niej z klawiatury kolejne liczby.
 Wczytywanie należy przerwać gdy użytkownik wpisze zero lub po wczytaniu 50 liczb.
 Dodaj do powyższego programu pętlę for idącą przez wszystkie wczytane liczby i drukującą te z nich, które są większe od 10 i mniejsze od 100.*/

 #include <stdio.h>

 int main(){

    int liczby[50];


    for(int i = 0; i <50; i++){
        scanf("%d",&liczby[i]);
        if(liczby[i]==0){
            break;
        }
    }

    for(int j = 0; j <50;j++ ){
        if(liczby[j]>10 && liczby[j]<100){
            printf("%d",liczby[j]);
        }
    }


    printf("hej\n");
    return 0;
 }