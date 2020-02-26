/* Powyższy program prawdopodobnie używał indeksowania tablic. 
Jeśli tak, to przerób go aby korzystał ze wskaźników i aby nigdzie w kodzie nie występowało liczby[i].*/



 #include <stdio.h>

 int main(){

    int liczby[50];

    int *wsk, *wsk2;


    wsk = &liczby[0];
    wsk2 = liczby;


    for(int i = 0; i <50; i++){
        wsk++;
        scanf("%d",wsk);
        printf("hej\n");
        printf("%ls", (wsk));
        if(*wsk ==0){
            break;
        }
    }

    for(int j = 0; j <50;j++ ){
        wsk2++;
        if(*wsk2>10 && *wsk2<100){
            printf("%d\n",*wsk2);
        }
    }


    printf("hej\n");
    return 0;
 }