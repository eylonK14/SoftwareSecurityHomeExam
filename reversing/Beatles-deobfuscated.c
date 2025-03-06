#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
  int iVar1;
  size_t sVar2;
  int counter;
  long password;

  password = 0x746e6271684d;

  if (argc != 2) 
  {
    exit(1);
  }
  
  counter = 0;
  while(1)
  {
    sVar2 = strlen(argv[1]);
    if (sVar2 <= (ulong)(long)counter) break;
    *(char *)((long) &password + (long) counter) =
         (char) counter + *(char *)((long) &password + (long)counter);
    counter++;
  }
  
  // ====== ADD THIS LINE BELOW ======
  printf("%s", (char *) &password);
  // ====== ADD THIS LINE ABOVE ======
  
  iVar1 = strcmp(argv[1],(char *) &password);
  if (iVar1 == 0) 
  {
    puts("Well done");
  }
  
  return 0;
}
