#include<stdio.h>
#include<string.h>
#define MAXCHAR 256
int res[256],k=-1;
void rabinKarpSearch(char* mainString, char* pattern, int prime) {
   int patLen = strlen(pattern);
   int strLen = strlen(mainString);
   int charIndex, pattHash = 0, strHash = 0, h = 1;

   for(int i = 0; i<patLen-1; i++) {
      h = (h*MAXCHAR) % prime;    //calculating h = {d^(M-1)} mod prime
   }

   for(int i = 0; i<patLen; i++) {
      pattHash = (MAXCHAR*pattHash + pattern[i]) % prime;    //pattern hash value
      strHash = (MAXCHAR*strHash + mainString[i]) % prime;   //hash for first window
   }

   for(int i = 0; i<=(strLen-patLen); i++) {
      if(pattHash == strHash) {      //when hash values are same check for matching
         for(charIndex = 0; charIndex < patLen; charIndex++) {
            if(mainString[i+charIndex] != pattern[charIndex])
               break;
         }

         if(charIndex == patLen)    //the pattern is found
            res[++k] = i;
      }

      if(i < (strLen-patLen)) {    //find hash value for next window
         strHash = (MAXCHAR*(strHash - mainString[i]*h) + mainString[i+patLen])%prime;
         if(strHash < 0) {
            strHash += prime;    //when hash value is negative, make it positive
         }
      }
   }
}

main()
{
	char T[255],P[255],nT,nP,q;
	printf("enter text: ");
	scanf("%s",&T);
	nT=strlen(T);
	printf("enter pattern: ");
	scanf("%s",&P);
	nP=strlen(P);
	//RK
	int prime = 101;
   	rabinKarpSearch(T, P, prime);
   	for(int i = 0; i <= k; i++)
	   	printf("Pattern found at position %d\n",res[i]);
}
