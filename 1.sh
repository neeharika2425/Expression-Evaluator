#!/bin/bash

`flex final.lex`
`gcc in-pre.c -o in-pre `
`gcc lex.yy.c -o calculator01`
`./in-pre`


