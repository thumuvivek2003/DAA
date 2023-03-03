```c
// Your C code goes here

#include<stdio.h>
int heapsize,length;
void print(int a[],int size){
	for(int i=0;i<size;i++)printf("  %d ",a[i]);
	printf("\n");
}
void heapify(int a[],int i)
{
    int larg=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heapsize && a[left]>a[larg])
        larg=left;
    else larg=i;
    if(right<heapsize && a[right]>=a[larg])
        larg=right;
    if(larg!=i)
    {
        int tmp=a[i];
        a[i]=a[larg];
        a[larg]=tmp;
    
    heapify(a,larg);
    }
}
void build_heap(int a[] )
{
    for(int i=length/2;i>=0;i--)
       heapify(a,i);
}
void heapsort(int a[] )
{
   build_heap(a );
   for(int i=length-1;i>=0;i--)
   { 
        int tmp=a[0];
          a[0]=a[i];
          a[i]=tmp;
          heapsize--;
          heapify(a,0);
    }
}
int main(){
    
    
    int a[7]={77,66,55,44,33,22,11};
    printf("Array before heap sort : ");
    length=heapsize=7;
    print(a,length);
    heapsort(a);
    printf("Array after heap sort : ");
    print(a, length);
}
