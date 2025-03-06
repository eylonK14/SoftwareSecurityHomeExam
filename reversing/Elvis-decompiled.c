undefined8 main(int param_1,long param_2)
{
  long lVar1;
  size_t sVar2;
  long in_FS_OFFSET;
  int local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = 0x9991bc9c928b91b8;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  if (param_1 != 2) {
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  lVar1 = ptrace(PTRACE_TRACEME,0,0,0);
  if ((int)lVar1 != 0) {
    puts("No Debuggers");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  local_4c = 0;
  while( true ) {
    sVar2 = strlen(*(char **)(param_2 + 8));
    if (sVar2 <= (ulong)(long)local_4c) break;
    if ((int)*(char *)((long)&local_48 + (long)local_4c) !=
        -(int)*(char *)((long)local_4c + *(long *)(param_2 + 8))) {
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    local_4c = local_4c + 1;
  }
  puts("Well done");
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}
