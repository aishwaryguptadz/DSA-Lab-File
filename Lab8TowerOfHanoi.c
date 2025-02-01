#include <stdio.h>
#include <conio.h>
void towers_of_hanoi(int n, char *a, char *b, char *c)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %s to %s", a, c);
        return;
    }
    towers_of_hanoi(n - 1, a, c, b);
    printf("\nMove disk %d from %s to %s", n, a, c);
    towers_of_hanoi(n - 1, b, a, c);
}
int main()
{
    int n;
    printf("Enter number of discs: ");
    scanf("%d", &n);
    towers_of_hanoi(n, "Tower 1", "Tower 2", "Tower 3");
    getch();
}