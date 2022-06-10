SRC	=	main.cpp
$(eval SRC = $(addprefix src/, $(SRC)))

CLASS	=	cookie_clicker.cpp
$(eval CLASS = $(addprefix class/, $(CLASS)))

OBJ	=	$(SRC:.cpp=.o)		\
		$(CLASS:.cpp=.o)

%.o: %.cpp
	g++ -c -o $@ $< $(LDFLAGS) $(CPPFLAGS)

NAME	=	cookie_clicker

CPPFLAGS	=	-I./class

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -fno-stack-protector

$(NAME): $(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: CPPFLAGS+=-g3
debug: fclean all

.PHONY:	all clean fclean re debug