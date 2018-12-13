/*
 *  Copyright (C) 2015, OpenSGX team, Georgia Tech & KAIST, All Rights Reserved
 *
 *  This file is part of OpenSGX (https://github.com/sslab-gatech/opensgx).
 *
 *  OpenSGX is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  OpenSGX is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with OpenSGX.  If not, see <http://www.gnu.org/licenses/>.
 */

// hello world

#include <sgx-lib.h>
#include <stdio.h>
#include <stdlib.h>

void enclave_main()
{
    char *hello = "hello sgx!\n";
    puts(hello);

    sgx_sec_aex_stats_t *p = malloc(sizeof(sgx_sec_aex_stats_t));
    printf("Struct to place aex stats into: %lx\n", p);

    char s[81];
    s[80] = '\0';
    fgets(s, 80, stdin);
    puts(s);

    sgx_sec_aex_stats(p);
    printf("Number of exceptions from enclave: %lu\n", p->count);

    s[80] = '\0';
    fgets(s, 80, stdin);
    puts(s);
    sgx_sec_aex_stats(p);
    printf("Number of exceptions from enclave: %lu\n", p->count);

    sgx_exit(NULL);
}

