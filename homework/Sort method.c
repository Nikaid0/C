
//交换排序法(升序)
#define N 5
main()
{
  int i,j,t,a[N];
  for(i=0;i<N-1;i++)
    for(j=i+1;j<N;j++)
        if(a[i]>a[j])
          {t=a[j];a[j]=a[i];a[i]=t;}//如果后者数值较前者小就交换
  return 0;
}
//          *             *             *

//选择排序法(升序)
#define N 5
main()
{
  int i,j,p,t,a[N];
  for(i=0;i<N-1;i++)
  {   p=i;
    {
       for(j=i+1;j<N;j++)
          if(a[p]>a[j])
              p=j;//交换下标，而不是通过数组直接交换
       if(p!=i)
          {t=a[p];a[p]=a[i];a[i]=t;}
    }
  }
  return 0;
}
