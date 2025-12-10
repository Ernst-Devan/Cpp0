

NAME := Dreams_jobs

SRCS := Account.cpp \
        tests.cpp

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

CFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -MP
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

-include $(DEPS)

