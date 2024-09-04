#include<stdio.h>

// Function to calculate the length of a string
int stringLength(char *str)
 {
    int length = 0;
    while (*str != '\0')
        {
        length++;
        str++;
    }
    return length;
}

// Function to concatenate two strings
void stringConcat(char *str1, char *str2, int maxLen) {
    int i, j;
    i = stringLength(str1);
    j = 0;

    // Check if there's enough space to concatenate str2 to str1
    while (str2[j] != '\0' && i < maxLen - 1) {  // -1 to leave space for null terminator
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

// Function to compare two strings
int stringCompare(char *str1, char *str2)
 {
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    } else if (str1[i] == '\0')
    {
        return -1;
    } else {
        return 1;
    }
}

// Function to insert a substring into a string
void stringInsert(char *str, char *subStr, int position)
{
    int i, j, k;
    int lenStr = stringLength(str);
    int lenSubStr = stringLength(subStr);
    char temp[100];
    for (i = 0; i < position; i++)
        {
        temp[i] = str[i];
        }
    for (j = 0; j < lenSubStr; j++, i++)
    {
        temp[i] = subStr[j];
    }
    for (k = position; k < lenStr; k++, i++)
    {
        temp[i] = str[k];
    }
    temp[i] = '\0';
    for (i = 0; temp[i] != '\0'; i++)
    {
        str[i] = temp[i];
    }
    str[i] = '\0';
}

void stringDelete(char *str, int position, int length)
 {
    int i, j;
    int lenStr = stringLength(str);
    char temp[100];
    for (i = 0; i < position; i++)
        {
        temp[i] = str[i];
    }
    for (j = position + length; j < lenStr; j++, i++)
     {
        temp[i] = str[j];
    }
    temp[i] = '\0';
    for (i = 0; temp[i] != '\0'; i++)
    {
        str[i] = temp[i];
    }
    str[i] = '\0';
}

int main() {
    char str1[100], str2[100], subStr[100];
    int position, length;

    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Length of the string: %d\n", stringLength(str1));

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    stringConcat(str1, str2, sizeof(str1));
    printf("Concatenated string: %s\n", str1);

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    if (stringCompare(str1, str2) == 0)
        {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are not equal\n");
    }

    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter substring to insert: ");
    scanf("%s", subStr);
    printf("Enter position to insert: ");
    scanf("%d", &position);
    stringInsert(str1, subStr, position);
    printf("String after insertion: %s\n", str1);

    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter position to delete: ");
    scanf("%d", &position);
    printf("Enter length to delete: ");
    scanf("%d", &length);
    stringDelete(str1, position, length);
    printf("String after deletion: %s\n", str1);

    return 0;
}


