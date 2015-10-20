/* The second of many musical programs to be written */
#include <stdio.h>

int main()
{
  int test = sizeof(int);
  int best = sizeof(char);
  int zest = sizeof(short);
  int fest = sizeof(long);
  int blank = sizeof(float);
  int flank = sizeof(double);


  printf("int size: %d\n", test);
  printf("char size: %d\n", best);
  printf("short size: %d\n", zest);
  printf("long size: %d\n", fest);
  printf("float size: %d\n", blank);
  printf("double size: %d\n", flank);
  return 0;
}
