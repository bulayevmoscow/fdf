all:
	gcc  -lmlx -framework OpenGL -framework AppKit main.c minilibx/libmlx_intel-mac.a libft/libft_pro.a -o kekw
re:
	rm -rf ./kekw
	make all
