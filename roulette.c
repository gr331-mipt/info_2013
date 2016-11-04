#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *spisok[] = {"example", "Atayan", "Boromir", "Volobuev",
                  "Goncharova", "Gunko", "Kalmykov", "Kotova",
                  "Liviniuk", "Lyalin", "Makarov", "Mihailov",
                  "Muzenitov", "Panov", "Romanov", "Selezneva",
                  "Semenov", "Shapkin"};

int tasks[18][3];

int check_dup(int idx)
{
  int i;
  for (i = 0; i < idx; i++)
//    if (tasks[i] == tasks[idx]) // wrong !!!
    if (tasks[i][0] == tasks[idx][0] && tasks[i][1] == tasks[idx][1] ||
        tasks[i][1] == tasks[idx][1] && tasks[i][2] == tasks[idx][2] ||
        tasks[i][2] == tasks[idx][2] && tasks[i][0] == tasks[idx][0])
      return i + 1;
  return 0;
}

//is this task assigned to anybody?
int check_mis(int task, int val)
{
  int i;
  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    if (tasks[i][task] == val)
      return i + 1;
  return 0;
}

int main(void)
{
  int i, flag;
  srand((unsigned)time(NULL));
/*  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    printf("%i) %s: %i-%i-%i\n", i, spisok[i], rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1);*/
  do
  {
    flag = 0;
    for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    {
      tasks[i][0] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      tasks[i][1] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      tasks[i][2] = 1 + (unsigned) (6 * (rand() / (RAND_MAX + 1.0)));
      if (check_dup(i))
        i--;
    }

    //fix the situation, when there is variants assigned to nobody
    for (i = 1; i <= 6; i++)
      if (!check_mis(0, i) || !check_mis(1, i) || !check_mis(2, i))
        flag = 1;
  } while (flag);

  for (i = 0; i < sizeof spisok / sizeof spisok[0]; i++)
    printf("%2i) %-13s: %i-%i-%i\n", i, spisok[i], tasks[i][0], tasks[i][1], tasks[i][2]);
  return 0;
}
