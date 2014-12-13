/**
* Seena Rowhani
* COMP 2401
* Due Thurs. Oct 9th
* 
* Goal:
* You will write a program in C, in the Ubuntu Linux environment, to provide the end user with the ability to encrypt and
* decrypt messages, using a secret key. Your program will prompt the user to indicate whether they wish to encrypt a
* readable (“plaintext”) message or decrypt an already encrypted sequence of numbers (“ciphertext”) back to its
* readable form. You will implement the encryption and decryption algorithm described in the instructions below. In
* order to prevent your enemies from easily cracking your encrypted messages, the algorithm will use an incrementing
* counter to encrypt each character in a slightly different way. Your program will output the result (either the ciphertext
* or the plaintext) to the screen.
*
* Code commented on vigorously.
**/

#include <stdio.h>
#include <string.h>

#define MAX_BUF  256

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char encode(unsigned char, unsigned char, int);


int main(int argc, char *argv[])
{
  char str[8];
  char msg[MAX_BUF];
  char *input;

  unsigned int choice;
  unsigned int dec;
  unsigned int cipher[MAX_BUF];
  int i = 0;
  int size = 0;
  int key;

  if(argc == 1){ // if only 1 arg

    printf("\nYou may:\n");
    printf("  (1) Encrypt a message \n");
    printf("  (2) Decrypt a message \n");
    printf("\n  what is your selection: ");

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &choice);
    switch (choice) { //switch statement denoting which case the end user had chosen
	
      case 1: //if user selected 1 as a choice
        printf("\nEnter plaintext:\n");
        fgets(msg, sizeof msg, stdin);//get input from end user for the message
     
        printf("\nEnter key:\n");
        scanf("%d", &key);//get input from end user for the key

        printf("\nCiphertext:\n\n"); 
        for(i=0 ; i < strlen(msg) -1 ; i++)//for all indexes from 0 to the length of our input msg
          printf("%d ",encode(msg[i], key, i)); //print each encrypted value as an integer
		printf("\n");
        break;

      case 2: //if user entered 2
        printf("\nEnter ciphertext:\n"); //prints a prompt
        
	      while(scanf("%d",&dec) != -1 && dec != -1) //scanf doesnt return false and our input isn't -1
	        cipher[size++] = dec;

        printf("\nEnter key:\n"); 
        scanf("%d",&key); //get input for key

        printf("\nPlaintext:\n\n");
        
        for (i = 0 ; i < size ; i++ )
           printf("%c",encode(cipher[i],key,i)); //print out the result from encode to a character
		printf("\n");
        break;

      default:
        break;
    }
  }
  /*
   * Command line interface for (hopefully) bonus marks)
   */
  else{ 
    /*
     * Command line options
     */
    if(!strcmp(argv[1],"-h")){ //help prompt
      printf("%s <encrypt/decrypt> <plain/cipher> <key>\n", argv[0]);
    }

    else if(!strcmp(argv[1],"encrypt")){ //if first arg is encrypt
      int c;
      printf("\nCiphertext:\n\n");
      for(c=0 ; c < strlen(argv[2]) ; c++)
        printf("%d ", encode(argv[2][c], atoi(argv[3]), c));
      printf("\n");
     }
   
    else if(!strcmp(argv[1],"decrypt")){
      input = strtok(argv[2]," "); //split spaces
      printf("\nPlaintext:\n\n");

        do{ //do while loop
          printf("%c",encode(atoi(input),atoi(argv[3]),i++)); //print out the result from encode to a character
          input = strtok(NULL," "); //split the string, find the next number

        } while(atoi(input)!=-1); //continue running while m doesn't equal 1
      printf("\n");
    }
  }
  return 0; //end program,
}

/*
  Function:  encode
  Purpose:   encrypts or decrypts text
       in:  source: byte intended to be modifed
       in:      key : Integer value that you XOR your bits from source against
       in:   count: index of string being iterated through
   return:  encoded byte
*/
unsigned char encode(unsigned char source, unsigned char key, int count)
{
  unsigned char pt=source;
  char i = 0; //value used to iterate through each bit
  switch(count%3){//count mod 3
    case 0: //case in which it's 0
      for(i=0;i<8;i+=2){//every even number from 0-6
        //if the bit in source at index i (starting from the right) XOR the bit in the key at index i ==0
        if(getBit(source,i)^getBit(key, i)==0)
          pt = clearBit(pt,i); //set the bit at index i of my return value to 0
        else
          pt = setBit(pt,i); //set the bit at index i of my return value to 1
      }
      break;
    case 1: //case where count mod 3 = 1
      i=0;
      for(i=1;i<8;i+=2){ //every odd number, 1-7
        if(getBit(source,i)^getBit(key,i)==0)//not going to comment on this logic, see above
          pt = clearBit(pt,i);
        else
          pt = setBit(pt,i);
      }
      break;
    case 2: //case where count mod 3 = 2
      i=0;
      for(i=0;i<8;i++){ //iterate through every number
        if(getBit(source,i)^getBit(key, i)==0)
          pt = clearBit(pt,i);
        else
          pt = setBit(pt,i);
      }
      break;
    default:
      break;
  }
  return pt;
}


/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)   
{ 
  return (c & 1 << n) >> n;
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)   
{ 
  return c | (1 << n);
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n) 
{ 
  return c & (~ (1 << n) );
}


