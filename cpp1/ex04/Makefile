NAME		= zombie

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I $(INCDIR)

SRCDIR		= src
INCDIR		= inc
OBJDIR		= obj

SRC			= main
SRCS		= $(addprefix $(SRCDIR)/, $(addsuffix .cpp, $(SRC)))
OBJS		= $(addprefix $(OBJDIR)/, $(SRC:=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation de $(NAME) terminée."

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "Compiling $< -> $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Nettoyage des fichiers objets."

fclean: clean
	@rm -f $(NAME)
	@echo "Nettoyage complet."

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
