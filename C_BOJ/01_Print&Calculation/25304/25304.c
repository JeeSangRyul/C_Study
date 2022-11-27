#include <stdio.h>

int main()
{
  int x,n,result;
  int a,b;

  result = 0;
  scanf("%d\n%d", &x, &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    result = result + (a * b);
  }
  if (result == x)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
