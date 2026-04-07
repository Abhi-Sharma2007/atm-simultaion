
#include <stdio.h>
#include "auth.h"
#include "file_ops.h"
#include "account.h"

int authenticateUser(int accNo, int pin) {
    Account acc;
    int found = readAccount(accNo, &acc);

    if (found == 1 && acc.pin == pin)
        return 1;   // success
    else
        return 0;   // fail
}
