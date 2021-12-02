#include <stdio.h>
#include "my_mat.h"

int main (){
    
    int i,j;
    char ch;
    scanf("%c",&ch);

    while(ch!='D'){
        if (ch=='A'){
            userinput();
        }
        else if(ch=='B'){
            scanf("%d",&i);
            scanf("%d",&j);
            int answer=isconnected(i, j);
            if (answer==1)
                printf("True\n");
            else
                printf("False\n");
        }
       else if(ch=='C'){
            scanf("%d",&i);
            scanf("%d",&j);
            int answer=Shortest_route(i, j);
            printf("%d\n", answer);
        }
        scanf("%c",&ch);
    }
    return 0;
}