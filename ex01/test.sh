#!/bin/bash

GREEN="\033[32m"
BLUE="\033[34m"
RESET="\033[0m"
RED="\033[31m"


printf "$BLUE%s""Test[0] => 3 2 1 + *\n"
out=$(./RPN "3 2 1 + *")
if [ "$out" = "9" ]; then
      printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
  printf "$RED%s""      Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [9]\n\n"$RESET
}
fi


printf "$BLUE%s""Test[1] => 2 4 8 + * \n"
out=$(./RPN "2 4 8 + *")
if [ "$out" = "24" ]; then
        printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [24]\n\n"$RESET
}
fi


printf "$BLUE%s""Test[2] => 2 5 * 4 + 3 2 * 1 + / \n"
out=$(./RPN "2 5 * 4 + 3 2 * 1 + / ")
if [ "$out" = "2" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [2]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[3] => 8 9 * 9 - 9 - 9 - 4 - 1 + \n"
out=$(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +")
if [ "$out" = "42" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [42]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[4] => 7 7 * 7 - \n"
out=$(./RPN "7 7 * 7 -")
if [ "$out" = "42" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [42]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[5] => 1 2 * 2 / 2 * 2 4 - + \n"
out=$(./RPN "1 2 * 2 / 2 * 2 4 - +")
if [ "$out" = "0" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [0]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[6]: Invalid input => (1 + 1) \n"
out=$(./RPN "(1 + 1)")
if [ "$out" = "Error: invalid input" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [Error: invalid input]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[7] => 1 2 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 - \n"
out=$(./RPN "12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -")
if [ "$out" = "42" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [42]\n\n"$RESET
}
fi

printf "$BLUE%s""Test[8] => 9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -\n"
out=$(./RPN "98 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -")
if [ "$out" = "42" ]; then
    printf "$GREEN%s""      Good: "$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n\n"$RESET
else
{
    printf "$RED%s""        Wrong\n"$RESET
    printf	"$BLUE%s""Your Output =   [$out]\n"$RESET
    printf	"$GREEN%s""Correct Value = [42]\n\n"$RESET
}
fi
