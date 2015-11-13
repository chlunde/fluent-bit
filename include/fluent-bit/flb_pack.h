/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_PACK_H
#define FLB_PACK_H

#include <jsmn/jsmn.h>

struct flb_pack_state {
    int tokens_count;     /* number of parsed tokens */
    int tokens_size;      /* array size of tokens    */
    jsmntok_t *tokens;    /* tokens array            */
    jsmn_parser parser;   /* parser state            */
};

int flb_pack_json(char *js, size_t len, char **buffer, int *size);
int flb_pack_state_init(struct flb_pack_state *s);
int flb_pack_json_state(char *js, size_t len,
                        char **buffer, int *size,
                        struct flb_pack_state *state);

void flb_pack_print(char *data, size_t bytes);

#endif
