/* program writtern by manush desai*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user , rock ,paper ,scissor,highscore=0;
   
   
    
   
       
    while(1){    

        


      


       
        printf("enter 0 for rock ,1 for paper or 2 for scissor\n");
        scanf("%d",&user);
        rock==0;
        paper==1;
        scissor==2;
        srand(time(0));


        int randomNumber = rand() % 3;
         
        if(randomNumber == 0){
            printf("compter selected stone\n");
        }
            else if(randomNumber == 1){
                    printf("compter selected paper \n");}
            else if(randomNumber == 2){
                printf("compter selected scissor\n ");}
        




        
    if(user==0 && randomNumber==1){
        printf("computer wins\n");
          break;        }
        else if (user==0 && randomNumber== 2){
        printf("computer loose\n");
            highscore++;
        }
    else if(user==0&&randomNumber==0){
        printf("draw\n");
    }
    else if(user==1&& randomNumber==0){
        printf("computer loose\n");
        highscore++;
    }
    else if(user==1 && randomNumber==1){
        printf("draw\n");
    }
    else if(user==1 &&  randomNumber==2){
        printf("computer wins\n");
        break;
    }
    else if(user==2 &&  randomNumber==0){
        printf("computer wins\n");
        break;
        
    }
    else if(user==2 && randomNumber==1 ){
         printf("computer loose\n");
        highscore++;
        
    }
    else if(user==2 && randomNumber==2){
         printf("draw\n");
    }
    
    }
    printf("your score is %d\n",highscore);
    return 0;
    
    }
        
    
    
