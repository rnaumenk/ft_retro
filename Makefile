NAME = ft_retro

SRC = Bot1.cpp Bot2.cpp Bot3.cpp Bullet.cpp Enemy.cpp main.cpp \
        Map.cpp Player.cpp Star.cpp

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@clang++ -lncurses -std=c++98 $(FLG) -o $(NAME) $(OBJ)
	@echo "\033[0;32mEnjoy!\033[0m"

%.o: %.cpp
	@clang++ -c $(FLG) -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[0;31mdelete: objects"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "delete:" $(NAME)

re: fclean all
