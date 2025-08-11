clean:
	clear
	$(MAKE) clean -C ex00
	$(MAKE) clean -C ex01
	$(MAKE) clean -C ex02
	$(MAKE) clean -C ex03
	$(MAKE) clean -C ex04
	$(MAKE) clean -C ex05
	$(MAKE) clean -C ex06

fclean:
	clear
	$(MAKE) -C ex00 fclean
	$(MAKE) -C ex01 fclean
	$(MAKE) -C ex02 fclean
	$(MAKE) -C ex03 fclean
	$(MAKE) -C ex04 fclean
	$(MAKE) -C ex05 fclean
	$(MAKE) -C ex06 fclean

re:
	clear
	$(MAKE) -C ex00 re
	$(MAKE) -C ex01 re
	$(MAKE) -C ex02 re
	$(MAKE) -C ex03 re
	$(MAKE) -C ex04 re
	$(MAKE) -C ex05 re
	$(MAKE) -C ex06 re

run:
	clear
	echo "\n\n\n\n"
	$(MAKE) -C ex00 run
	echo "\n\n\n\n"
	$(MAKE) -C ex01 run
	echo "\n\n\n\n"
	$(MAKE) -C ex02 run
	echo "\n\n\n\n"
	$(MAKE) -C ex03 run
	echo "\n\n\n\n"
	$(MAKE) -C ex04 run
	echo "\n\n\n\n"
	$(MAKE) -C ex05 run
	echo "\n\n\n\n"
	$(MAKE) -C ex06 run
	echo "\n\n\n\n"

all:
	clear
	$(MAKE) -C ex00 all
	$(MAKE) -C ex01 all
	$(MAKE) -C ex02 all
	$(MAKE) -C ex03 all
	$(MAKE) -C ex04 all
	$(MAKE) -C ex05 all
	$(MAKE) -C ex06 all




# $(MAKE) = make
# $(CLEAN) = clean
# $(FCLEAN) = fclean
# $(RE) = re
# $(RUN) = run


# $(CLEAN):
# 	$(MAKE) $(CLEAN) -C ex00
# 	$(MAKE) $(CLEAN) -C ex01
# 	$(MAKE) $(CLEAN) -C ex02
# 	$(MAKE) $(CLEAN) -C ex03
# 	$(MAKE) $(CLEAN) -C ex04
# 	$(MAKE) $(CLEAN) -C ex05
# 	$(MAKE) $(CLEAN) -C ex06

# $(FCLEAN):
# 	$(MAKE) -C ex00 $(FCLEAN)
# 	$(MAKE) -C ex01 $(FCLEAN)
# 	$(MAKE) -C ex02 $(FCLEAN)
# 	$(MAKE) -C ex03 $(FCLEAN)
# 	$(MAKE) -C ex04 $(FCLEAN)
# 	$(MAKE) -C ex05 $(FCLEAN)
# 	$(MAKE) -C ex06 $(FCLEAN)

# $(RE):
# 	$(MAKE) -C ex00 $(RE)
# 	$(MAKE) -C ex01 $(RE)
# 	$(MAKE) -C ex02 $(RE)
# 	$(MAKE) -C ex03 $(RE)
# 	$(MAKE) -C ex04 $(RE)
# 	$(MAKE) -C ex05 $(RE)
# 	$(MAKE) -C ex06 $(RE)

# $(RUN):
# 	$(MAKE) -C ex00 $(RUN)
# 	$(MAKE) -C ex01 $(RUN)
# 	$(MAKE) -C ex02 $(RUN)
# 	$(MAKE) -C ex03 $(RUN)
# 	$(MAKE) -C ex04 $(RUN)
# 	$(MAKE) -C ex05 $(RUN)
# 	$(MAKE) -C ex06 $(RUN)

# all:
# 	$(MAKE) -C ex00 $(MAKE)
# 	$(MAKE) -C ex01 $(MAKE)
# 	$(MAKE) -C ex02 $(MAKE)
# 	$(MAKE) -C ex03 $(MAKE)
# 	$(MAKE) -C ex04 $(MAKE)
# 	$(MAKE) -C ex05 $(MAKE)
# 	$(MAKE) -C ex06 $(MAKE)
