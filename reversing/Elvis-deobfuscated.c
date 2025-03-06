#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, long param_2)
{
  long lVar1;
  size_t sVar2;
  int local_4c;
  long local_48;

  local_48 = 0x9991bc9c928b91b8;
  if (argc != 2)
  {
    exit(1);
  }
  local_4c = 0;
  while(1) 
  {
    sVar2 = strlen(*(char **)(param_2 + 8));
    if (sVar2 <= (ulong)(long)local_4c) break;

    printf("mine: %c\n", (char *)((long)local_4c + *(long *)(param_2 + 8)));
    printf("his: %c\n", (char *)((long)&local_48 + (long)local_4c));

    if ((int)*(char *)((long)&local_48 + (long)local_4c) !=
        -(int)*(char *)((long)local_4c + *(long *)(param_2 + 8))) {
      exit(1);
    }
    local_4c++;
  }
  puts("Well done");
  return 0;
}
