all: checker push_swap

checker:
	@make -C checker_src/.
	@cp checker_src/checker .

push_swap:
	@make -C push_swap_src/.
	@cp push_swap_src/push_swap .

clean:
	@make -C checker_src/. clean
	@make -C push_swap_src/. clean

fclean:
	@rm -rf checker
	@rm -rf push_swap
	@make -C checker_src/. fclean
	@make -C push_swap_src/. fclean

re: fclean all
