#define WIN32_LEAN_AND_MEAN 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);

int main()
{
	HANDLE hThrd;
	DWORD threadId;

	for (int i = 0; i < 5; i++)
	{
		hThrd =  CreateThread(NULL, 0, ThreadFunc, (LPVOID)i, 0, &threadId);
		if (hThrd)
		{
			printf("Thread lauched %d\n", i);
			CloseHandle(hThrd);
		}
	}
	Sleep(2000);


	return 0;
}

DWORD WINAPI ThreadFunc(LPVOID n)
{
	for (int i = 0; i < 10; i++)
		printf("%d%d%d%d%d%d%d%d%d%d\n", n, n, n, n, n, n, n, n, n, n);
	return 0;
}
