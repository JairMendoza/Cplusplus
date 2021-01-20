#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define TROZO 100*1024*1024
#define PUNTO (10*1024*1024)
 
 void accede (char * p, unsigned long long tam)
 {
 	unsigned long long i;
 	for(i=0;i<tam;i++)
 	{
 		p[i]='a';
 		if((i%PUNTO)==0)
 			write (1,".",1);/*imprime un punto cada 10 Mbytes accedidos*/
	 }
  } 
  main(int argc,char*argv[])
  {
  	char *p;
  	unsigned long long  total=0, cantidad=TROZO;
  	unsigned long long maximo=ULLONG_MAX;
	  if(argv[1]!=NULL){
	  	maximo=strtoull(argv[1],NULL,10);
	  	if(argv[2]!=NULL)
	  		cantidad=strtoull(argv[2],NULL,10);
	   } 
	   while (total<maximo && (p!=malloc(cantidad))!=NULL){
	   		total+=cantidad;
	   		printf("asignados %llu (total:%llu) bytes en %p\n",cantidad, total,p);
	   		printf("Total asignacion: %llu\n",total);
	   		accede(p,cantidad);
	   		getchar();
	   		
	   }
	   
	   //sleep(10);
  }
  
  
  
  
  

  
