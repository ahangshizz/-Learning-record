//#include<stdio.h>
//int	main()
//{
//	int	count = 0;
//	int	i = 0;
//		for (i = 100; i <= 200; i++)
//	{
//	int	j = 0;
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (i == j)
//		{
//			count++;
//			printf("%d\t", i);
//		}
//		}printf("count=%d\n\n", count);
//	return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	int	i = 0;
//	int	j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ",i,j,i*j);
//		}printf("\n");
//	}
//	return	0;
//}
//#include <stdio.h>
//int	main()
//{
//	int	y =0;
//	int	count = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (y % 4 == 0)
//		{
//			if (y % 100 != 0)
//			{
//				count++;
//				printf("%d ", y);
//			}
//			
//		}
//		 if (y % 400 == 0)
//		{
//			count++;
//			printf("%d ", y);
//		}
//	}printf("\ncount=%d", count);
//	return	0;
//}
//#include	<stdio.h>
//int main()
//{
//	int y = 0;
//	int count = 0l;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
//		{
//			count++;
//			printf("%d ", y);
//		}
//	}printf("\ncount=%d", count);
//	return 0;
//	getchar();
//}
//#include <stdio.h>
//int main()
//{
//	int y = 0;
//	int num = 0;
//	printf("����һ����ݣ�(���س�������) ");
//	scanf("%d",&num );
//	if ((num % 400 == 0) || ((num % 4 ==0) && (num % 100 != 0)))
//	{
//		printf("%d������", num);
//	}
//	else
//	{
//		printf("%d��������", num);
//	}
//	return 0;
//}
//
