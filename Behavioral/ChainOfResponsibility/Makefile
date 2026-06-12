NAME = chainofresponsability

CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I. -pthread
LGTEST = -lgtest

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LGTEST)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
