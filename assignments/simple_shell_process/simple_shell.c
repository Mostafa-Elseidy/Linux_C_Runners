#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int status;

    char var_arr[10];
    char val_arr[10];
    int count_loc_vars = 0;

    typedef struct local_var
    {
        char var[5];
        char val[5];
    } local_var[5];
    local_var loc_var;

    while (1)
    {
        char buf[100];

        printf("please enter a command > ");
        fgets(buf, 100, stdin);
        // scanf("%s", buf);
        int len = strlen(buf);
        buf[len - 1] = 0;
        // printf("buf= %s\n", buf);

        // local variables ------------------------------------
        int has_equal_sign = 0;
        if (strchr(buf, '=') != NULL)
        {
            has_equal_sign = 1;
            // printf("Has equal sign\n");

            // tokinze varaible and value
            char *array[20];
            int i = 0;

            array[i] = strtok(buf, " =");

            while (array[i] != NULL)
                array[++i] = strtok(NULL, " =");

            // add varaible and value to array
            strcpy(loc_var[count_loc_vars].var, array[0]);
            strcpy(loc_var[count_loc_vars].val, array[1]);
            // printf("Local varaibles updated\n");
            count_loc_vars++;
            continue;
        }
        // local variables ------------------------------------

        // show all local variables with set command --------------
        else if (strcmp(buf, "set") == 0)
        {

            for (int i = 0; i < count_loc_vars; i++)
                printf("local var[%d]: %s = %s\n", i, loc_var[i].var, loc_var[i].val);
            continue;
        }
        // show all local variables with set command --------------

        // search for a local variable-----------------------------
        // tokinze varaible and value
        char *arrayc[20];
        int k = 0;

        arrayc[k] = strtok(buf, " ");

        while (arrayc[k] != NULL)
            arrayc[++k] = strtok(NULL, " ");

        if (strcmp(arrayc[0], "export") == 0)
        {
            char *search_var = arrayc[1];
            int found_loc_var = 0;
            for (int j = 0; j < count_loc_vars; j++)
            {

                if (strcmp(loc_var[j].var, search_var) == 0)
                {
                    // printf("found  %s = %s \n", loc_var[j].var, loc_var[j].val);
                    found_loc_var = 1;
                    const char *name = loc_var[j].var;
                    const char *value = loc_var[j].val;
                    int overwrite = 1;

                    // convert to environment variable
                    setenv(name, value, overwrite);
                    continue;
                }
            }
            if (found_loc_var == 0)
                printf("variable %s does not exist\n", search_var);
            continue;
        }
        // search for a local variable-----------------------------

        // parent process------------------------------------------
        int ret_pid = fork();

        if (ret_pid < 0)
            printf("Fork failed\n");
        else if (ret_pid > 0)
        {
            // printf("> 0 parent process\n");
            wait(&status);
            // printf("My child has been terminated\n");
        }
        // parent process------------------------------------------

        else
        // if (ret_pid == 0)
        {
            // child process-------------------------------------------
            // tokenizer --------------------------------------
            char *buf_arr[20];
            int i = 0;

            buf_arr[i] = strtok(buf, " ");

            while (buf_arr[i] != NULL)
                buf_arr[++i] = strtok(NULL, " ");
            // tokenizer --------------------------------------

            // execvp(argv[0], argv);
            execvp(buf_arr[0], buf_arr);
            printf("Exec failed\n");
            // child process-------------------------------------------
        }
    }
    return 0;
}
