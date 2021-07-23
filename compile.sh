#!/bin/bash
gcc ./srcs/main.c -I ./minilibx-linux/ -L ./minilibx-linux -lmlx -lXext -lX11
