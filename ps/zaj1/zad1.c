/* Napisz (albo odszukaj w archiwum zadań domowych z pierwszego roku studiów) program 
w C deklarujący tablicę int liczby[50] i wczytujący do niej z klawiatury kolejne liczby.
 Wczytywanie należy przerwać gdy użytkownik wpisze zero lub po wczytaniu 50 liczb.*/

 #include <stdio.h>

 int main(){

    int liczby[50];


    for(int i = 0; i <50; i++){
        scanf("%d",&liczby[i]);
        if(liczby[i]==0){
            break;
        }
    }


    printf("hej\n");
    return 0;
 }