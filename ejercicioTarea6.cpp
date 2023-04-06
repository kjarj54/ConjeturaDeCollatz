#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void collatz(int num) {
  while (num != 1) {
    printf("%d, ", num);
    if (num % 2 == 0)
      num = num / 2;
    else
      num = 3 * num + 1;
  }
  printf("1\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout<<("Usage: %s <number>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);

  if (num <= 0) {
    cout<<("Error: Entrada no valida\n");
    return 1;
  }

  pid_t pid = fork();

  if (pid == -1) {
    cout<<("Fork failed\n");
    return 1;
  }

  if (pid == 0) { 
    collatz(num);
    exit(0);
  } else {
    wait(NULL);
   	cout<<("Proceso hijo terminado\n");
  }

  return 0;
}
