#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //

int main(int argc, char const *argv[]){
char fileFrom [255];
char fileTo [255];
char buffer[4096];
int numberOfBytes = 0;
int readVal;
int writeVal;

puts("Welcome to the File Copy Program by Carlos Lopez!");

puts("Enter the name of the file to copy from:");

scanf("%s", fileFrom);

puts("Enter the name of the file to copy to:");

scanf("%s", fileTo);

int readfd = open( fileFrom, O_RDONLY| O_CREAT, S_IRWXU);

int writefd = open(fileTo,O_RDWR|O_CREAT| O_EXCL|O_TRUNC, S_IRWXU);

// successfull,
if(readfd > 0 && writefd > 0){
	
	// arbitrary value to start loop
	readVal = 1;
	while(readVal != 0){
			readVal = read(readfd, buffer, BUFF_MAX);
			writeVal = write(writefd, buffer,readVal);
//			printf("buffr1: %d\n", writeVal);
		numberOfBytes +=readVal;
		}	 
//	printf("Number Of Bytes In: %d\n", numberOfBytes);
		
}
// did not work
else
	puts("Input/Ouput file did not read properly.");

printf("File Copy Successful, %d bytes copied\n", numberOfBytes);



  return 0;
}
