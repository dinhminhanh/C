#include "BSTree.h"

int main(){
  char choice;


  while(1){
    printf("           ---MENU---\n"
	   "|1.   \n"
	   "|2.                   \n"
	   "|3.             \n"
	   "|4.        \n"
	   "|5.        \n"
	   "|6. Quit.           |\n");

    fflush(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '6' || choice < '1'){
      fflush(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }
    
    switch(choice){
    case '1':{

      break;
    }

    case '2':{
      break;
    }

    case '3':{
      break;
    }

    case '4':{

      break;
    }

    case '5':{

      break;
    }

    case '6':{
      exit(1);
      break;
    }
    }
  }
  return 0;
}
