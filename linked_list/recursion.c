// this program explains recursive left and recursive right

#include<stdio.h>
#include<stdlib.h>

// placing recursive after the printf makes it left to right
void recursive_l(int A[], int n, int c)
{
	if(c < n)
	{
		printf("%d\n", A[c]);
		recursive_l(A, n, c + 1);

	}

}

// placing recursive function before makes it in opposite order ie. right->left
void recursive_r(int A[], int n, int c)
{
	if(c < n)
	{
		recursive_r(A, n, c+1);
		printf("%d\n", A[c]);
	}
}

int main()
{
	int A[] = {1, 2, 3, 4, 5};
	printf("Recurive Left\n");
	recursive_l(A, 5, 0);
	printf("Recursive Right\n");
	recursive_r(A, 5, 0);
}
