.PHONY: test
test: comp
	./prog
	leaks --atExit -- ./prog
	@$(MAKE) clean

comp:
	gcc -Wall -Wextra -Werror -g -o prog sv_test.c

clean:
	rm -rf ./prog*

