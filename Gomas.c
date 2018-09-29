#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Winner(int size, int *seq)
{
  int i;
  int temp;
  bool isSorted=false;
  bool jake=false;
  int lastSorted=size-1;
  while(!isSorted)
  {
    for(i=0;i<lastSorted;i++)
    {
      if(seq[i]>seq[i+1])
      {
        //swap
        temp=seq[i];
        seq[i]=seq[i+1];
        seq[i+1]=temp;
        isSorted=false;
        if(jake==false)
          jake=true;
        else
          jake=false;
      }
    }
    lastSorted=lastSorted-1;
  }
  return jake;
}

int main()
{
  int size;
  int *seq;
  int i;
  bool jake;

  scanf("%d", &size);

  while(size!=0)
  {
    seq=(int *)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {
      scanf("%d", &seq[i]);
    }

    jake=Winner(size, seq);

    if(jake)
      printf("Jake\n");
    else
      printf("Finn\n");

    scanf("%d", &size);
  }
  return 0;
}
