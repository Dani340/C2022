#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* passwordCracker(int n, int i, char pass[n][100], char login[]) {
    if (i == n) {
        return login;
    }
    else {
        /*
            folosesc regex ca sa gasesc daca cuvintele din login se
            regasesc si in pass si le scot pana raman cu un login
            gol pe care apoi il transform in rezultat, adica cuvintele
            gasite cu spatii intre ele
        */
        return passwordCracker(n, i+1, pass, login);
    }
}

int main() {
    char st[100], str[100][100], login[200], *res;
    char s[2] = " ";
    int i, t, n;

    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%d", &n);

        scanf("%s", st);
        strcpy(str[0], strtok(st, s));

        for(i = 1; i < n; i++) {
            strcpy(str[i], strtok(st, NULL));
        }

        scanf("%s", login);
        res = passwordCracker(n, 0, str, login);
        printf("%s\n", res);
    }

    return 0;
}
