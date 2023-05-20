void continue_function()
{
    char yesorno[2];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          DO YOU WANT TOO CONTINUE [TYPE 'Y' OR 'N'] : ");
    scanf("%s", yesorno);
    printf("\t\t\t  ---------------------------------------------------------\n");

    int value_y, value_Y;
    int value_n, value_N;
    value_y = strcmp(yesorno, "y");
    value_Y = strcmp(yesorno, "Y");
    value_N = strcmp(yesorno, "N");
    value_n = strcmp(yesorno, "n");
    if (value_y == 0 || value_Y == 0)
    {
        Features_Services();
    }
    else if (value_N == 0 || value_n == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                                SYSTEM EXIT                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                           ");
        printf("\n\t\t\t                      REDIRECT MAIN MENU                       ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        Features_Services();
    }
}